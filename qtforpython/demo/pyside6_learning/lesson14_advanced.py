# Model/View 的核心思想：
# 窗口不直接修改表格显示，
# 窗口请求模型修改数据，
# 模型通知表格更新。


import sys

from PySide6.QtCore import QAbstractTableModel, QModelIndex, Qt
from PySide6.QtWidgets import (
    QApplication,
    QLabel,
    QMainWindow,
    QPushButton,
    QTableView,
    QVBoxLayout,
    QWidget,
)


class StudentModel(QAbstractTableModel):
    def __init__(self, students):
        super().__init__()
        self.students = students
        self.headers = ["姓名", "年龄", "城市", "专业", "邮箱"]

    def rowCount(self, parent=QModelIndex()):
        # 返回数据行数
        return len(self.students)

    def columnCount(self, parent=QModelIndex()):
        # 返回数据列数
        return len(self.headers)

    def data(self, index, role=Qt.ItemDataRole.DisplayRole):
        # 无效位置不返回数据
        if not index.isValid():
            return None

        # 表格请求显示数据时，返回对应内容
        if role == Qt.ItemDataRole.DisplayRole:
            row = index.row()
            column = index.column()
            return str(self.students[row][column])

        return None

    def headerData(self, section, orientation, role):
        # 只处理需要显示的表头文字
        if role != Qt.ItemDataRole.DisplayRole:
            return None

        if orientation == Qt.Orientation.Horizontal:
            return self.headers[section]

        # 垂直表头显示 1、2、3……
        return str(section + 1)

    def add_student(self, student):
        # 新数据将要插入的位置
        new_row = len(self.students)

        # 通知视图：准备插入一行
        self.beginInsertRows(QModelIndex(), new_row, new_row)

        # 修改真正的 Python 数据
        self.students.append(student)

        # 通知视图：插入完成
        self.endInsertRows()

    def remove_student(self, row):
        # 检查行号是否有效
        if row < 0 or row >= len(self.students):
            return False

        # 通知视图：准备删除一行
        self.beginRemoveRows(QModelIndex(), row, row)

        # 删除真正的数据
        self.students.pop(row)

        # 通知视图：删除完成
        self.endRemoveRows()

        return True


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        students = [
            ["小明", "18", "北京", "计算机科学", "xiaoming@example.com"],
            ["小红", 20, "上海", "软件工程", "xiaohong@example.com"],
            ["小刚", 19, "广州", "人工智能", "xiaogang@example.com"],
            ["小丽", 20, "深圳", "数据科学", "xiaoli@example.com"],
        ]

        # 创建模型和表格视图
        self.model = StudentModel(students)
        self.table = QTableView()
        self.table.setModel(self.model)

        # 创建界面控件
        self.add_button = QPushButton("添加学生")
        self.delete_button = QPushButton("删除选中行")
        self.result_label = QLabel("请选择一行")

        # 界面控件的信号连接到窗口方法
        self.add_button.clicked.connect(self.add_student)
        self.delete_button.clicked.connect(self.delete_selected)
        self.table.doubleClicked.connect(self.show_double_clicked)

        layout = QVBoxLayout()
        layout.addWidget(self.table)
        layout.addWidget(self.add_button)
        layout.addWidget(self.delete_button)
        layout.addWidget(self.result_label)

        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)

        self.setWindowTitle("第 14 课：Model/View")
        self.resize(700, 350)

    def add_student(self):
        # 窗口层决定添加什么数据，再调用模型的方法
        self.model.add_student(
            ["小华", 21, "杭州", "网络工程", "xiaohua@example.com"]
        )
        self.result_label.setText("已添加小华")

    def delete_selected(self):
        # 从视图获取当前索引，再把行号交给模型
        index = self.table.currentIndex()

        if not index.isValid():
            self.result_label.setText("请先选择一行")
            return

        if self.model.remove_student(index.row()):
            self.result_label.setText("删除成功")

    def show_double_clicked(self, index):
        value = self.model.students[index.row()][index.column()]
        self.result_label.setText(f"双击内容：{value}")


app = QApplication(sys.argv)
window = MainWindow()
window.show()
sys.exit(app.exec())
