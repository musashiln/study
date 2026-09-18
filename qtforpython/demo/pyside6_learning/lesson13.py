import sys

from PySide6.QtWidgets import (
    QApplication,
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
        self.table.setRowCount(3)
        self.table.setColumnCount(3)

        # 设置表头
        self.table.setHorizontalHeaderLabels(
            ["姓名", "年龄", "城市"]
        )

        # 填充表格数据
        data = [
            ["小明", "18", "北京"],
            ["小红", "20", "上海"],
            ["小刚", "19", "广州"],
        ]

        for row_index, row_data in enumerate(data):
            for column_index, value in enumerate(row_data):
                item = QTableWidgetItem(value)
                self.table.setItem(row_index, column_index, item)

        # 创建按钮
        self.show_button = QPushButton("显示选中行")
        self.delete_button = QPushButton("删除选中行")

        # 创建结果标签
        self.result_label = QLabel("请选择一行")

        # 连接按钮
        self.show_button.clicked.connect(self.show_selected_row)
        self.delete_button.clicked.connect(self.delete_selected_row)

        # 创建布局
        layout = QVBoxLayout()
        layout.addWidget(self.title_label)
        layout.addWidget(self.table)
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

        # 获取当前行的三个单元格内容
        name = self.table.item(row, 0).text()
        age = self.table.item(row, 1).text()
        city = self.table.item(row, 2).text()

        self.result_label.setText(
            f"姓名：{name}，年龄：{age}，城市：{city}"
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


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())