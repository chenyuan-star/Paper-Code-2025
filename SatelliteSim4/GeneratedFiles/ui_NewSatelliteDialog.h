/********************************************************************************
** Form generated from reading UI file 'NewSatelliteDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSATELLITEDIALOG_H
#define UI_NEWSATELLITEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewSatelliteDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_16;
    QLineEdit *lineEditName;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxSemimajorAxis;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxEccentricity;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBoxInclination;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBoxArgumentOfPerigee;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxLongitudeOfTheAscendingNode;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBoxMeanAnomaly;
    QLabel *label_15;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBoxPitch;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBoxYaw;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBoxRoll;
    QLabel *label_17;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *lineEditPayloadFile;
    QPushButton *pushButtonOpenPayload;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *NewSatelliteDialog)
    {
        if (NewSatelliteDialog->objectName().isEmpty())
            NewSatelliteDialog->setObjectName(QStringLiteral("NewSatelliteDialog"));
        NewSatelliteDialog->resize(440, 490);
        verticalLayout = new QVBoxLayout(NewSatelliteDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_3 = new QGroupBox(NewSatelliteDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_11->addWidget(label_16);

        lineEditName = new QLineEdit(groupBox_3);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        horizontalLayout_11->addWidget(lineEditName);


        verticalLayout_4->addLayout(horizontalLayout_11);


        verticalLayout->addWidget(groupBox_3);

        groupBox = new QGroupBox(NewSatelliteDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        doubleSpinBoxSemimajorAxis = new QDoubleSpinBox(groupBox);
        doubleSpinBoxSemimajorAxis->setObjectName(QStringLiteral("doubleSpinBoxSemimajorAxis"));
        doubleSpinBoxSemimajorAxis->setDecimals(3);
        doubleSpinBoxSemimajorAxis->setMinimum(0);
        doubleSpinBoxSemimajorAxis->setMaximum(1e+8);
        doubleSpinBoxSemimajorAxis->setValue(36000);

        horizontalLayout_4->addWidget(doubleSpinBoxSemimajorAxis);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(label_10);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        doubleSpinBoxEccentricity = new QDoubleSpinBox(groupBox);
        doubleSpinBoxEccentricity->setObjectName(QStringLiteral("doubleSpinBoxEccentricity"));
        doubleSpinBoxEccentricity->setDecimals(7);
        doubleSpinBoxEccentricity->setMaximum(0.999);
        doubleSpinBoxEccentricity->setSingleStep(0.01);
        doubleSpinBoxEccentricity->setValue(0.01);

        horizontalLayout_5->addWidget(doubleSpinBoxEccentricity);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(label_12);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        doubleSpinBoxInclination = new QDoubleSpinBox(groupBox);
        doubleSpinBoxInclination->setObjectName(QStringLiteral("doubleSpinBoxInclination"));
        doubleSpinBoxInclination->setDecimals(4);
        doubleSpinBoxInclination->setMaximum(180);
        doubleSpinBoxInclination->setSingleStep(0.1);
        doubleSpinBoxInclination->setValue(30);

        horizontalLayout_3->addWidget(doubleSpinBoxInclination);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(label_11);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        doubleSpinBoxArgumentOfPerigee = new QDoubleSpinBox(groupBox);
        doubleSpinBoxArgumentOfPerigee->setObjectName(QStringLiteral("doubleSpinBoxArgumentOfPerigee"));
        doubleSpinBoxArgumentOfPerigee->setDecimals(4);
        doubleSpinBoxArgumentOfPerigee->setMaximum(360);
        doubleSpinBoxArgumentOfPerigee->setSingleStep(0.1);
        doubleSpinBoxArgumentOfPerigee->setValue(50);

        horizontalLayout_6->addWidget(doubleSpinBoxArgumentOfPerigee);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);
        label_13->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(label_13);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        doubleSpinBoxLongitudeOfTheAscendingNode = new QDoubleSpinBox(groupBox);
        doubleSpinBoxLongitudeOfTheAscendingNode->setObjectName(QStringLiteral("doubleSpinBoxLongitudeOfTheAscendingNode"));
        doubleSpinBoxLongitudeOfTheAscendingNode->setDecimals(4);
        doubleSpinBoxLongitudeOfTheAscendingNode->setMinimum(0);
        doubleSpinBoxLongitudeOfTheAscendingNode->setMaximum(360);
        doubleSpinBoxLongitudeOfTheAscendingNode->setSingleStep(0.1);
        doubleSpinBoxLongitudeOfTheAscendingNode->setValue(100);

        horizontalLayout_2->addWidget(doubleSpinBoxLongitudeOfTheAscendingNode);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(label_14);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        doubleSpinBoxMeanAnomaly = new QDoubleSpinBox(groupBox);
        doubleSpinBoxMeanAnomaly->setObjectName(QStringLiteral("doubleSpinBoxMeanAnomaly"));
        doubleSpinBoxMeanAnomaly->setDecimals(6);
        doubleSpinBoxMeanAnomaly->setMaximum(360);
        doubleSpinBoxMeanAnomaly->setValue(138.448);

        horizontalLayout_7->addWidget(doubleSpinBoxMeanAnomaly);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(label_15);


        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(NewSatelliteDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_9->addWidget(label_8);

        doubleSpinBoxPitch = new QDoubleSpinBox(groupBox_2);
        doubleSpinBoxPitch->setObjectName(QStringLiteral("doubleSpinBoxPitch"));
        doubleSpinBoxPitch->setDecimals(1);
        doubleSpinBoxPitch->setMaximum(360);

        horizontalLayout_9->addWidget(doubleSpinBoxPitch);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy1.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy1);
        label_18->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_9->addWidget(label_18);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_10->addWidget(label_9);

        doubleSpinBoxYaw = new QDoubleSpinBox(groupBox_2);
        doubleSpinBoxYaw->setObjectName(QStringLiteral("doubleSpinBoxYaw"));
        doubleSpinBoxYaw->setDecimals(1);
        doubleSpinBoxYaw->setMaximum(360);

        horizontalLayout_10->addWidget(doubleSpinBoxYaw);

        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy1.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy1);
        label_19->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_10->addWidget(label_19);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_8->addWidget(label_7);

        doubleSpinBoxRoll = new QDoubleSpinBox(groupBox_2);
        doubleSpinBoxRoll->setObjectName(QStringLiteral("doubleSpinBoxRoll"));
        doubleSpinBoxRoll->setDecimals(1);
        doubleSpinBoxRoll->setMaximum(360);

        horizontalLayout_8->addWidget(doubleSpinBoxRoll);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);
        label_17->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(label_17);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(NewSatelliteDialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_13 = new QHBoxLayout(groupBox_4);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        lineEditPayloadFile = new QLineEdit(groupBox_4);
        lineEditPayloadFile->setObjectName(QStringLiteral("lineEditPayloadFile"));
        lineEditPayloadFile->setReadOnly(true);

        horizontalLayout_13->addWidget(lineEditPayloadFile);

        pushButtonOpenPayload = new QPushButton(groupBox_4);
        pushButtonOpenPayload->setObjectName(QStringLiteral("pushButtonOpenPayload"));

        horizontalLayout_13->addWidget(pushButtonOpenPayload);


        verticalLayout->addWidget(groupBox_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonOK = new QPushButton(NewSatelliteDialog);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));

        horizontalLayout->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(NewSatelliteDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(NewSatelliteDialog);

        QMetaObject::connectSlotsByName(NewSatelliteDialog);
    } // setupUi

    void retranslateUi(QDialog *NewSatelliteDialog)
    {
        NewSatelliteDialog->setWindowTitle(QApplication::translate("NewSatelliteDialog", "\346\226\260\345\273\272\345\215\253\346\230\237", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("NewSatelliteDialog", "\345\237\272\346\234\254\344\277\241\346\201\257", Q_NULLPTR));
        label_16->setText(QApplication::translate("NewSatelliteDialog", "\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        lineEditName->setText(QApplication::translate("NewSatelliteDialog", "Satellite_1", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("NewSatelliteDialog", "\350\275\250\351\201\223\345\217\202\346\225\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("NewSatelliteDialog", "\351\225\277\345\215\212\350\275\264(a)\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("NewSatelliteDialog", "(km)", Q_NULLPTR));
        label_4->setText(QApplication::translate("NewSatelliteDialog", "\345\201\217\345\277\203\347\216\207(e)\357\274\232", Q_NULLPTR));
        label_12->setText(QString());
        label_2->setText(QApplication::translate("NewSatelliteDialog", "\350\275\250\351\201\223\345\200\276\350\247\222(i)\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("NewSatelliteDialog", "(\345\272\246)[0,180]", Q_NULLPTR));
        label_5->setText(QApplication::translate("NewSatelliteDialog", "\350\277\221\345\234\260\347\202\271\345\271\205\350\247\222(\317\211)\357\274\232", Q_NULLPTR));
        label_13->setText(QApplication::translate("NewSatelliteDialog", "(\345\272\246)[0,360]", Q_NULLPTR));
        label->setText(QApplication::translate("NewSatelliteDialog", "\345\215\207\344\272\244\347\202\271\350\265\244\347\273\217(\316\251)\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("NewSatelliteDialog", "(\345\272\246)[0,360]", Q_NULLPTR));
        label_6->setText(QApplication::translate("NewSatelliteDialog", "\345\271\263\350\277\221\347\202\271\350\247\222(M)\357\274\232", Q_NULLPTR));
        label_15->setText(QApplication::translate("NewSatelliteDialog", "(\345\272\246)[0,360]", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("NewSatelliteDialog", "\345\215\253\346\230\237\345\247\277\346\200\201", Q_NULLPTR));
        label_8->setText(QApplication::translate("NewSatelliteDialog", "\344\277\257\344\273\260\350\247\222(Pitch):", Q_NULLPTR));
        label_18->setText(QApplication::translate("NewSatelliteDialog", "(\345\272\246)[0,360]", Q_NULLPTR));
        label_9->setText(QApplication::translate("NewSatelliteDialog", "\345\201\217\350\210\252\350\247\222(Yaw):", Q_NULLPTR));
        label_19->setText(QApplication::translate("NewSatelliteDialog", "(\345\272\246)[0,360]", Q_NULLPTR));
        label_7->setText(QApplication::translate("NewSatelliteDialog", "\347\277\273\346\273\232\350\247\222(Roll):", Q_NULLPTR));
        label_17->setText(QApplication::translate("NewSatelliteDialog", "(\345\272\246)[0,360]", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("NewSatelliteDialog", "\346\220\255\350\275\275\350\275\275\350\215\267", Q_NULLPTR));
        pushButtonOpenPayload->setText(QApplication::translate("NewSatelliteDialog", "\346\211\223\345\274\200", Q_NULLPTR));
        pushButtonOK->setText(QApplication::translate("NewSatelliteDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("NewSatelliteDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewSatelliteDialog: public Ui_NewSatelliteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSATELLITEDIALOG_H
