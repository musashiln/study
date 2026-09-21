import sqlite3
import sys

from PySide6.QtWidgets import (
    QApplication,
    QFormLayout,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QMessageBox,
    QPushButton,
    QTableWidget,
    QTableWidgetItem,
    QVBoxLayout,
    QWidget,
)


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        # 数据库文件会保存在当前程序目录
        self.connection = sqlite3.connect("students.db")
        self.create_table()

        self.name_input = QLineEdit()
        self.age_input = QLineEdit()
        self.city_input = QLineEdit()
        self.email_input = QLineEdit()

        form_layout = QFormLayout()
        form_layout.addRow("姓名：", self.name_input)
        form_layout.addRow("年龄：", self.age_input)
        form_layout.addRow("城市：", self.city_input)
        form_layout.addRow("邮箱：", self.email_input)

        self.add_button = QPushButton("添加学生")
        self.clear_button = QPushButton("清空所有学生")
        self.delete_button = QPushButton("删除选中行")
        self.refresh_button = QPushButton("刷新表格")

        self.result_label = QLabel("请输入学生信息")

        button_layout = QHBoxLayout()
        button_layout.addWidget(self.add_button)
        button_layout.addWidget(self.clear_button)
        button_layout.addWidget(self.delete_button)
        button_layout.addWidget(self.refresh_button)

        self.table = QTableWidget()
        self.table.setColumnCount(5)
        self.table.setHorizontalHeaderLabels(["编号", "姓名", "年龄", "城市", "邮箱"])

        # 姓名搜索框
        self.search_input = QLineEdit()
        self.search_input.setPlaceholderText("按姓名搜索")
        self.search_input.textChanged.connect(self.search_students)

        layout = QVBoxLayout()
        layout.addLayout(form_layout)
        layout.addLayout(button_layout)
        layout.addWidget(self.search_input)
        layout.addWidget(self.table)
        layout.addWidget(self.result_label)
        self.setLayout(layout)

        self.add_button.clicked.connect(self.add_student)
        self.clear_button.clicked.connect(self.clear_all_students)
        self.delete_button.clicked.connect(self.delete_student)
        self.refresh_button.clicked.connect(self.load_students)

        self.setWindowTitle("第 18 课：SQLite 数据库")
        self.resize(600, 400)

        self.load_students()

    def create_table(self):
        """如果 students 表不存在，就创建它。"""
        cursor = self.connection.cursor()
        cursor.execute(
            """
            CREATE TABLE IF NOT EXISTS students (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT NOT NULL,
                age INTEGER NOT NULL,
                city TEXT NOT NULL,
                email TEXT NOT NULL
            )
            """
        )

        # 兼容第一个版本创建的旧数据库：旧表可能还没有 email 字段
        cursor.execute("PRAGMA table_info(students)")
        columns = {row[1] for row in cursor.fetchall()}
        if "email" not in columns:
            cursor.execute(
                "ALTER TABLE students ADD COLUMN email TEXT NOT NULL DEFAULT ''"
            )

        self.connection.commit()

    def load_students(self):
        """从数据库读取所有学生，并重新填充表格。"""
        cursor = self.connection.cursor()
        cursor.execute("SELECT id, name, age, city, email FROM students ORDER BY id")
        rows = cursor.fetchall()

        self.table.setRowCount(0)

        for row_data in rows:
            row = self.table.rowCount()
            self.table.insertRow(row)

            for column, value in enumerate(row_data):
                self.table.setItem(row, column, QTableWidgetItem(str(value)))

        self.result_label.setText(f"当前共有 {len(rows)} 名学生")

    def add_student(self):
        """验证输入后，把一名学生写入数据库。"""
        name = self.name_input.text().strip()
        age_text = self.age_input.text().strip()
        city = self.city_input.text().strip()
        email = self.email_input.text().strip()

        if not name or not age_text or not city or not email:
            self.result_label.setText("请完整填写姓名、年龄、城市和邮箱")
            return

        if not age_text.isdigit():
            self.result_label.setText("年龄必须是数字")
            return

        age = int(age_text)

        cursor = self.connection.cursor()
        cursor.execute(
            "INSERT INTO students (name, age, city, email) VALUES (?, ?, ?, ?)",
            (name, age, city, email),
        )
        self.connection.commit()

        self.clear_inputs()
        self.load_students()
        self.result_label.setText("学生添加成功")

    def delete_student(self):
        """删除表格当前选中的数据库记录。"""
        row = self.table.currentRow()

        if row < 0:
            self.result_label.setText("请先选择一行")
            return

        id_item = self.table.item(row, 0)
        student_id = int(id_item.text())

        cursor = self.connection.cursor()
        cursor.execute("DELETE FROM students WHERE id = ?", (student_id,))
        self.connection.commit()

        self.load_students()
        self.result_label.setText("学生删除成功")

    def clear_all_students(self):
        answer = QMessageBox.question(
            self,
            "确认清空",
            "你确定要清空所有学生记录吗？此操作无法撤销。",
        )

        if answer == QMessageBox.StandardButton.Yes:
            # 清空 students 表中的所有记录
            cursor = self.connection.cursor()
            cursor.execute("DELETE FROM students")
            self.connection.commit()

            self.load_students()
            self.result_label.setText("已清空所有学生记录")
        else:
            self.result_label.setText("你取消了清空操作")

    def clear_inputs(self):
        self.name_input.clear()
        self.age_input.clear()
        self.city_input.clear()
        self.email_input.clear()

    def search_students(self):
        keyword = self.search_input.text().strip()
        cursor = self.connection.cursor()
        if keyword:
            cursor.execute("SELECT id, name, age, city, email FROM students WHERE name LIKE ?", (f"%{keyword}%",))
        else:
            cursor.execute("SELECT id, name, age, city, email FROM students ORDER BY id")
        rows = cursor.fetchall()

        self.table.setRowCount(0)

        for row_data in rows:
            row = self.table.rowCount()
            self.table.insertRow(row)

            for column, value in enumerate(row_data):
                self.table.setItem(row, column, QTableWidgetItem(str(value)))

        self.result_label.setText(f"当前共有 {len(rows)} 名学生")

    def closeEvent(self, event):
        # 程序关闭前释放数据库连接
        self.connection.close()
        event.accept()


app = QApplication(sys.argv)
window = MainWindow()
window.show()
sys.exit(app.exec())
