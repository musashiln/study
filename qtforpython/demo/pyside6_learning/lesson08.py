import os
import sys

from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QTextEdit,
    QMessageBox,
    QFileDialog,
)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        # 当前打开或保存的文件路径
        self.current_file = ""

        # 创建文本编辑器
        self.text_edit = QTextEdit()

        # 设置中央控件
        self.setCentralWidget(self.text_edit)

        # 创建菜单
        self.create_menu()

        # 设置窗口标题和大小
        self.setWindowTitle("第 8 课：简易记事本")
        self.resize(700, 500)

    def create_menu(self):
        # 创建“文件”菜单
        file_menu = self.menuBar().addMenu("文件")

        # 新建
        new_action = file_menu.addAction("新建")
        new_action.setShortcut("Ctrl+N")
        new_action.triggered.connect(self.new_file)

        # 打开
        open_action = file_menu.addAction("打开")
        open_action.setShortcut("Ctrl+O")
        open_action.triggered.connect(self.open_file)

        # 保存
        save_action = file_menu.addAction("保存")
        save_action.setShortcut("Ctrl+S")
        save_action.triggered.connect(self.save_file)

        # 另存为
        save_as_action = file_menu.addAction("另存为")
        save_as_action.triggered.connect(self.save_as_file)

        file_menu.addSeparator()

        # 退出
        exit_action = file_menu.addAction("退出")
        exit_action.triggered.connect(self.close)

    def new_file(self):
        answer = QMessageBox.question(
            self,
            "确认操作",
            "确定要继续新建吗？",
        )

        if answer == QMessageBox.StandardButton.Yes:
            # 清空文本内容
            self.text_edit.clear()

            # 清除当前文件路径
            self.current_file = ""

            # 更新窗口标题
            self.setWindowTitle("第 8 课：简易记事本")

    def open_file(self):
        # 让用户选择一个文本文件
        file_path, _ = QFileDialog.getOpenFileName(
            self,
            "打开文件",
            "",
            "文本文件 (*.txt);;Python 文件 (*.py);;所有文件 (*.*)",
        )

        # 用户取消选择时，直接返回
        if not file_path:
            return

        try:
            # 以 UTF-8 编码读取文件
            with open(file_path, "r", encoding="utf-8") as file:
                content = file.read()

            # 把文件内容放进编辑器
            self.text_edit.setPlainText(content)

            # 保存当前文件路径
            self.current_file = file_path

            # 更新窗口标题和状态栏
            self.update_window_title()
            self.statusBar().showMessage("文件打开成功")

        except OSError as error:
            QMessageBox.critical(
                self,
                "打开失败",
                f"无法打开文件：{error}",
            )

    def save_file(self):
        # 如果还没有文件路径，就执行“另存为”
        if not self.current_file:
            self.save_as_file()
            return

        self.write_file(self.current_file)

    def save_as_file(self):
        # 让用户选择保存位置
        file_path, _ = QFileDialog.getSaveFileName(
            self,
            "保存文件",
            "",
            "文本文件 (*.txt);;所有文件 (*.*)",
        )

        # 用户取消保存时，直接返回
        if not file_path:
            return

        # 写入文件并记录路径
        self.write_file(file_path)

    def write_file(self, file_path):
        try:
            # 读取编辑器中的纯文本
            content = self.text_edit.toPlainText()

            # 以 UTF-8 编码写入文件
            with open(file_path, "w", encoding="utf-8") as file:
                file.write(content)

            # 保存当前文件路径
            self.current_file = file_path

            # 更新标题和状态栏
            self.update_window_title()
            self.statusBar().showMessage("文件保存成功")

            QMessageBox.information(
                self,
                "提示",
                file_path + " 文件保存成功",
            )

        except OSError as error:
            QMessageBox.critical(
                self,
                "保存失败",
                f"无法保存文件：{error}",
            )

    def update_window_title(self):
        """根据当前文件路径更新窗口标题，只显示文件名。"""
        if self.current_file:
            file_name = os.path.basename(self.current_file)
            self.setWindowTitle(f"第 8 课：{file_name}")
        else:
            self.setWindowTitle("第 8 课：简易记事本")
         

app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())
