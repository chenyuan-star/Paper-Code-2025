/********************************************************************************
** Form generated from reading UI file 'LoadquipInformation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADQUIPINFORMATION_H
#define UI_LOADQUIPINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadquipInformation
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_45;
    QLineEdit *lineEditName;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_46;
    QLineEdit *lineEditType;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_47;
    QLineEdit *lineEditState;
    QHBoxLayout *horizontalLayout_34;
    QLabel *label_48;
    QLineEdit *lineEditNumber;
    QHBoxLayout *horizontalLayout_35;
    QLabel *label_49;
    QLineEdit *lineEditDeviceNumber;
    QHBoxLayout *horizontalLayout_36;
    QLabel *label_50;
    QLineEdit *lineEditImage;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWidgetFunctions;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QListWidget *listWidgetDetailParameter;

    void setupUi(QWidget *LoadquipInformation)
    {
        if (LoadquipInformation->objectName().isEmpty())
            LoadquipInformation->setObjectName(QStringLiteral("LoadquipInformation"));
        LoadquipInformation->resize(1012, 527);
        horizontalLayout = new QHBoxLayout(LoadquipInformation);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scrollArea = new QScrollArea(LoadquipInformation);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 492, 507));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        label_45 = new QLabel(groupBox_3);
        label_45->setObjectName(QStringLiteral("label_45"));

        horizontalLayout_24->addWidget(label_45);

        lineEditName = new QLineEdit(groupBox_3);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setEnabled(false);

        horizontalLayout_24->addWidget(lineEditName);


        verticalLayout_4->addLayout(horizontalLayout_24);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        label_46 = new QLabel(groupBox_3);
        label_46->setObjectName(QStringLiteral("label_46"));

        horizontalLayout_32->addWidget(label_46);

        lineEditType = new QLineEdit(groupBox_3);
        lineEditType->setObjectName(QStringLiteral("lineEditType"));
        lineEditType->setEnabled(false);

        horizontalLayout_32->addWidget(lineEditType);


        verticalLayout_4->addLayout(horizontalLayout_32);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName(QStringLiteral("horizontalLayout_33"));
        label_47 = new QLabel(groupBox_3);
        label_47->setObjectName(QStringLiteral("label_47"));

        horizontalLayout_33->addWidget(label_47);

        lineEditState = new QLineEdit(groupBox_3);
        lineEditState->setObjectName(QStringLiteral("lineEditState"));
        lineEditState->setEnabled(false);

        horizontalLayout_33->addWidget(lineEditState);


        verticalLayout_4->addLayout(horizontalLayout_33);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        label_48 = new QLabel(groupBox_3);
        label_48->setObjectName(QStringLiteral("label_48"));

        horizontalLayout_34->addWidget(label_48);

        lineEditNumber = new QLineEdit(groupBox_3);
        lineEditNumber->setObjectName(QStringLiteral("lineEditNumber"));
        lineEditNumber->setEnabled(false);

        horizontalLayout_34->addWidget(lineEditNumber);


        verticalLayout_4->addLayout(horizontalLayout_34);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        label_49 = new QLabel(groupBox_3);
        label_49->setObjectName(QStringLiteral("label_49"));

        horizontalLayout_35->addWidget(label_49);

        lineEditDeviceNumber = new QLineEdit(groupBox_3);
        lineEditDeviceNumber->setObjectName(QStringLiteral("lineEditDeviceNumber"));
        lineEditDeviceNumber->setEnabled(false);

        horizontalLayout_35->addWidget(lineEditDeviceNumber);


        verticalLayout_4->addLayout(horizontalLayout_35);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName(QStringLiteral("horizontalLayout_36"));
        label_50 = new QLabel(groupBox_3);
        label_50->setObjectName(QStringLiteral("label_50"));

        horizontalLayout_36->addWidget(label_50);

        lineEditImage = new QLineEdit(groupBox_3);
        lineEditImage->setObjectName(QStringLiteral("lineEditImage"));
        lineEditImage->setEnabled(false);

        horizontalLayout_36->addWidget(lineEditImage);


        verticalLayout_4->addLayout(horizontalLayout_36);


        verticalLayout_2->addWidget(groupBox_3);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        scrollArea_2 = new QScrollArea(LoadquipInformation);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 492, 507));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_4 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        listWidgetFunctions = new QListWidget(groupBox_4);
        listWidgetFunctions->setObjectName(QStringLiteral("listWidgetFunctions"));

        verticalLayout_3->addWidget(listWidgetFunctions);


        verticalLayout->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_5 = new QVBoxLayout(groupBox_5);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        listWidgetDetailParameter = new QListWidget(groupBox_5);
        listWidgetDetailParameter->setObjectName(QStringLiteral("listWidgetDetailParameter"));

        verticalLayout_5->addWidget(listWidgetDetailParameter);


        verticalLayout->addWidget(groupBox_5);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(scrollArea_2);


        retranslateUi(LoadquipInformation);

        QMetaObject::connectSlotsByName(LoadquipInformation);
    } // setupUi

    void retranslateUi(QWidget *LoadquipInformation)
    {
        LoadquipInformation->setWindowTitle(QApplication::translate("LoadquipInformation", "\350\275\275\350\215\267\350\257\246\347\273\206\344\277\241\346\201\257", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("LoadquipInformation", "\345\237\272\346\234\254\344\277\241\346\201\257", Q_NULLPTR));
        label_45->setText(QApplication::translate("LoadquipInformation", "\350\275\275\350\215\267\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        lineEditName->setText(QString());
        label_46->setText(QApplication::translate("LoadquipInformation", "\350\275\275\350\215\267\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        lineEditType->setText(QString());
        label_47->setText(QApplication::translate("LoadquipInformation", "\345\275\223\345\211\215\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        lineEditState->setText(QString());
        label_48->setText(QApplication::translate("LoadquipInformation", "\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        lineEditNumber->setText(QString());
        label_49->setText(QApplication::translate("LoadquipInformation", "\350\256\276\347\275\256\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        lineEditDeviceNumber->setText(QString());
        label_50->setText(QApplication::translate("LoadquipInformation", "\350\275\275\350\215\267\345\233\276\347\211\207\357\274\232", Q_NULLPTR));
        lineEditImage->setText(QString());
        groupBox_4->setTitle(QApplication::translate("LoadquipInformation", "\345\205\267\344\275\223\345\212\237\350\203\275", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("LoadquipInformation", "\350\257\246\347\273\206\345\217\202\346\225\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoadquipInformation: public Ui_LoadquipInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADQUIPINFORMATION_H
