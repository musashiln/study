import sys

from PySide6.QtGui import QAction, QKeySequence
from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QMessageBox,
    QTextEdit,
)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.text_edit = QTextEdit()
        self.setCentralWidget(self.text_edit)

        self.create_actions()
        self.create_menus()
        # 创建工具栏
        self.create_toolbar()

        self.setWindowTitle("第 10 课：快捷键和关闭事件")
        self.resize(700, 500)

    def create_actions(self):
        # 创建“新建”动作
        self.new_action = QAction("新建", self)

        # 设置快捷键
        self.new_action.setShortcut(QKeySequence("Ctrl+N"))

        # 连接动作信号
        self.new_action.triggered.connect(self.new_file)

        # 创建“保存”动作
        self.save_action = QAction("保存", self)
        self.save_action.setShortcut(QKeySequence("Ctrl+S"))
        self.save_action.triggered.connect(self.save_file)

        # 创建“退出”动作
        self.exit_action = QAction("退出", self)
        self.exit_action.setShortcut(QKeySequence("Ctrl+Q"))
        self.exit_action.triggered.connect(self.close)

    def create_menus(self):
        # 创建“文件”菜单
        file_menu = self.menuBar().addMenu("文件")

        # 添加动作
        file_menu.addAction(self.new_action)
        file_menu.addAction(self.save_action)
        file_menu.addAction(self.exit_action)

    def create_toolbar(self):
        # 创建工具栏
        toolbar = self.addToolBar("常用操作")

        # 添加“新建”按钮
        toolbar.addAction(self.new_action)

        # 添加“保存”按钮
        toolbar.addAction(self.save_action)

    def new_file(self):
        # 清空编辑器
        self.text_edit.clear()

        # 在状态栏显示提示
        self.statusBar().showMessage("已新建文件")

    def save_file(self):
        # 本课暂时不写入磁盘，只演示动作和信号的连接
        self.text_edit.document().setModified(False)
        self.statusBar().showMessage("已执行保存操作")

    def closeEvent(self, event):
        # 判断文本编辑器是否有未保存内容
        if self.text_edit.document().isModified():
            answer = QMessageBox.question(
                self,
                "确认退出",
                "内容尚未保存，确定要退出吗？",
                QMessageBox.StandardButton.Yes
                | QMessageBox.StandardButton.No,
                QMessageBox.StandardButton.No,
            )

            if answer == QMessageBox.StandardButton.Yes:
                event.accept()
            else:
                event.ignore()
        else:
            event.accept()


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())
