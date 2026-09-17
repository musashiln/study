import sys

from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QTextEdit,
    QMessageBox,
)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        # 创建文本编辑区域
        self.text_edit = QTextEdit()

        # 设置为主窗口的中央控件
        self.setCentralWidget(self.text_edit)

        # 创建菜单栏
        self.create_menu()

        # 创建工具栏
        self.create_toolbar()

        # 创建状态栏
        self.statusBar().showMessage("程序已准备好")

        # 设置窗口标题和大小
        self.setWindowTitle("第 7 课：主窗口")
        self.resize(700, 500)

    def create_menu(self):
        # 创建“文件”菜单
        file_menu = self.menuBar().addMenu("文件")

        # 创建“新建”操作
        new_action = file_menu.addAction("新建")
        new_action.triggered.connect(self.new_file)

        # 创建“退出”操作
        exit_action = file_menu.addAction("退出")
        exit_action.triggered.connect(self.close)

        # 创建“帮助”菜单
        help_menu = self.menuBar().addMenu("帮助")

        # 创建“关于”操作
        about_action = help_menu.addAction("关于")
        about_action.triggered.connect(self.show_about)

        # 创建“编辑”菜单
        edit_menu = self.menuBar().addMenu("编辑")

        # 创建“撤销”操作
        undo_action = edit_menu.addAction("撤销")
        undo_action.triggered.connect(self.text_edit.undo)

        # 创建“重做”操作
        redo_action = edit_menu.addAction("重做")
        redo_action.triggered.connect(self.text_edit.redo)

    def create_toolbar(self):
        # 创建工具栏
        toolbar = self.addToolBar("常用操作")

        # 添加“新建”按钮
        new_action = toolbar.addAction("新建")
        new_action.triggered.connect(self.new_file)

        # 添加“清空”按钮
        clear_action = toolbar.addAction("清空")
        clear_action.triggered.connect(self.clear_text)

        # 添加“撤销”按钮
        undo_action = toolbar.addAction("撤销")
        undo_action.triggered.connect(self.text_edit.undo)

        # 添加“重做”按钮
        redo_action = toolbar.addAction("重做")
        redo_action.triggered.connect(self.text_edit.redo)

    def new_file(self):
        # 清空文本编辑区域
        self.text_edit.clear()

        # 更新状态栏文字
        self.statusBar().showMessage("已新建空白文档")

    def clear_text(self):
        # 清空编辑器内容
        self.text_edit.clear()

        # 更新状态栏文字
        self.statusBar().showMessage("文本已清空")

    def show_about(self):
        # 显示关于对话框
        QMessageBox.about(
            self,
            "关于",
            "这是我的第一个 QMainWindow 程序",
        )


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())