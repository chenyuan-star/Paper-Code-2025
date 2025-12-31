/********************************************************************************
** Form generated from reading UI file 'SaveSelectionFieldWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVESELECTIONFIELDWIDGET_H
#define UI_SAVESELECTIONFIELDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaveSelectionFieldWidget
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_submit;
    QPushButton *pushButton_cancel;
    QTabWidget *imageWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_showImage;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_saveFormat;
    QLineEdit *lineEdit_saveRoute;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_taskName;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_surfRoute;
    QTextBrowser *textBrowser_coordinateList;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;

    void setupUi(QWidget *SaveSelectionFieldWidget)
    {
        if (SaveSelectionFieldWidget->objectName().isEmpty())
            SaveSelectionFieldWidget->setObjectName(QStringLiteral("SaveSelectionFieldWidget"));
        SaveSelectionFieldWidget->resize(485, 588);
        SaveSelectionFieldWidget->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(SaveSelectionFieldWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(280, 550, 201, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_submit = new QPushButton(layoutWidget);
        pushButton_submit->setObjectName(QStringLiteral("pushButton_submit"));

        horizontalLayout->addWidget(pushButton_submit);

        pushButton_cancel = new QPushButton(layoutWidget);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);

        imageWidget = new QTabWidget(SaveSelectionFieldWidget);
        imageWidget->setObjectName(QStringLiteral("imageWidget"));
        imageWidget->setGeometry(QRect(0, 10, 481, 541));
        imageWidget->setStyleSheet(QStringLiteral(""));
        imageWidget->setTabPosition(QTabWidget::North);
        imageWidget->setTabShape(QTabWidget::Rounded);
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_showImage = new QLabel(widget);
        label_showImage->setObjectName(QStringLiteral("label_showImage"));
        label_showImage->setLayoutDirection(Qt::LeftToRight);
        label_showImage->setStyleSheet(QStringLiteral(""));
        label_showImage->setAlignment(Qt::AlignCenter);
        label_showImage->setWordWrap(false);

        verticalLayout->addWidget(label_showImage);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_saveFormat = new QLineEdit(widget);
        lineEdit_saveFormat->setObjectName(QStringLiteral("lineEdit_saveFormat"));

        gridLayout->addWidget(lineEdit_saveFormat, 2, 1, 1, 1);

        lineEdit_saveRoute = new QLineEdit(widget);
        lineEdit_saveRoute->setObjectName(QStringLiteral("lineEdit_saveRoute"));

        gridLayout->addWidget(lineEdit_saveRoute, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3->setWordWrap(false);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2->setWordWrap(false);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_taskName = new QLineEdit(widget);
        lineEdit_taskName->setObjectName(QStringLiteral("lineEdit_taskName"));

        gridLayout->addWidget(lineEdit_taskName, 0, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4->setWordWrap(false);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5->setWordWrap(false);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        pushButton_surfRoute = new QPushButton(widget);
        pushButton_surfRoute->setObjectName(QStringLiteral("pushButton_surfRoute"));
        pushButton_surfRoute->setMinimumSize(QSize(50, 0));

        gridLayout->addWidget(pushButton_surfRoute, 1, 2, 1, 1);

        textBrowser_coordinateList = new QTextBrowser(widget);
        textBrowser_coordinateList->setObjectName(QStringLiteral("textBrowser_coordinateList"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser_coordinateList->sizePolicy().hasHeightForWidth());
        textBrowser_coordinateList->setSizePolicy(sizePolicy);

        gridLayout->addWidget(textBrowser_coordinateList, 4, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_3->addLayout(verticalLayout);

        imageWidget->addTab(widget, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        imageWidget->addTab(tab_2, QString());

        retranslateUi(SaveSelectionFieldWidget);

        imageWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SaveSelectionFieldWidget);
    } // setupUi

    void retranslateUi(QWidget *SaveSelectionFieldWidget)
    {
        SaveSelectionFieldWidget->setWindowTitle(QApplication::translate("SaveSelectionFieldWidget", "SaveSelectionFieldWidget", Q_NULLPTR));
        pushButton_submit->setText(QApplication::translate("SaveSelectionFieldWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("SaveSelectionFieldWidget", "\345\205\263\351\227\255", Q_NULLPTR));
        label_showImage->setText(QApplication::translate("SaveSelectionFieldWidget", "\345\233\276\345\203\217", Q_NULLPTR));
        label_3->setText(QApplication::translate("SaveSelectionFieldWidget", "\344\277\235\345\255\230\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("SaveSelectionFieldWidget", "\344\273\273\345\212\241\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("SaveSelectionFieldWidget", "\345\255\230\345\202\250\346\240\274\345\274\217\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("SaveSelectionFieldWidget", "\345\235\220\346\240\207\345\272\217\345\210\227\357\274\232", Q_NULLPTR));
        pushButton_surfRoute->setText(QApplication::translate("SaveSelectionFieldWidget", "\346\265\217\350\247\210", Q_NULLPTR));
        imageWidget->setTabText(imageWidget->indexOf(widget), QApplication::translate("SaveSelectionFieldWidget", "\345\275\261\345\203\217", Q_NULLPTR));
        imageWidget->setTabText(imageWidget->indexOf(tab_2), QApplication::translate("SaveSelectionFieldWidget", "\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SaveSelectionFieldWidget: public Ui_SaveSelectionFieldWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVESELECTIONFIELDWIDGET_H
