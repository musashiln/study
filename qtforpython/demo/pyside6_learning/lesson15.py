import sys

from PySide6.QtCore import QSettings
from PySide6.QtWidgets import (
    QApplication,
    QCheckBox,
    QComboBox,
    QLabel,
    QLineEdit,
    QPushButton,
    QVBoxLayout,
    QWidget,
)


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("第 15 课：QSettings")

        # 创建设置对象。
        # 这两个名称用于区分不同的应用程序设置。
        self.settings = QSettings("MyLearning", "Lesson15")

        self.info_label = QLabel("关闭窗口后重新打开，观察设置是否被记住")

        self.name_label = QLabel("请输入姓名：")
        self.name_input = QLineEdit()

        self.color_label = QLabel("请选择颜色：")
        self.color_combo = QComboBox()
        self.color_combo.addItems(["红色", "绿色", "蓝色"])

        self.remember_checkbox = QCheckBox("记住我的选择")
        self.save_button = QPushButton("保存设置")
        self.reset_button = QPushButton("恢复默认设置")

        layout = QVBoxLayout()
        layout.addWidget(self.info_label)
        layout.addWidget(self.name_label)
        layout.addWidget(self.name_input)
        layout.addWidget(self.color_label)
        layout.addWidget(self.color_combo)
        layout.addWidget(self.remember_checkbox)
        layout.addWidget(self.save_button)
        layout.addWidget(self.reset_button)
        self.setLayout(layout)

        self.save_button.clicked.connect(self.save_settings)
        self.reset_button.clicked.connect(self.reset_settings)

        # 窗口创建时读取上次保存的设置
        self.load_settings()

    def load_settings(self):
        """读取设置；如果没有保存过，就使用默认值。"""
        geometry = self.settings.value("window_geometry")

        if geometry is not None:
            self.restoreGeometry(geometry)
        else:
            self.resize(400, 220)

        remember = self.settings.value(
            "remember_choice",
            False,
            type=bool,
        )
        self.remember_checkbox.setChecked(remember)

        name = self.settings.value("name", "")
        self.name_input.setText(name)

        color = self.settings.value("color", "红色")
        index = self.color_combo.findText(color)
        if index != -1:
            self.color_combo.setCurrentIndex(index)

    def save_settings(self):
        """把当前窗口状态和复选框状态写入设置。"""
        self.settings.setValue("window_geometry", self.saveGeometry())
        self.settings.setValue(
            "remember_choice",
            self.remember_checkbox.isChecked(),
        )
        if self.remember_checkbox.isChecked():
            self.settings.setValue("name", self.name_input.text())
            self.settings.setValue("color", self.color_combo.currentText())
        else:
            self.settings.remove("name")
            self.settings.remove("color")
        self.info_label.setText("设置已保存")

    def reset_settings(self):
        """删除保存的设置，并恢复默认界面。"""
        self.settings.clear()
        self.remember_checkbox.setChecked(False)
        self.name_input.clear()
        self.color_combo.setCurrentIndex(0)
        self.resize(400, 220)
        self.info_label.setText("设置已恢复默认值")

    def closeEvent(self, event):
        # 关闭窗口时自动保存设置
        self.save_settings()
        event.accept()


app = QApplication(sys.argv)
window = MainWindow()
window.show()
sys.exit(app.exec())
