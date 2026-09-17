import sys

from PySide6.QtWidgets import (
    QApplication,
    QWidget,
    QLabel,
    QPushButton,
    QFileDialog,
    QMessageBox,
    QVBoxLayout,
)


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        # 创建“选择文件”按钮
        self.file_button = QPushButton("选择文件")

        # 创建“选择文件夹”按钮
        self.folder_button = QPushButton("选择文件夹")

        # 创建“显示提示”按钮
        self.message_button = QPushButton("显示提示")

        # 创建“警告提示”按钮
        self.warning_button = QPushButton("警告提示")

        # 创建“询问”按钮
        self.answer_button = QPushButton("询问")

        # 显示操作结果
        self.result_label = QLabel("请选择一个操作")

        # 连接按钮的点击信号
        self.file_button.clicked.connect(self.choose_file)
        self.folder_button.clicked.connect(self.choose_folder)
        self.message_button.clicked.connect(self.show_message)
        self.warning_button.clicked.connect(self.warning_message)
        self.answer_button.clicked.connect(self.answer)

        # 创建垂直布局
        layout = QVBoxLayout()
        layout.addWidget(self.file_button)
        layout.addWidget(self.folder_button)
        layout.addWidget(self.message_button)
        layout.addWidget(self.warning_button)
        layout.addWidget(self.answer_button)
        layout.addWidget(self.result_label)

        self.setLayout(layout)

        self.setWindowTitle("第 6 课：对话框")
        self.resize(500, 200)

    def choose_file(self):
        # 打开文件选择框
        file_path, selected_filter = QFileDialog.getOpenFileName(
            self,
            "选择一个文件",
            "",
            "所有文件 (*.*);;文本文件 (*.txt);;Python 文件 (*.py)",
        )

        # 如果用户选择了文件，file_path 就不是空字符串
        if file_path:
            self.result_label.setText(f"选择的文件：{file_path}")
        else:
            self.result_label.setText("你取消了文件选择")

    def choose_folder(self):
        # 打开文件夹选择框
        folder_path = QFileDialog.getExistingDirectory(
            self,
            "选择文件夹",
        )

        # 如果用户选择了文件夹，就显示文件夹路径
        if folder_path:
            self.result_label.setText(f"选择的文件夹：{folder_path}")
        else:
            self.result_label.setText("你取消了文件夹选择")
        
    def show_message(self):
        # 显示一个信息提示框
        QMessageBox.information(
            self,
            "操作成功",
            "这是一条信息提示",
        )

    def warning_message(self):
        # 显示一个警告提示框
        QMessageBox.warning(
            self,
            "警告",
            "这是一条警告提示",
        )

    def answer(self):
        answer = QMessageBox.question(
            self,
            "确认操作",
            "确定要继续吗？",
        )

        if answer == QMessageBox.StandardButton.Yes:
            self.result_label.setText("你选择了继续")
        else:
            self.result_label.setText("你选择了取消")



app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())
