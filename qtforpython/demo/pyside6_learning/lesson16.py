import sys

from PySide6.QtGui import QAction
from PySide6.QtWidgets import (
    QApplication,
    QLabel,
    QMainWindow,
    QMenu,
    QPushButton,
    QSystemTrayIcon,
    QTextEdit,
)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.text_edit = QTextEdit()
        # 拖放事件由 MainWindow 的 dragEnterEvent/dropEvent 处理。
        # 不让中央文本编辑器拦截文件拖放事件。
        self.text_edit.setAcceptDrops(False)
        self.setCentralWidget(self.text_edit)

        # 创建菜单栏和系统托盘图标
        self.create_menu()
        self.create_tray_icon()

        # 设置窗口属性
        self.setAcceptDrops(True)
        self.setWindowTitle("第 16 课：剪贴板、拖放和系统托盘")
        self.resize(700, 500)

        self.statusBar().showMessage("准备就绪")

        self.word_count_label = QLabel("字数：0")
        self.statusBar().addPermanentWidget(self.word_count_label)
        self.text_edit.textChanged.connect(self.update_word_count)

        self.clipboard_count_label = QLabel("剪贴板字数：0")
        self.statusBar().addPermanentWidget(self.clipboard_count_label)
        QApplication.clipboard().dataChanged.connect(
            self.update_clipboard_count
        )
        self.update_clipboard_count()

        exit_button = QPushButton("退出程序", self)
        exit_button.clicked.connect(QApplication.quit)

        self.quit_button = exit_button
        self.statusBar().addPermanentWidget(exit_button)

    def update_word_count(self):
        count = len(self.text_edit.toPlainText())
        self.word_count_label.setText(f"字数：{count}")

    def update_clipboard_count(self):
        clipboard_text = QApplication.clipboard().text()
        self.clipboard_count_label.setText(
            f"剪贴板字数：{len(clipboard_text)}"
        )

    def create_menu(self):
        edit_menu = self.menuBar().addMenu("编辑")
        clear_menu = self.menuBar().addMenu("清空文本")

        copy_action = QAction("复制", self)
        copy_action.setShortcut("Ctrl+C")
        copy_action.triggered.connect(self.text_edit.copy)
        edit_menu.addAction(copy_action)

        paste_action = QAction("粘贴", self)
        paste_action.setShortcut("Ctrl+V")
        paste_action.triggered.connect(self.text_edit.paste)
        edit_menu.addAction(paste_action)

        cut_action = QAction("剪切", self)
        cut_action.setShortcut("Ctrl+X")
        cut_action.triggered.connect(self.text_edit.cut)
        edit_menu.addAction(cut_action)

        clear_action = QAction("清空文本", self)
        clear_action.triggered.connect(self.text_edit.clear)
        clear_menu.addAction(clear_action)

    def create_tray_icon(self):
        # 检查当前系统是否支持系统托盘
        if not QSystemTrayIcon.isSystemTrayAvailable():
            return

        self.tray_icon = QSystemTrayIcon(self)

        # 使用 Qt 内置图标
        self.tray_icon.setIcon(
            self.style().standardIcon(
                self.style().StandardPixmap.SP_ComputerIcon
            )
        )

        tray_menu = QMenu()

        show_action = QAction("显示窗口", self)
        show_action.triggered.connect(self.show_window)
        tray_menu.addAction(show_action)

        quit_action = QAction("退出程序", self)
        quit_action.triggered.connect(QApplication.quit)
        tray_menu.addAction(quit_action)

        clear_action = QAction("清空文本", self)
        clear_action.triggered.connect(self.text_edit.clear)
        tray_menu.addAction(clear_action)

        # 将菜单设置为系统托盘图标的上下文菜单
        self.tray_icon.setContextMenu(tray_menu)
        self.tray_icon.activated.connect(self.tray_activated)
        self.tray_icon.show()

    def show_window(self):
        self.showNormal()
        self.activateWindow()

    def tray_activated(self, reason):
        # 双击托盘图标时显示窗口
        if reason == QSystemTrayIcon.ActivationReason.DoubleClick:
            self.show_window()

    def dragEnterEvent(self, event):
        # 只有拖入文件或 URL 时才接受拖放
        if event.mimeData().hasUrls():
            event.acceptProposedAction()
        else:
            event.ignore()

    def dropEvent(self, event):
        # 读取拖入的所有文件路径
        file_paths = []

        for url in event.mimeData().urls():
            if url.isLocalFile():
                file_paths.append(url.toLocalFile())

        if file_paths:
            self.text_edit.setPlainText("\n".join(file_paths))
            self.statusBar().showMessage(
                f"已接收 {len(file_paths)} 个文件"
            )
            
        event.acceptProposedAction()

    def closeEvent(self, event):
        # 关闭窗口时隐藏到系统托盘，而不是直接退出
        if hasattr(self, "tray_icon") and self.tray_icon.isVisible():
            self.hide()
            self.tray_icon.showMessage(
                "程序仍在运行",
                "程序已隐藏到系统托盘，双击图标可以重新打开。",
                QSystemTrayIcon.MessageIcon.Information,
                2000,
            )
            event.ignore()
        else:
            event.accept()



app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec())
