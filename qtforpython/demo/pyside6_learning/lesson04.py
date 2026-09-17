import sys

from PySide6.QtWidgets import (
    QApplication,
    QWidget,
    QLabel,
    QLineEdit,
    QPushButton,
    QCheckBox,
    QComboBox,
    QVBoxLayout,
)


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        # 姓名提示文字
        self.name_label = QLabel("姓名：")

        # 姓名输入框
        self.name_input = QLineEdit()
        self.name_input.setPlaceholderText("请输入姓名")

        # 年龄提示文字
        self.age_label = QLabel("年龄：")

        # 年龄输入框
        self.age_input = QLineEdit()
        self.age_input.setPlaceholderText("请输入年龄")

        # 下拉框提示文字
        self.color_label = QLabel("喜欢的颜色：")

        # 创建下拉框
        self.color_combo = QComboBox()

        # 向下拉框添加选项
        self.color_combo.addItem("请选择")
        self.color_combo.addItem("红色")
        self.color_combo.addItem("绿色")
        self.color_combo.addItem("蓝色")

        # 下拉框提示文字
        self.role_label = QLabel("身份：")

        # 创建下拉框
        self.role_combo = QComboBox()
        
        # 向下拉框添加选项
        self.role_combo.addItem("学生")
        self.role_combo.addItem("教师")
        self.role_combo.addItem("其他")

        # 创建复选框
        self.agree_checkbox = QCheckBox("我同意提交信息")

        # 创建按钮
        self.button = QPushButton("提交")

        # 创建结果标签
        self.result_label = QLabel("填写信息后点击提交")

        # 连接按钮的点击信号
        self.button.clicked.connect(self.handle_submit)

        # 创建垂直布局
        layout = QVBoxLayout()

        # 按顺序把控件放入窗口
        layout.addWidget(self.name_label)
        layout.addWidget(self.name_input)
        layout.addWidget(self.age_label)
        layout.addWidget(self.age_input)
        layout.addWidget(self.color_label)
        layout.addWidget(self.color_combo)
        layout.addWidget(self.role_label)
        layout.addWidget(self.role_combo)
        layout.addWidget(self.agree_checkbox)
        layout.addWidget(self.button)
        layout.addWidget(self.result_label)

        # 将布局设置给窗口
        self.setLayout(layout)

        # 设置窗口标题和大小
        self.setWindowTitle("第 4 课：输入验证")
        self.resize(400, 350)

    def handle_submit(self):
        # 读取输入框内容
        name = self.name_input.text().strip()
        age = self.age_input.text().strip()

        # 读取下拉框当前选中的文字
        color = self.color_combo.currentText()

        # 读取下拉框当前选中的文字
        role = self.role_combo.currentText()

        # 判断复选框是否被选中
        is_agreed = self.agree_checkbox.isChecked()

        # 逐项检查用户输入
        if not name:
            self.result_label.setText("请输入姓名")
        elif not age:
            self.result_label.setText("请输入年龄")
        elif not age.isdigit():
            self.result_label.setText("年龄必须是数字")
        else:
            # 输入框中的内容是字符串，先转换成整数后再比较数值范围
            age_number = int(age)

            if age_number < 1 or age_number > 120:
                self.result_label.setText("请输入 1 到 120 之间的年龄")
                return

            if color == "请选择":
                self.result_label.setText("请选择喜欢的颜色")
                return

            if not is_agreed:
                self.result_label.setText("请先同意提交信息")
                return

            self.result_label.setText(
                f"姓名：{name}，年龄：{age}，喜欢的颜色：{color}，身份：{role}"
            )


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())
