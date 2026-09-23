import json
import sys
import urllib.request

from PySide6.QtWidgets import (
    QApplication,
    QLabel,
    QPushButton,
    QTableWidget,
    QTableWidgetItem,
    QVBoxLayout,
    QWidget,
)


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

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
        self.result_label.setText("正在获取数据...")

        try:
            with urllib.request.urlopen(url, timeout=10) as response:
                raw_data = response.read()

            users = json.loads(raw_data.decode("utf-8"))

            self.table.setRowCount(0)

            for user in users:
                row = self.table.rowCount()
                self.table.insertRow(row)

                self.table.setItem(
                    row,
                    0,
                    QTableWidgetItem(str(user["id"])),
                )
                self.table.setItem(
                    row,
                    1,
                    QTableWidgetItem(user["name"]),
                )
                self.table.setItem(
                    row,
                    2,
                    QTableWidgetItem(user["email"]),
                )

            self.result_label.setText(
                f"获取成功，共 {len(users)} 名用户"
            )

        except Exception as error:
            self.result_label.setText(f"获取失败：{error}")

        finally:
            self.load_button.setEnabled(True)


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())