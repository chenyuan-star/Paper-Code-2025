/********************************************************************************
** Form generated from reading UI file 'QueryFromServiceDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYFROMSERVICEDIALOG_H
#define UI_QUERYFROMSERVICEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QueryFromServiceDialog
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEditUrl;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *QueryFromServiceDialog)
    {
        if (QueryFromServiceDialog->objectName().isEmpty())
            QueryFromServiceDialog->setObjectName(QStringLiteral("QueryFromServiceDialog"));
        QueryFromServiceDialog->resize(330, 78);
        gridLayout = new QGridLayout(QueryFromServiceDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEditUrl = new QLineEdit(QueryFromServiceDialog);
        lineEditUrl->setObjectName(QStringLiteral("lineEditUrl"));

        gridLayout->addWidget(lineEditUrl, 0, 1, 1, 1);

        label = new QLabel(QueryFromServiceDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonOK = new QPushButton(QueryFromServiceDialog);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));

        horizontalLayout->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(QueryFromServiceDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);


        retranslateUi(QueryFromServiceDialog);

        QMetaObject::connectSlotsByName(QueryFromServiceDialog);
    } // setupUi

    void retranslateUi(QDialog *QueryFromServiceDialog)
    {
        QueryFromServiceDialog->setWindowTitle(QApplication::translate("QueryFromServiceDialog", "\344\273\216\346\234\215\345\212\241\346\237\245\350\257\242", Q_NULLPTR));
        lineEditUrl->setText(QApplication::translate("QueryFromServiceDialog", "http://192.168.20.59:6666", Q_NULLPTR));
        label->setText(QApplication::translate("QueryFromServiceDialog", "\346\234\215\345\212\241\345\234\260\345\235\200:", Q_NULLPTR));
        pushButtonOK->setText(QApplication::translate("QueryFromServiceDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("QueryFromServiceDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QueryFromServiceDialog: public Ui_QueryFromServiceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYFROMSERVICEDIALOG_H
