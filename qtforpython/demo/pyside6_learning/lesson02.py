import sys
from PySide6.QtWidgets import (
    QApplication,
    QWidget,
    QLabel,
    QPushButton,
    QVBoxLayout,
)


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        # 创建标签
        self.label = QLabel("按钮还没有被点击")

        # 创建按钮
        self.button = QPushButton("改变文字")

        # 把按钮的 clicked 信号连接到 handle_click 方法
        self.button.clicked.connect(self.handle_click)

        # 创建按钮
        self.button2 = QPushButton("第二个按钮")
                    
        # 把按钮的 clicked 信号连接到 handle_second_click 方法
        self.button2.clicked.connect(self.handle_second_click)            

        # 创建垂直布局
        layout = QVBoxLayout()

        # 按照添加顺序，从上到下排列控件
        layout.addWidget(self.label)
        layout.addWidget(self.button)
        layout.addWidget(self.button2)

        # 把布局设置给当前窗口
        self.setLayout(layout)

        # 设置窗口标题和初始大小
        self.setWindowTitle("第 2 课：按钮和布局")
        self.resize(400, 200)

    def handle_click(self):
        # 按钮被点击时，修改标签文字
        self.label.setText("按钮已经被点击")

    def handle_second_click(self):
        self.label.setText("这是第二个按钮")

app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())