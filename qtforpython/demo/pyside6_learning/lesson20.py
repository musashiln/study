import sys

from PySide6.QtCore import Qt
from PySide6.QtGui import QFont, QPainter, QPen
from PySide6.QtWidgets import (
    QApplication,
    QCheckBox,
    QLabel,
    QLineEdit,
    QPushButton,
    QVBoxLayout,
    QWidget,
)


class CircleProgress(QWidget):
    """一个简单的圆形进度控件。"""

    def __init__(self):
        super().__init__()
        self.value = 0
        self.setMinimumSize(150, 150)

    def set_value(self, value):
        self.value = max(0, min(100, value))
        # 调用 update() 方法触发重绘
        self.update()

    def paintEvent(self, event):
        del event

        painter = QPainter(self)
        painter.setRenderHint(QPainter.RenderHint.Antialiasing)

        size = min(self.width(), self.height()) - 20
        x = (self.width() - size) // 2
        y = (self.height() - size) // 2

        # 绘制背景圆环
        background_pen = QPen(Qt.GlobalColor.lightGray, 12)
        painter.setPen(background_pen)
        painter.drawEllipse(x, y, size, size)

        # 绘制进度圆弧
        # 将进度圆弧改成绿色
        progress_pen = QPen(Qt.GlobalColor.green, 12)
        painter.setPen(progress_pen)
        span_angle = int(-self.value * 360 / 100 * 16)
        painter.drawArc(x, y, size, size, 90 * 16, span_angle)

        # 绘制中心文字
        painter.setPen(self.palette().text().color())
        painter.setFont(QFont("Arial", 20))
        painter.drawText(
            self.rect(),
            Qt.AlignmentFlag.AlignCenter,
            f"{self.value}%",
        )


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        self.title_label = QLabel("样式表和自定义控件")
        self.name_input = QLineEdit()
        self.name_input.setPlaceholderText("请输入你的名字")

        self.submit_button = QPushButton("显示问候")
        self.increase_button = QPushButton("进度 +10")
        self.theme_checkbox = QCheckBox("使用深色主题")
        self.result_label = QLabel("请输入名字后点击按钮")
        self.result_label.setObjectName("resultLabel")

        self.progress = CircleProgress()
        self.progress.set_value(75)

        layout = QVBoxLayout()
        layout.addWidget(self.title_label)
        layout.addWidget(self.name_input)
        layout.addWidget(self.submit_button)
        layout.addWidget(self.increase_button)
        layout.addWidget(self.theme_checkbox)
        layout.addWidget(self.progress, alignment=Qt.AlignmentFlag.AlignCenter)
        layout.addWidget(self.result_label)
        self.setLayout(layout)

        self.submit_button.clicked.connect(self.show_greeting)
        self.increase_button.clicked.connect(self.increase_progress)
        self.theme_checkbox.toggled.connect(self.toggle_theme)

        self.setWindowTitle("第 20 课：样式和自定义控件")
        self.resize(420, 500)

        self.apply_light_theme()

    def show_greeting(self):
        name = self.name_input.text().strip()

        if name:
            self.result_label.setText(f"你好，{name}！")
        else:
            self.result_label.setText("请输入名字")

    def increase_progress(self):
        # 当前进度加 10；达到或超过 100 时回到 0
        new_value = self.progress.value + 10

        if new_value >= 100:
            new_value = 0

        self.progress.set_value(new_value)

    def toggle_theme(self, enabled):
        if enabled:
            self.apply_dark_theme()
        else:
            self.apply_light_theme()

    def apply_light_theme(self):
        self.setStyleSheet(
            """
            QWidget {
                background-color: #f4f6f8;
                color: #202124;
                font-size: 15px;
            }
            QLineEdit {
                background-color: white;
                border: 1px solid #b8c0cc;
                border-radius: 5px;
                padding: 8px;
            }
            QPushButton {
                background-color: #16a34a;
                color: white;
                border: none;
                border-radius: 5px;
                padding: 9px;
            }
            QPushButton:hover {
                background-color: #15803d;
            }
            QLabel#resultLabel {
                font-size: 18px;
                color: #166534;
            }
            """
        )

    def apply_dark_theme(self):
        self.setStyleSheet(
            """
            QWidget {
                background-color: #202124;
                color: #f1f3f4;
                font-size: 15px;
            }
            QLineEdit {
                background-color: #3a4048;
                color: #f1f3f4;
                border: 1px solid #5f6368;
                border-radius: 5px;
                padding: 8px;
            }
            QPushButton {
                background-color: #8ab4f8;
                color: #202124;
                border: none;
                border-radius: 5px;
                padding: 9px;
            }
            QPushButton:hover {
                background-color: #aecbfa;
            }
            QLabel#resultLabel {
                font-size: 18px;
                color: #86efac;
            }
            """
        )


app = QApplication(sys.argv)
window = MainWindow()
window.show()
sys.exit(app.exec())
