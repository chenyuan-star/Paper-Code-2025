/********************************************************************************
** Form generated from reading UI file 'AboutDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QStringLiteral("AboutDialog"));
        AboutDialog->resize(567, 325);
        AboutDialog->setAutoFillBackground(false);
        AboutDialog->setStyleSheet(QStringLiteral("image: url(:/SatelliteSim/Resources/About.jpeg);"));
        AboutDialog->setSizeGripEnabled(false);

        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "\345\205\263\344\272\216 \345\244\251\345\237\272\351\200\232\347\224\250\350\256\241\347\256\227\347\216\257\345\242\203\344\273\277\347\234\237\346\274\224\347\244\272\347\263\273\347\273\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
