/********************************************************************************
** Form generated from reading UI file 'AddRadarStationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRADARSTATIONDIALOG_H
#define UI_ADDRADARSTATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddRadarStationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBoxLon;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxLat;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxHei;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *AddRadarStationDialog)
    {
        if (AddRadarStationDialog->objectName().isEmpty())
            AddRadarStationDialog->setObjectName(QStringLiteral("AddRadarStationDialog"));
        AddRadarStationDialog->resize(362, 221);
        verticalLayout = new QVBoxLayout(AddRadarStationDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AddRadarStationDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditName = new QLineEdit(AddRadarStationDialog);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        horizontalLayout->addWidget(lineEditName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(AddRadarStationDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        doubleSpinBoxLon = new QDoubleSpinBox(AddRadarStationDialog);
        doubleSpinBoxLon->setObjectName(QStringLiteral("doubleSpinBoxLon"));
        doubleSpinBoxLon->setMinimum(-180);
        doubleSpinBoxLon->setMaximum(180);
        doubleSpinBoxLon->setValue(114.29);

        horizontalLayout_2->addWidget(doubleSpinBoxLon);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(AddRadarStationDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        doubleSpinBoxLat = new QDoubleSpinBox(AddRadarStationDialog);
        doubleSpinBoxLat->setObjectName(QStringLiteral("doubleSpinBoxLat"));
        doubleSpinBoxLat->setMinimum(-90);
        doubleSpinBoxLat->setMaximum(90);
        doubleSpinBoxLat->setValue(30.58);

        horizontalLayout_3->addWidget(doubleSpinBoxLat);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(AddRadarStationDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        doubleSpinBoxHei = new QDoubleSpinBox(AddRadarStationDialog);
        doubleSpinBoxHei->setObjectName(QStringLiteral("doubleSpinBoxHei"));
        doubleSpinBoxHei->setMaximum(1e+9);
        doubleSpinBoxHei->setValue(1);

        horizontalLayout_5->addWidget(doubleSpinBoxHei);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButtonOk = new QPushButton(AddRadarStationDialog);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));

        horizontalLayout_4->addWidget(pushButtonOk);

        pushButtonCancel = new QPushButton(AddRadarStationDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_4->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(AddRadarStationDialog);

        QMetaObject::connectSlotsByName(AddRadarStationDialog);
    } // setupUi

    void retranslateUi(QDialog *AddRadarStationDialog)
    {
        AddRadarStationDialog->setWindowTitle(QApplication::translate("AddRadarStationDialog", "\346\267\273\345\212\240\345\234\260\351\235\242\351\233\267\350\276\276\347\253\231", Q_NULLPTR));
        label->setText(QApplication::translate("AddRadarStationDialog", "\345\220\215\347\247\260:", Q_NULLPTR));
        lineEditName->setText(QApplication::translate("AddRadarStationDialog", "\345\234\260\351\235\242\351\233\267\350\276\276\347\253\231_1", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddRadarStationDialog", "\347\273\217\345\272\246:", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddRadarStationDialog", "\347\272\254\345\272\246:", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddRadarStationDialog", "\351\253\230\345\272\246:", Q_NULLPTR));
        pushButtonOk->setText(QApplication::translate("AddRadarStationDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("AddRadarStationDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddRadarStationDialog: public Ui_AddRadarStationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRADARSTATIONDIALOG_H
