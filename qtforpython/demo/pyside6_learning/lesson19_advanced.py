import json
import sys
import urllib.request

from PySide6.QtCore import QObject, QThread, Signal, Slot
from PySide6.QtWidgets import (
    QApplication,
    QLabel,
    QPushButton,
    QTableWidget,
    QTableWidgetItem,
    QVBoxLayout,
    QWidget,
)


class Worker(QObject):
    finished = Signal()
    result = Signal(str)
    users_ready = Signal(list)

    def __init__(self):
        super().__init__()
        self.cancel_requested = False

    @Slot()
    def run(self, url):
        self.result.emit("正在获取数据...")

        try:
            with urllib.request.urlopen(url, timeout=10) as response:
                raw_data = response.read()

            users = json.loads(raw_data.decode("utf-8"))

            if not isinstance(users, list):
                raise ValueError("服务器返回的数据不是用户列表")

            # 通过信号把数据安全地传回主线程
            self.users_ready.emit(users)
            self.result.emit(f"获取成功，共 {len(users)} 名用户")
        except Exception as error:
            self.result.emit(f"获取失败：{error}")
        finally:
            self.finished.emit()

class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        self.users = []

        self.title_label = QLabel("点击按钮获取网络数据")
        self.load_button = QPushButton("获取用户列表")
        self.result_label = QLabel("尚未获取数据")

        self.table = QTableWidget()
        self.table.setColumnCount(3)
        self.table.setHorizontalHeaderLabels(
            ["用户编号", "姓名", "邮箱"]
        )

        layout = QVBoxLayout()
        layout.addWidget(self.title_label)
        layout.addWidget(self.load_button)
        layout.addWidget(self.table)
        layout.addWidget(self.result_label)
        self.setLayout(layout)

        self.load_button.clicked.connect(self.load_users)

        self.setWindowTitle("第 19 课：网络和 JSON")
        self.resize(600, 400)

    def load_users(self):
        url = "https://jsonplaceholder.typicode.com/users"

        self.load_button.setEnabled(False)

        # 创建线程和工作对象
        self.thread = QThread()
        self.worker = Worker()
        
        # 把工作对象移动到后台线程
        self.worker.moveToThread(self.thread)
        
        # 线程启动后执行 worker.run()
        # 线程启动后执行网络请求。
        # connect() 只是建立连接，不能把 run() 的返回值保存到 self.users。
        self.thread.started.connect(lambda: self.worker.run(url))
        
        # 更新结果文字
        self.worker.result.connect(self.result_label.setText)
        self.worker.users_ready.connect(self.show_users)
        
        # 任务完成后停止线程
        self.worker.finished.connect(self.thread.quit)
        self.worker.finished.connect(self.worker.deleteLater)
        self.thread.finished.connect(self.thread.deleteLater)
        
        # 线程完成后恢复按钮
        self.thread.finished.connect(self.task_finished)
        
        # 启动线程
        self.thread.start()

    def show_users(self, users):
        """在主线程中把后台线程返回的数据显示到表格。"""
        self.users = users
        self.table.setRowCount(0)

        for user in users:
            row = self.table.rowCount()
            self.table.insertRow(row)

            self.table.setItem(
                row,
                0,
                QTableWidgetItem(str(user.get("id", ""))),
            )
            self.table.setItem(
                row,
                1,
                QTableWidgetItem(user.get("name", "未知姓名")),
            )
            self.table.setItem(
                row,
                2,
                QTableWidgetItem(user.get("email", "没有邮箱")),
            )

    def task_finished(self):
        self.load_button.setEnabled(True)


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())
