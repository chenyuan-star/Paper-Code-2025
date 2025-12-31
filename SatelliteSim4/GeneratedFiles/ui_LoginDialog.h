/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QWidget *widgetLoginPanel;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEditName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEditPwd;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonLogin;
    QPushButton *pushButtonQuit;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(1200, 675);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginDialog->sizePolicy().hasHeightForWidth());
        LoginDialog->setSizePolicy(sizePolicy);
        LoginDialog->setMinimumSize(QSize(1200, 675));
        LoginDialog->setMaximumSize(QSize(1200, 675));
        QFont font;
        font.setFamily(QStringLiteral("AcadEref"));
        font.setPointSize(16);
        LoginDialog->setFont(font);
        LoginDialog->setStyleSheet(QStringLiteral("LoginDialog{border-image: url(:/SatelliteSim/Resources/Login.jpg);}"));
        horizontalLayout = new QHBoxLayout(LoginDialog);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        widgetLoginPanel = new QWidget(LoginDialog);
        widgetLoginPanel->setObjectName(QStringLiteral("widgetLoginPanel"));
        widgetLoginPanel->setMinimumSize(QSize(400, 300));
        widgetLoginPanel->setMaximumSize(QSize(400, 300));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Devanagari"));
        font1.setPointSize(11);
        widgetLoginPanel->setFont(font1);
        widgetLoginPanel->setStyleSheet(QStringLiteral("QWidget#widgetLoginPanel {background-color: rgba(128, 128, 128, 128);border-radius: 25px;}"));
        verticalLayout = new QVBoxLayout(widgetLoginPanel);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(32, 20, 32, 20);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(widgetLoginPanel);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_3->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(84, 190, 255);"));
        label_3->setTextFormat(Qt::AutoText);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widgetLoginPanel);
        label->setObjectName(QStringLiteral("label"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(14);
        label->setFont(font3);
        label->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label->setTextFormat(Qt::AutoText);

        horizontalLayout_2->addWidget(label);

        lineEditName = new QLineEdit(widgetLoginPanel);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setMinimumSize(QSize(0, 32));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font4.setPointSize(11);
        lineEditName->setFont(font4);
        lineEditName->setFrame(true);
        lineEditName->setEchoMode(QLineEdit::Normal);
        lineEditName->setCursorPosition(0);
        lineEditName->setReadOnly(false);
        lineEditName->setCursorMoveStyle(Qt::LogicalMoveStyle);

        horizontalLayout_2->addWidget(lineEditName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(widgetLoginPanel);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font3);
        label_2->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_2);

        lineEditPwd = new QLineEdit(widgetLoginPanel);
        lineEditPwd->setObjectName(QStringLiteral("lineEditPwd"));
        lineEditPwd->setMinimumSize(QSize(0, 32));
        lineEditPwd->setFont(font1);
        lineEditPwd->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(lineEditPwd);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButtonLogin = new QPushButton(widgetLoginPanel);
        pushButtonLogin->setObjectName(QStringLiteral("pushButtonLogin"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font5.setPointSize(14);
        pushButtonLogin->setFont(font5);
        pushButtonLogin->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(pushButtonLogin);

        pushButtonQuit = new QPushButton(widgetLoginPanel);
        pushButtonQuit->setObjectName(QStringLiteral("pushButtonQuit"));
        pushButtonQuit->setFont(font5);
        pushButtonQuit->setStyleSheet(QStringLiteral(""));
        pushButtonQuit->setCheckable(false);

        horizontalLayout_4->addWidget(pushButtonQuit);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(widgetLoginPanel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoginDialog", "\345\244\251\345\237\272\351\200\232\347\224\250\350\256\241\347\256\227\347\216\257\345\242\203\344\273\277\347\234\237\346\274\224\347\244\272\347\263\273\347\273\237", Q_NULLPTR));
        label->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        lineEditName->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_ACCESSIBILITY
        lineEditName->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        lineEditName->setInputMask(QString());
        lineEditName->setPlaceholderText(QApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215...", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginDialog", "\345\257\206   \347\240\201\357\274\232", Q_NULLPTR));
        lineEditPwd->setText(QString());
        lineEditPwd->setPlaceholderText(QString());
        pushButtonLogin->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButtonQuit->setText(QApplication::translate("LoginDialog", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
