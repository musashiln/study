import sys

from PySide6.QtWidgets import (
    QApplication,
    QWidget,
    QLabel,
    QLineEdit,
    QPushButton,
    QVBoxLayout,
)


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        # 创建提示文字
        self.title_label = QLabel("请输入你的名字")

        # 创建单行输入框
        self.name_input = QLineEdit()

        # 设置输入框中的提示文字
        self.name_input.setPlaceholderText("例如：小明")

        self.age_input = QLineEdit()
        self.age_input.setPlaceholderText("请输入年龄")

        # 创建按钮
        self.button = QPushButton("确定")

        # 创建用于显示结果的标签
        self.result_label = QLabel("这里会显示结果")

        # 当按钮被点击时，执行 handle_click 方法
        self.button.clicked.connect(self.handle_click)

        # 创建垂直布局
        layout = QVBoxLayout()

        # 按照从上到下的顺序添加控件
        layout.addWidget(self.title_label)
        layout.addWidget(self.name_input)
        layout.addWidget(self.age_input)
        layout.addWidget(self.button)
        layout.addWidget(self.result_label)

        # 把布局设置给当前窗口
        self.setLayout(layout)

        # 设置窗口标题和大小
        self.setWindowTitle("我的信息")
        self.resize(400, 200)

    def handle_click(self):
        # 获取输入框中的文字
        name = self.name_input.text()
        age = self.age_input.text()

        # 去掉文字两端多余的空格
        name = name.strip()

        # 判断用户是否输入了内容
        if name:
            self.result_label.setText(f"你好，我叫{name}，今年 {age} 岁")
        else:
            self.result_label.setText("你还没有输入名字")


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())