# pyside6-designer
# pyside6-uic lesson10.ui -o ui_lesson10.py

import sys

from PySide6.QtWidgets import QApplication, QWidget

from ui_lesson10 import Ui_Form


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        # 创建 Designer 生成的界面对象
        self.ui = Ui_Form()

        # 把界面设置到当前窗口
        self.ui.setupUi(self)

        # 连接按钮点击信号
        self.ui.submitButton.clicked.connect(self.handle_submit)

    def handle_submit(self):
        # 读取输入框内容
        name = self.ui.nameInput.text().strip()
        age = self.ui.ageInput.text().strip()

        # 判断用户是否输入内容
        if not name:
            self.ui.resultLabel.setText("请输入姓名")
        elif not age:
            self.ui.resultLabel.setText("请输入年龄")
        else:
            self.ui.resultLabel.setText(f"你好，{name}！年龄：{age}岁")


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())