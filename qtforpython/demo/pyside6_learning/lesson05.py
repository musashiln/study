import sys

from PySide6.QtWidgets import (
    QApplication,
    QCheckBox,
    QWidget,
    QLabel,
    QLineEdit,
    QPushButton,
    QComboBox,
    QRadioButton,
    QSpinBox,
    QFormLayout,
    QVBoxLayout,
    QHBoxLayout,
)


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        # 创建姓名输入框
        self.name_input = QLineEdit()
        self.name_input.setPlaceholderText("请输入姓名")

        # 创建年龄数字输入框
        self.age_input = QSpinBox()
        self.age_input.setRange(1, 120)
        self.age_input.setValue(18)

        # 创建颜色下拉框
        self.color_combo = QComboBox()
        self.color_combo.addItems(["红色", "绿色", "蓝色"])

        # 创建职业下拉框
        self.role_combo = QComboBox()
        self.role_combo.addItems(["程序员", "设计师", "学生", "其他"])

        # 创建性别单选按钮
        self.male_radio = QRadioButton("男")
        self.female_radio = QRadioButton("女")

        # 默认选中“男”
        self.male_radio.setChecked(True)

        # 创建水平布局，用来横向排列性别按钮
        gender_layout = QHBoxLayout()
        gender_layout.addWidget(self.male_radio)
        gender_layout.addWidget(self.female_radio)

        # 创建提交按钮
        self.submit_button = QPushButton("提交")

        # 创建结果标签
        self.result_label = QLabel("请填写信息后提交")

        # 点击按钮时执行 handle_submit 方法
        self.submit_button.clicked.connect(self.handle_submit)

        # 创建表单布局
        form_layout = QFormLayout()

        # 左侧是字段名称，右侧是输入控件
        form_layout.addRow("姓名：", self.name_input)
        form_layout.addRow("年龄：", self.age_input)
        form_layout.addRow("喜欢的颜色：", self.color_combo)
        form_layout.addRow("职业：", self.role_combo)
        form_layout.addRow("性别：", gender_layout)

        # 创建复选框
        self.my_checkbox = QCheckBox("我喜欢学习 Python")

        # 创建总的垂直布局
        main_layout = QVBoxLayout()

        # 把表单、按钮和结果标签从上到下排列
        main_layout.addLayout(form_layout)
        main_layout.addWidget(self.my_checkbox)
        main_layout.addWidget(self.submit_button)
        main_layout.addWidget(self.result_label)

        # 把总布局设置给窗口
        self.setLayout(main_layout)

        # 设置窗口标题和大小
        self.setWindowTitle("第 5 课：常用控件")
        self.resize(450, 250)

    def handle_submit(self):
        # 获取姓名输入框中的文字，并删除两端空格
        name = self.name_input.text().strip()

        # 获取 QSpinBox 中的整数
        age = self.age_input.value()

        # 获取下拉框当前选中的文字
        color = self.color_combo.currentText()

        # 获取职业下拉框当前选中的文字
        role = self.role_combo.currentText()

        # 根据哪个单选按钮被选中，确定性别
        if self.male_radio.isChecked():
            gender = "男"
        else:
            gender = "女"

        # 检查姓名是否为空
        if not name:
            self.result_label.setText("请输入姓名")
            return

        # 判断复选框是否被选中
        is_checked = self.my_checkbox.isChecked()

        # 显示完整信息
        hobby = "喜欢学习 Python" if is_checked else "不喜欢学习 Python"

        self.result_label.setText(
            f"姓名：{name}，年龄：{age}，"
            f"颜色：{color}，性别：{gender}，"
            f"职业：{role}，{hobby}"
        )


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())
