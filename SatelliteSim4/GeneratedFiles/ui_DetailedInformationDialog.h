/********************************************************************************
** Form generated from reading UI file 'DetailedInformationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILEDINFORMATIONDIALOG_H
#define UI_DETAILEDINFORMATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetailedInformationDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_38;
    QLineEdit *lineEditNameSateName;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_39;
    QLineEdit *lineEditNameInternationalNumber;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_40;
    QLineEdit *lineEditNameLaunchSite;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_41;
    QLineEdit *lineEditNameLaunchSequence;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_42;
    QLineEdit *lineEditNameLaunchNumber;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_43;
    QLineEdit *lineEditNameStorageCapacity;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_44;
    QLineEdit *lineEditNameComputingPower;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_20;
    QLabel *labelSemimajorAxis;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_22;
    QLabel *labelEccentricity;
    QLabel *label_23;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_24;
    QLabel *labelInclination;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_26;
    QLabel *labelArgumentOfPerigee;
    QLabel *label_27;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_28;
    QLabel *labelLongitudeOfTheAscendingNode;
    QLabel *label_29;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_32;
    QLabel *labelPitch;
    QLabel *label_33;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_34;
    QLabel *labelYaw;
    QLabel *label_35;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_36;
    QLabel *labelRoll;
    QLabel *label_37;
    QHBoxLayout *horizontalLayout_25;
    QPushButton *pushButtonOK;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBoxEquList;
    QPushButton *pushButtonInstallLoadEqu;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widgetLoadEquipments;
    QPushButton *pushButtonClose;

    void setupUi(QDialog *DetailedInformationDialog)
    {
        if (DetailedInformationDialog->objectName().isEmpty())
            DetailedInformationDialog->setObjectName(QStringLiteral("DetailedInformationDialog"));
        DetailedInformationDialog->resize(1152, 519);
        horizontalLayout = new QHBoxLayout(DetailedInformationDialog);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scrollArea = new QScrollArea(DetailedInformationDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 562, 499));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        label_38 = new QLabel(groupBox_3);
        label_38->setObjectName(QStringLiteral("label_38"));

        horizontalLayout_23->addWidget(label_38);

        lineEditNameSateName = new QLineEdit(groupBox_3);
        lineEditNameSateName->setObjectName(QStringLiteral("lineEditNameSateName"));
        lineEditNameSateName->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditNameSateName->sizePolicy().hasHeightForWidth());
        lineEditNameSateName->setSizePolicy(sizePolicy);

        horizontalLayout_23->addWidget(lineEditNameSateName);


        verticalLayout_3->addLayout(horizontalLayout_23);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        label_39 = new QLabel(groupBox_3);
        label_39->setObjectName(QStringLiteral("label_39"));

        horizontalLayout_26->addWidget(label_39);

        lineEditNameInternationalNumber = new QLineEdit(groupBox_3);
        lineEditNameInternationalNumber->setObjectName(QStringLiteral("lineEditNameInternationalNumber"));
        lineEditNameInternationalNumber->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEditNameInternationalNumber->sizePolicy().hasHeightForWidth());
        lineEditNameInternationalNumber->setSizePolicy(sizePolicy);

        horizontalLayout_26->addWidget(lineEditNameInternationalNumber);


        verticalLayout_3->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        label_40 = new QLabel(groupBox_3);
        label_40->setObjectName(QStringLiteral("label_40"));

        horizontalLayout_27->addWidget(label_40);

        lineEditNameLaunchSite = new QLineEdit(groupBox_3);
        lineEditNameLaunchSite->setObjectName(QStringLiteral("lineEditNameLaunchSite"));
        lineEditNameLaunchSite->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEditNameLaunchSite->sizePolicy().hasHeightForWidth());
        lineEditNameLaunchSite->setSizePolicy(sizePolicy);

        horizontalLayout_27->addWidget(lineEditNameLaunchSite);


        verticalLayout_3->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        label_41 = new QLabel(groupBox_3);
        label_41->setObjectName(QStringLiteral("label_41"));

        horizontalLayout_28->addWidget(label_41);

        lineEditNameLaunchSequence = new QLineEdit(groupBox_3);
        lineEditNameLaunchSequence->setObjectName(QStringLiteral("lineEditNameLaunchSequence"));
        lineEditNameLaunchSequence->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEditNameLaunchSequence->sizePolicy().hasHeightForWidth());
        lineEditNameLaunchSequence->setSizePolicy(sizePolicy);

        horizontalLayout_28->addWidget(lineEditNameLaunchSequence);


        verticalLayout_3->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        label_42 = new QLabel(groupBox_3);
        label_42->setObjectName(QStringLiteral("label_42"));

        horizontalLayout_29->addWidget(label_42);

        lineEditNameLaunchNumber = new QLineEdit(groupBox_3);
        lineEditNameLaunchNumber->setObjectName(QStringLiteral("lineEditNameLaunchNumber"));
        lineEditNameLaunchNumber->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEditNameLaunchNumber->sizePolicy().hasHeightForWidth());
        lineEditNameLaunchNumber->setSizePolicy(sizePolicy);

        horizontalLayout_29->addWidget(lineEditNameLaunchNumber);


        verticalLayout_3->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        label_43 = new QLabel(groupBox_3);
        label_43->setObjectName(QStringLiteral("label_43"));

        horizontalLayout_30->addWidget(label_43);

        lineEditNameStorageCapacity = new QLineEdit(groupBox_3);
        lineEditNameStorageCapacity->setObjectName(QStringLiteral("lineEditNameStorageCapacity"));
        lineEditNameStorageCapacity->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEditNameStorageCapacity->sizePolicy().hasHeightForWidth());
        lineEditNameStorageCapacity->setSizePolicy(sizePolicy);

        horizontalLayout_30->addWidget(lineEditNameStorageCapacity);


        verticalLayout_3->addLayout(horizontalLayout_30);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        label_44 = new QLabel(groupBox_3);
        label_44->setObjectName(QStringLiteral("label_44"));

        horizontalLayout_31->addWidget(label_44);

        lineEditNameComputingPower = new QLineEdit(groupBox_3);
        lineEditNameComputingPower->setObjectName(QStringLiteral("lineEditNameComputingPower"));
        lineEditNameComputingPower->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEditNameComputingPower->sizePolicy().hasHeightForWidth());
        lineEditNameComputingPower->setSizePolicy(sizePolicy);

        horizontalLayout_31->addWidget(lineEditNameComputingPower);


        verticalLayout_3->addLayout(horizontalLayout_31);


        verticalLayout->addWidget(groupBox_3);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_12->addWidget(label_20);

        labelSemimajorAxis = new QLabel(groupBox);
        labelSemimajorAxis->setObjectName(QStringLiteral("labelSemimajorAxis"));
        labelSemimajorAxis->setEnabled(false);

        horizontalLayout_12->addWidget(labelSemimajorAxis);

        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QStringLiteral("label_21"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy2);
        label_21->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_12->addWidget(label_21);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_14->addWidget(label_22);

        labelEccentricity = new QLabel(groupBox);
        labelEccentricity->setObjectName(QStringLiteral("labelEccentricity"));
        labelEccentricity->setEnabled(false);

        horizontalLayout_14->addWidget(labelEccentricity);

        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy2.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy2);
        label_23->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_14->addWidget(label_23);


        verticalLayout_5->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_15->addWidget(label_24);

        labelInclination = new QLabel(groupBox);
        labelInclination->setObjectName(QStringLiteral("labelInclination"));

        horizontalLayout_15->addWidget(labelInclination);

        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QStringLiteral("label_25"));
        sizePolicy2.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy2);
        label_25->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_15->addWidget(label_25);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_26 = new QLabel(groupBox);
        label_26->setObjectName(QStringLiteral("label_26"));

        horizontalLayout_16->addWidget(label_26);

        labelArgumentOfPerigee = new QLabel(groupBox);
        labelArgumentOfPerigee->setObjectName(QStringLiteral("labelArgumentOfPerigee"));
        labelArgumentOfPerigee->setEnabled(false);

        horizontalLayout_16->addWidget(labelArgumentOfPerigee);

        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QStringLiteral("label_27"));
        sizePolicy2.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy2);
        label_27->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_16->addWidget(label_27);


        verticalLayout_5->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_28 = new QLabel(groupBox);
        label_28->setObjectName(QStringLiteral("label_28"));

        horizontalLayout_17->addWidget(label_28);

        labelLongitudeOfTheAscendingNode = new QLabel(groupBox);
        labelLongitudeOfTheAscendingNode->setObjectName(QStringLiteral("labelLongitudeOfTheAscendingNode"));
        labelLongitudeOfTheAscendingNode->setEnabled(false);

        horizontalLayout_17->addWidget(labelLongitudeOfTheAscendingNode);

        label_29 = new QLabel(groupBox);
        label_29->setObjectName(QStringLiteral("label_29"));
        sizePolicy2.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy2);
        label_29->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_17->addWidget(label_29);


        verticalLayout_5->addLayout(horizontalLayout_17);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        label_32 = new QLabel(groupBox_2);
        label_32->setObjectName(QStringLiteral("label_32"));

        horizontalLayout_20->addWidget(label_32);

        labelPitch = new QLabel(groupBox_2);
        labelPitch->setObjectName(QStringLiteral("labelPitch"));
        labelPitch->setEnabled(false);

        horizontalLayout_20->addWidget(labelPitch);

        label_33 = new QLabel(groupBox_2);
        label_33->setObjectName(QStringLiteral("label_33"));
        sizePolicy2.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy2);
        label_33->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_20->addWidget(label_33);


        verticalLayout_6->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_34 = new QLabel(groupBox_2);
        label_34->setObjectName(QStringLiteral("label_34"));

        horizontalLayout_21->addWidget(label_34);

        labelYaw = new QLabel(groupBox_2);
        labelYaw->setObjectName(QStringLiteral("labelYaw"));
        labelYaw->setEnabled(false);

        horizontalLayout_21->addWidget(labelYaw);

        label_35 = new QLabel(groupBox_2);
        label_35->setObjectName(QStringLiteral("label_35"));
        sizePolicy2.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy2);
        label_35->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_21->addWidget(label_35);


        verticalLayout_6->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_36 = new QLabel(groupBox_2);
        label_36->setObjectName(QStringLiteral("label_36"));

        horizontalLayout_22->addWidget(label_36);

        labelRoll = new QLabel(groupBox_2);
        labelRoll->setObjectName(QStringLiteral("labelRoll"));
        labelRoll->setEnabled(false);

        horizontalLayout_22->addWidget(labelRoll);

        label_37 = new QLabel(groupBox_2);
        label_37->setObjectName(QStringLiteral("label_37"));
        sizePolicy2.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy2);
        label_37->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_22->addWidget(label_37);


        verticalLayout_6->addLayout(horizontalLayout_22);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        pushButtonOK = new QPushButton(scrollAreaWidgetContents);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));

        horizontalLayout_25->addWidget(pushButtonOK);


        verticalLayout->addLayout(horizontalLayout_25);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        scrollArea_2 = new QScrollArea(DetailedInformationDialog);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 562, 499));
        verticalLayout_9 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        comboBoxEquList = new QComboBox(scrollAreaWidgetContents_2);
        comboBoxEquList->setObjectName(QStringLiteral("comboBoxEquList"));

        horizontalLayout_3->addWidget(comboBoxEquList);

        pushButtonInstallLoadEqu = new QPushButton(scrollAreaWidgetContents_2);
        pushButtonInstallLoadEqu->setObjectName(QStringLiteral("pushButtonInstallLoadEqu"));

        horizontalLayout_3->addWidget(pushButtonInstallLoadEqu);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_9->addLayout(horizontalLayout_3);

        widgetLoadEquipments = new QWidget(scrollAreaWidgetContents_2);
        widgetLoadEquipments->setObjectName(QStringLiteral("widgetLoadEquipments"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widgetLoadEquipments->sizePolicy().hasHeightForWidth());
        widgetLoadEquipments->setSizePolicy(sizePolicy3);

        verticalLayout_9->addWidget(widgetLoadEquipments);

        pushButtonClose = new QPushButton(scrollAreaWidgetContents_2);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));

        verticalLayout_9->addWidget(pushButtonClose);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(scrollArea_2);


        retranslateUi(DetailedInformationDialog);

        QMetaObject::connectSlotsByName(DetailedInformationDialog);
    } // setupUi

    void retranslateUi(QDialog *DetailedInformationDialog)
    {
        DetailedInformationDialog->setWindowTitle(QApplication::translate("DetailedInformationDialog", "\345\215\253\346\230\237\350\257\246\347\273\206\344\277\241\346\201\257", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        DetailedInformationDialog->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        groupBox_3->setTitle(QApplication::translate("DetailedInformationDialog", "\345\237\272\346\234\254\344\277\241\346\201\257", Q_NULLPTR));
        label_38->setText(QApplication::translate("DetailedInformationDialog", "\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        lineEditNameSateName->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        label_39->setText(QApplication::translate("DetailedInformationDialog", "\345\233\275\351\231\205\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        lineEditNameInternationalNumber->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        label_40->setText(QApplication::translate("DetailedInformationDialog", "\345\217\221\345\260\204\345\234\260\347\202\271\357\274\232", Q_NULLPTR));
        lineEditNameLaunchSite->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        label_41->setText(QApplication::translate("DetailedInformationDialog", "\345\217\221\345\260\204\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        lineEditNameLaunchSequence->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        label_42->setText(QApplication::translate("DetailedInformationDialog", "\345\217\221\345\260\204\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        lineEditNameLaunchNumber->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        label_43->setText(QApplication::translate("DetailedInformationDialog", "\345\255\230\345\202\250\345\256\271\351\207\217\357\274\232", Q_NULLPTR));
        lineEditNameStorageCapacity->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        label_44->setText(QApplication::translate("DetailedInformationDialog", "\350\256\241\347\256\227\350\203\275\345\212\233\357\274\232", Q_NULLPTR));
        lineEditNameComputingPower->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DetailedInformationDialog", "\350\275\250\351\201\223\345\217\202\346\225\260", Q_NULLPTR));
        label_20->setText(QApplication::translate("DetailedInformationDialog", "\351\225\277\345\215\212\350\275\264(a)\357\274\232", Q_NULLPTR));
        labelSemimajorAxis->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        label_21->setText(QApplication::translate("DetailedInformationDialog", "(km)", Q_NULLPTR));
        label_22->setText(QApplication::translate("DetailedInformationDialog", "\345\201\217\345\277\203\347\216\207(e)\357\274\232", Q_NULLPTR));
        labelEccentricity->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        label_23->setText(QString());
        label_24->setText(QApplication::translate("DetailedInformationDialog", "\350\275\250\351\201\223\345\200\276\350\247\222(i)\357\274\232", Q_NULLPTR));
        labelInclination->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        label_25->setText(QApplication::translate("DetailedInformationDialog", "(\345\272\246)[0,180]", Q_NULLPTR));
        label_26->setText(QApplication::translate("DetailedInformationDialog", "\350\277\221\345\234\260\347\202\271\345\271\205\350\247\222(\317\211)\357\274\232", Q_NULLPTR));
        labelArgumentOfPerigee->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        label_27->setText(QApplication::translate("DetailedInformationDialog", "(\345\272\246)[0,360]", Q_NULLPTR));
        label_28->setText(QApplication::translate("DetailedInformationDialog", "\345\215\207\344\272\244\347\202\271\350\265\244\347\273\217(\316\251)\357\274\232", Q_NULLPTR));
        labelLongitudeOfTheAscendingNode->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        label_29->setText(QApplication::translate("DetailedInformationDialog", "(\345\272\246)[0,360]", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("DetailedInformationDialog", "\345\215\253\346\230\237\345\247\277\346\200\201", Q_NULLPTR));
        label_32->setText(QApplication::translate("DetailedInformationDialog", "\344\277\257\344\273\260\350\247\222(Pitch):", Q_NULLPTR));
        labelPitch->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        label_33->setText(QApplication::translate("DetailedInformationDialog", "(\345\272\246)[0,360]", Q_NULLPTR));
        label_34->setText(QApplication::translate("DetailedInformationDialog", "\345\201\217\350\210\252\350\247\222(Yaw):", Q_NULLPTR));
        labelYaw->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        label_35->setText(QApplication::translate("DetailedInformationDialog", "(\345\272\246)[0,360]", Q_NULLPTR));
        label_36->setText(QApplication::translate("DetailedInformationDialog", "\347\277\273\346\273\232\350\247\222(Roll):", Q_NULLPTR));
        labelRoll->setText(QApplication::translate("DetailedInformationDialog", "*", Q_NULLPTR));
        label_37->setText(QApplication::translate("DetailedInformationDialog", "(\345\272\246)[0,360]", Q_NULLPTR));
        pushButtonOK->setText(QApplication::translate("DetailedInformationDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        comboBoxEquList->clear();
        comboBoxEquList->insertItems(0, QStringList()
         << QApplication::translate("DetailedInformationDialog", "\350\275\275\350\215\2671", Q_NULLPTR)
         << QApplication::translate("DetailedInformationDialog", "\350\275\275\350\215\2672", Q_NULLPTR)
        );
        pushButtonInstallLoadEqu->setText(QApplication::translate("DetailedInformationDialog", "\346\214\202\350\275\275", Q_NULLPTR));
        pushButtonClose->setText(QApplication::translate("DetailedInformationDialog", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DetailedInformationDialog: public Ui_DetailedInformationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILEDINFORMATIONDIALOG_H
