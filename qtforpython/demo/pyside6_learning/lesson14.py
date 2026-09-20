import sys

from PySide6.QtCore import QAbstractTableModel, QModelIndex, Qt
from PySide6.QtWidgets import QApplication, QTableView


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


students = [
    ["小明", "18", "北京", "计算机科学", "xiaoming@example.com"],
    ["小红", 20, "上海", "软件工程", "xiaohong@example.com"],
    ["小刚", 19, "广州", "人工智能", "xiaogang@example.com"],
    ["小丽", 20, "深圳", "数据科学", "xiaoli@example.com"]
]

app = QApplication(sys.argv)

table = QTableView()
model = StudentModel(students)

# 让表格使用这个数据模型
table.setModel(model)

def show_double_clicked(index):
    row = index.row()
    column = index.column()
    value = students[row][column]
    print(row, " ", column, " ", value)


table.doubleClicked.connect(show_double_clicked)

table.setWindowTitle("第 14 课：Model/View")
table.resize(600, 300)
table.show()

sys.exit(app.exec())