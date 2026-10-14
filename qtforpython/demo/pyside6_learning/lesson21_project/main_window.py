from pathlib import Path

from PySide6.QtWidgets import (
    QFormLayout,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QMainWindow,
    QMessageBox,
    QPushButton,
    QTableWidget,
    QTableWidgetItem,
    QVBoxLayout,
    QWidget,
)

from database import StudentRepository


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        database_path = Path(__file__).resolve().parent / "data" / "students.db"
        self.repository = StudentRepository(database_path)

        self.name_input = QLineEdit()
        self.age_input = QLineEdit()
        self.city_input = QLineEdit()
        self.status_label = QLabel("请输入学生信息")

        form_layout = QFormLayout()
        form_layout.addRow("姓名：", self.name_input)
        form_layout.addRow("年龄：", self.age_input)
        form_layout.addRow("城市：", self.city_input)

        self.add_button = QPushButton("添加学生")
        self.delete_button = QPushButton("删除选中学生")
        self.refresh_button = QPushButton("刷新")

        button_layout = QHBoxLayout()
        button_layout.addWidget(self.add_button)
        button_layout.addWidget(self.delete_button)
        button_layout.addWidget(self.refresh_button)

        self.table = QTableWidget()
        self.table.setColumnCount(4)
        self.table.setHorizontalHeaderLabels(["编号", "姓名", "年龄", "城市"])

        layout = QVBoxLayout()
        layout.addLayout(form_layout)
        layout.addLayout(button_layout)
        layout.addWidget(self.table)
        layout.addWidget(self.status_label)

        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)

        self.add_button.clicked.connect(self.add_student)
        self.delete_button.clicked.connect(self.delete_student)
        self.refresh_button.clicked.connect(self.load_students)

        self.setWindowTitle("学生管理器")
        self.resize(650, 420)
        self.statusBar().showMessage("程序已准备好")
        self.load_students()

    def add_student(self):
        name = self.name_input.text().strip()
        age_text = self.age_input.text().strip()
        city = self.city_input.text().strip()

        if not name or not age_text or not city:
            self.status_label.setText("请完整填写姓名、年龄和城市")
            return

        if not age_text.isdigit():
            self.status_label.setText("年龄必须是数字")
            return

        self.repository.add_student(name, int(age_text), city)
        self.name_input.clear()
        self.age_input.clear()
        self.city_input.clear()
        self.load_students()
        self.status_label.setText("学生添加成功")
        self.statusBar().showMessage("数据库已更新", 3000)

    def delete_student(self):
        row = self.table.currentRow()
        if row < 0:
            self.status_label.setText("请先选择一名学生")
            return

        student_id = int(self.table.item(row, 0).text())
        answer = QMessageBox.question(
            self,
            "确认删除",
            "确定要删除选中的学生吗？",
        )
        if answer != QMessageBox.StandardButton.Yes:
            return

        if self.repository.delete_student(student_id):
            self.load_students()
            self.status_label.setText("学生删除成功")

    def load_students(self):
        students = self.repository.list_students()
        self.table.setRowCount(0)

        for student in students:
            row = self.table.rowCount()
            self.table.insertRow(row)
            for column, value in enumerate(student):
                self.table.setItem(row, column, QTableWidgetItem(str(value)))

        self.statusBar().showMessage(f"当前共有 {len(students)} 名学生")

    def closeEvent(self, event):
        self.repository.close()
        event.accept()
