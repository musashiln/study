import sys
from PySide6.QtWidgets import QApplication, QLabel

app = QApplication(sys.argv)

label = QLabel("你好，PySide6!")
label.resize(600, 300)
label.show()
label1 = QLabel("这是我的第一个 PySide6 程序")
label1.resize(600, 300)
label1.show()

sys.exit(app.exec())