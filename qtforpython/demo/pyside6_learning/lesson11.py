import sys

from PySide6.QtWidgets import (
    QApplication,
    QWidget,
    QLabel,
    QLineEdit,
    QPushButton,
    QVBoxLayout,
    QHBoxLayout,
    QGridLayout,
)


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        # 创建姓名输入框
        self.name_input = QLineEdit()
        self.name_input.setPlaceholderText("请输入姓名")

        # 创建年龄输入框
        self.age_input = QLineEdit()
        self.age_input.setPlaceholderText("请输入年龄")

        # 创建邮箱输入框
        self.email_input = QLineEdit()
        self.email_input.setPlaceholderText("请输入邮箱")

        # 创建提交按钮
        self.submit_button = QPushButton("提交")

        # 创建清空按钮
        self.clear_button = QPushButton("清空")

        # 创建退出按钮
        self.exit_button = QPushButton("退出")

        # 创建结果标签
        self.result_label = QLabel("请输入信息")

        # 把按钮放到水平布局中
        button_layout = QHBoxLayout()
        button_layout.addWidget(self.submit_button)
        button_layout.addWidget(self.clear_button)
        button_layout.addWidget(self.exit_button)

        # 创建表格布局
        form_layout = QGridLayout()

        # 第 0 行
        form_layout.addWidget(QLabel("姓名："), 0, 0)
        form_layout.addWidget(self.name_input, 0, 1)

        # 第 1 行
        form_layout.addWidget(QLabel("年龄："), 1, 0)
        form_layout.addWidget(self.age_input, 1, 1)

        # 第 2 行
        form_layout.addWidget(QLabel("邮箱："), 2, 0)
        form_layout.addWidget(self.email_input, 2, 1)

        # 创建主垂直布局
        main_layout = QVBoxLayout()

        # 添加表单布局
        main_layout.addLayout(form_layout)

        # 添加按钮水平布局
        main_layout.addLayout(button_layout)

        # 添加结果标签
        main_layout.addWidget(self.result_label)

        # 设置布局边距和控件间距
        main_layout.setContentsMargins(20, 20, 20, 20)
        main_layout.setSpacing(12)

        # 设置窗口布局
        self.setLayout(main_layout)

        # 连接按钮
        self.submit_button.clicked.connect(self.handle_submit)
        self.clear_button.clicked.connect(self.clear_form)
        self.exit_button.clicked.connect(self.close)

        self.setWindowTitle("第 11 课：布局")
        self.resize(450, 220)

    def handle_submit(self):
        name = self.name_input.text().strip()
        age = self.age_input.text().strip()
        email = self.email_input.text().strip()

        if not name:
            self.result_label.setText("请输入姓名")
        elif not age:
            self.result_label.setText("请输入年龄")
        elif not email:
            self.result_label.setText("请输入邮箱")
        else:
            self.result_label.setText(f"姓名：{name}，年龄：{age}，邮箱：{email}")

    def clear_form(self):
        # 清空输入框
        self.name_input.clear()
        self.age_input.clear()
        self.email_input.clear()

        # 恢复提示文字
        self.result_label.setText("请输入信息")


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())
