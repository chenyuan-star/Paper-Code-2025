/********************************************************************************
** Form generated from reading UI file 'FixPosLookAroundDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIXPOSLOOKAROUNDDIALOG_H
#define UI_FIXPOSLOOKAROUNDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_FixPosLookAroundDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBoxLon;
    QDoubleSpinBox *doubleSpinBoxLat;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *FixPosLookAroundDialog)
    {
        if (FixPosLookAroundDialog->objectName().isEmpty())
            FixPosLookAroundDialog->setObjectName(QStringLiteral("FixPosLookAroundDialog"));
        FixPosLookAroundDialog->resize(182, 95);
        gridLayout = new QGridLayout(FixPosLookAroundDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(FixPosLookAroundDialog);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(FixPosLookAroundDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(FixPosLookAroundDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        doubleSpinBoxLon = new QDoubleSpinBox(FixPosLookAroundDialog);
        doubleSpinBoxLon->setObjectName(QStringLiteral("doubleSpinBoxLon"));

        gridLayout->addWidget(doubleSpinBoxLon, 0, 1, 1, 1);

        doubleSpinBoxLat = new QDoubleSpinBox(FixPosLookAroundDialog);
        doubleSpinBoxLat->setObjectName(QStringLiteral("doubleSpinBoxLat"));

        gridLayout->addWidget(doubleSpinBoxLat, 1, 1, 1, 1);

        label_4 = new QLabel(FixPosLookAroundDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonOK = new QPushButton(FixPosLookAroundDialog);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));

        horizontalLayout->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(FixPosLookAroundDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 3);

        gridLayout->setColumnStretch(0, 1);

        retranslateUi(FixPosLookAroundDialog);

        QMetaObject::connectSlotsByName(FixPosLookAroundDialog);
    } // setupUi

    void retranslateUi(QDialog *FixPosLookAroundDialog)
    {
        FixPosLookAroundDialog->setWindowTitle(QApplication::translate("FixPosLookAroundDialog", "\345\256\232\347\202\271\347\216\257\350\247\206", Q_NULLPTR));
        label->setText(QApplication::translate("FixPosLookAroundDialog", "\347\273\217\345\272\246\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("FixPosLookAroundDialog", "\347\272\254\345\272\246\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("FixPosLookAroundDialog", "(\345\272\246)", Q_NULLPTR));
        label_4->setText(QApplication::translate("FixPosLookAroundDialog", "(\345\272\246)", Q_NULLPTR));
        pushButtonOK->setText(QApplication::translate("FixPosLookAroundDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("FixPosLookAroundDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FixPosLookAroundDialog: public Ui_FixPosLookAroundDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIXPOSLOOKAROUNDDIALOG_H
