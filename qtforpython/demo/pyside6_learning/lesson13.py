import sys

from PySide6.QtWidgets import (
    QApplication,
    QLineEdit,
    QWidget,
    QLabel,
    QTableWidget,
    QTableWidgetItem,
    QPushButton,
    QVBoxLayout,
)


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        # 创建说明标签
        self.title_label = QLabel("学生信息表")

        # 创建表格
        self.table = QTableWidget()

        # 设置表格行数和列数
        self.table.setRowCount(4)
        self.table.setColumnCount(4)

        # 设置表头
        self.table.setHorizontalHeaderLabels(
            ["姓名", "年龄", "城市", "专业"]
        )

        # 填充表格数据
        data = [
            ["小明", "18", "北京", "计算机科学"],
            ["小红", "20", "上海", "软件工程"],
            ["小刚", "19", "广州", "人工智能"],
            ["小丽", "20", "深圳", "数据科学"]
        ]

        for row_index, row_data in enumerate(data):
            for column_index, value in enumerate(row_data):
                item = QTableWidgetItem(value)
                self.table.setItem(row_index, column_index, item)

        #创建输入框
        self.name_input = QLineEdit()
        self.name_input.setPlaceholderText("请输入姓名")

        self.age_input = QLineEdit()
        self.age_input.setPlaceholderText("请输入年龄")

        self.city_input = QLineEdit()
        self.city_input.setPlaceholderText("请输入城市")

        self.major_input = QLineEdit()
        self.major_input.setPlaceholderText("请输入专业")

        # 创建按钮
        self.add_button = QPushButton("添加学生")
        self.show_button = QPushButton("显示选中行")
        self.delete_button = QPushButton("删除选中行")
        self.edit_button = QPushButton("修改选中行")

        # 创建结果标签
        self.result_label = QLabel("请选择一行")

        # 连接按钮
        self.show_button.clicked.connect(self.show_selected_row)
        self.delete_button.clicked.connect(self.delete_selected_row)
        self.add_button.clicked.connect(self.add_student)
        self.edit_button.clicked.connect(self.edit_selected_row)

        # 双击单元格时，信号会传入该单元格的行号和列号
        self.table.cellDoubleClicked.connect(self.show_double_clicked_cell)

        # 创建布局
        layout = QVBoxLayout()
        layout.addWidget(self.title_label)
        layout.addWidget(self.table)
        layout.addWidget(self.name_input)
        layout.addWidget(self.age_input)
        layout.addWidget(self.city_input)
        layout.addWidget(self.major_input)
        layout.addWidget(self.add_button)
        layout.addWidget(self.edit_button)
        layout.addWidget(self.show_button)
        layout.addWidget(self.delete_button)
        layout.addWidget(self.result_label)

        self.setLayout(layout)

        self.setWindowTitle("第 13 课：表格控件")
        self.resize(500, 350)

    def show_selected_row(self):
        # 获取当前选中的行号
        row = self.table.currentRow()

        # 没有选择任何行时，currentRow() 返回 -1
        if row < 0:
            self.result_label.setText("请先选择一行")
            return

        # 获取当前行的四个单元格内容
        name = self.table.item(row, 0).text()
        age = self.table.item(row, 1).text()
        city = self.table.item(row, 2).text()
        major = self.table.item(row, 3).text()

        self.result_label.setText(
            f"姓名：{name}，年龄：{age}，城市：{city}，专业：{major}"
        )

    def delete_selected_row(self):
        # 获取当前选中的行号
        row = self.table.currentRow()

        if row < 0:
            self.result_label.setText("请先选择一行")
            return

        # 删除整行
        self.table.removeRow(row)
        self.result_label.setText("选中行已删除")

    def add_student(self):
        name = self.name_input.text().strip()
        age = self.age_input.text().strip()
        city = self.city_input.text().strip()
        major = self.major_input.text().strip()

        if not name or not age or not city or not major:
            self.result_label.setText("请完整填写姓名、年龄、城市和专业")
            return

        if not age.isdigit():
            self.result_label.setText("年龄必须是数字")
            return

        # 输入通过检查后，再创建新行
        row_count = self.table.rowCount()
        self.table.insertRow(row_count)

        self.table.setItem(row_count, 0, QTableWidgetItem(name))
        self.table.setItem(row_count, 1, QTableWidgetItem(age))
        self.table.setItem(row_count, 2, QTableWidgetItem(city))
        self.table.setItem(row_count, 3, QTableWidgetItem(major))

        self.result_label.setText("已添加一名新学生")
        self.clear_inputs()

    def edit_selected_row(self):
        # 获取当前选中的行号
        row = self.table.currentRow()

        if row < 0:
            self.result_label.setText("请先选择一行")
            return

        name = self.name_input.text().strip()
        age = self.age_input.text().strip()
        city = self.city_input.text().strip()
        major = self.major_input.text().strip()

        if not name or not age or not city or not major:
            self.result_label.setText("请完整填写姓名、年龄、城市和专业")
            return

        if not age.isdigit():
            self.result_label.setText("年龄必须是数字")
            return

        # 修改当前行的内容
        self.table.setItem(row, 0, QTableWidgetItem(name))
        self.table.setItem(row, 1, QTableWidgetItem(age))
        self.table.setItem(row, 2, QTableWidgetItem(city))
        self.table.setItem(row, 3, QTableWidgetItem(major))

        self.result_label.setText("选中行已修改")
        self.clear_inputs()

    def show_double_clicked_cell(self, row, column):
        # 根据行号和列号取得被双击的单元格
        item = self.table.item(row, column)

        if item is not None:
            self.result_label.setText(f"双击的内容：{item.text()}")

    def clear_inputs(self):
        # 添加或修改完成后清空全部输入框
        self.name_input.clear()
        self.age_input.clear()
        self.city_input.clear()
        self.major_input.clear()


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())
