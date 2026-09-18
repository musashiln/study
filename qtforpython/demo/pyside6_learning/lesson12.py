import sys

from PySide6.QtWidgets import (
    QApplication,
    QLineEdit,
    QWidget,
    QLabel,
    QListWidget,
    QPushButton,
    QVBoxLayout,
)


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        # 创建说明标签
        self.title_label = QLabel("请选择你喜欢的编程语言")

        # 创建列表控件
        self.language_list = QListWidget()

        # 向列表中添加项目
        self.language_list.addItem("Python")
        self.language_list.addItem("Java")
        self.language_list.addItem("C++")
        self.language_list.addItem("JavaScript")
        self.language_list.addItem("Rust")
        self.language_list.addItem("Go")

        # 创建按钮
        self.button = QPushButton("查看选择")
        self.delete_button = QPushButton("删除选择")

        # 创建输入框
        self.input_field = QLineEdit()
        self.add_button = QPushButton("添加语言")

        # 创建结果标签
        self.result_label = QLabel("还没有选择")

        # 点击按钮时执行方法
        self.button.clicked.connect(self.show_selected)
        self.delete_button.clicked.connect(self.delete_selected)
        self.add_button.clicked.connect(self.add_language)

        self.language_list.itemDoubleClicked.connect(self.show_double_clicked)

        # 创建垂直布局
        layout = QVBoxLayout()
        layout.addWidget(self.title_label)
        layout.addWidget(self.language_list)
        layout.addWidget(self.button)
        layout.addWidget(self.delete_button)
        layout.addWidget(self.input_field)
        layout.addWidget(self.add_button)
        layout.addWidget(self.result_label)

        self.setLayout(layout)

        self.setWindowTitle("第 12 课：列表控件")
        self.resize(400, 300)

    def show_selected(self):
        # 获取当前选中的项目
        item = self.language_list.currentItem()

        # 如果没有选择项目
        if item is None:
            self.result_label.setText("请选择一个项目")
            return

        # 获取项目中的文字
        language = item.text()

        # 显示选择结果
        self.result_label.setText(f"你选择了：{language}")

    def show_double_clicked(self, item):
        # item 是 itemDoubleClicked 信号传入的被双击项目
        # 获取项目中的文字
        language = item.text()

        # 显示选择结果
        self.result_label.setText(f"你选择了：{language}")

    def delete_selected(self):
        row = self.language_list.currentRow()

        if row < 0:
            self.result_label.setText("请先选择一个项目")
            return

        self.language_list.takeItem(row)
        self.result_label.setText("选中的项目已删除")

    def add_language(self):
        language = self.input_field.text().strip()

        if language:
            self.language_list.addItem(language)
            self.input_field.clear()
            self.result_label.setText(f"已添加语言：{language}")


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())
