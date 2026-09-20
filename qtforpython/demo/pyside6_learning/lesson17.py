# 把任务时间改成 5 秒。
# 增加一个“取消任务”按钮。
# 让进度条每次增加 2。
# 任务完成后显示“计算完成”。
# 在后台线程中计算 1 到 1000000 的总和。
# 不要在后台线程中直接操作标签或进度条。

import sys
import time

from PySide6.QtCore import QObject, QThread, Signal, Slot
from PySide6.QtWidgets import (
    QApplication,
    QLabel,
    QPushButton,
    QProgressBar,
    QVBoxLayout,
    QWidget,
)


class Worker(QObject):
    progress = Signal(int)
    finished = Signal()
    result = Signal(str)
    cancelled = Signal()

    def __init__(self):
        super().__init__()
        self.cancel_requested = False

    @Slot()
    def run(self):
        # 计算 1 到 1,000,000 的总和，并分成 100 个进度阶段
        total = 0
        limit = 1_000_000
        step = 20_000

        for start in range(1, limit + 1, step):
            if self.cancel_requested:
                self.cancelled.emit()
                self.finished.emit()
                return

            end = min(start + step - 1, limit)
            for value in range(start, end + 1):
                total += value

            # 每完成 2% 暂停一下，方便观察线程和进度条效果
            time.sleep(0.1)
            self.progress.emit(end * 100 // limit)

        self.result.emit(f"计算完成，1 到 {limit} 的总和是：{total}")
        self.finished.emit()

    def request_cancel(self):
        # 只修改取消标记，不操作任何界面控件
        self.cancel_requested = True


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        self.status_label = QLabel("任务尚未开始")
        self.progress_bar = QProgressBar()
        self.start_button = QPushButton("开始任务")
        self.cancel_button = QPushButton("取消任务")
        self.cancel_button.setEnabled(False)

        layout = QVBoxLayout()
        layout.addWidget(self.status_label)
        layout.addWidget(self.progress_bar)
        layout.addWidget(self.start_button)
        layout.addWidget(self.cancel_button)
        self.setLayout(layout)

        self.start_button.clicked.connect(self.start_task)
        self.cancel_button.clicked.connect(self.cancel_task)

        self.thread = None
        self.worker = None

        self.setWindowTitle("第 17 课：多线程")
        self.resize(400, 200)

    def start_task(self):
        # 防止重复启动任务
        self.start_button.setEnabled(False)
        self.cancel_button.setEnabled(True)
        self.status_label.setText("任务正在执行...")
        self.progress_bar.setValue(0)

        # 创建线程和工作对象
        self.thread = QThread()
        self.worker = Worker()

        # 把工作对象移动到后台线程
        self.worker.moveToThread(self.thread)

        # 线程启动后执行 worker.run()
        self.thread.started.connect(self.worker.run)

        # 更新进度条和结果文字
        self.worker.progress.connect(self.progress_bar.setValue)
        self.worker.result.connect(self.status_label.setText)

        # 任务完成后停止线程
        self.worker.finished.connect(self.thread.quit)
        self.worker.finished.connect(self.worker.deleteLater)
        self.thread.finished.connect(self.thread.deleteLater)

        # 线程完成后恢复按钮
        self.thread.finished.connect(self.task_finished)
        self.worker.cancelled.connect(
            lambda: self.status_label.setText("任务已取消")
        )

        # 启动线程
        self.thread.start()

    def cancel_task(self):
        if self.worker is not None:
            self.worker.request_cancel()
            self.cancel_button.setEnabled(False)
            self.status_label.setText("正在取消任务...")

    def task_finished(self):
        self.start_button.setEnabled(True)
        self.cancel_button.setEnabled(False)


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())
