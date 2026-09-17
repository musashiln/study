# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'lesson10.ui'
##
## Created by: Qt User Interface Compiler version 6.11.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QLabel, QLineEdit, QPushButton,
    QSizePolicy, QVBoxLayout, QWidget)

class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(600, 448)
        self.verticalLayout = QVBoxLayout(Form)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.nameInput = QLineEdit(Form)
        self.nameInput.setObjectName(u"nameInput")

        self.verticalLayout.addWidget(self.nameInput)

        self.nameLabel = QLabel(Form)
        self.nameLabel.setObjectName(u"nameLabel")

        self.verticalLayout.addWidget(self.nameLabel)

        self.submitButton = QPushButton(Form)
        self.submitButton.setObjectName(u"submitButton")

        self.verticalLayout.addWidget(self.submitButton)

        self.resultLabel = QLabel(Form)
        self.resultLabel.setObjectName(u"resultLabel")

        self.verticalLayout.addWidget(self.resultLabel)


        self.retranslateUi(Form)

        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Form", None))
        self.nameLabel.setText(QCoreApplication.translate("Form", u"TextLabel", None))
        self.submitButton.setText(QCoreApplication.translate("Form", u"\u63d0\u4ea4", None))
        self.resultLabel.setText(QCoreApplication.translate("Form", u"TextLabel", None))
    # retranslateUi

