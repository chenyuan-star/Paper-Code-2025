/********************************************************************************
** Form generated from reading UI file 'SatelliteSim.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SATELLITESIM_H
#define UI_SATELLITESIM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SatelliteSimClass
{
public:
    QAction *actionAbout;
    QAction *actionNew;
    QAction *actionExit;
    QAction *actionStartSim;
    QAction *actionPauseSim;
    QAction *actionStopSim;
    QAction *actionOpenTLEFile;
    QAction *actionOpenCOEFile;
    QAction *actionPlusX;
    QWidget *centralWidget;
    QStatusBar *statusBar;
    QDockWidget *dockWidgetObjects;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonAddFromDB;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *lineEditSearch;
    QPushButton *pushButtonSearch;
    QTreeWidget *treeWidgetObjects;
    QGroupBox *groupBoxPara;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxSemimajorAxis;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxEccentricity;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBoxInclination;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBoxArgumentOfPerigee;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxLongitudeOfTheAscendingNode;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBoxMeanAnomaly;
    QLabel *label_13;
    QGroupBox *groupBoxPos;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBoxPitch;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBoxYaw;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_16;
    QDoubleSpinBox *doubleSpinBoxRoll;
    QLabel *label_21;
    QGroupBox *groupBoxUnderPoint;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelLon;
    QDoubleSpinBox *doubleSpinBoxLon;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_12;
    QLabel *labelLat;
    QDoubleSpinBox *doubleSpinBoxLat;
    QLabel *label_19;
    QGroupBox *groupBoxFixLookaround;
    QGridLayout *gridLayout_4;
    QLabel *label_26;
    QLabel *label_27;
    QDoubleSpinBox *doubleSpinBoxPinLon;
    QDoubleSpinBox *doubleSpinBoxPinLat;
    QLabel *label_24;
    QLabel *label_25;
    QPushButton *pushButtonPinCamera;
    QPushButton *pushButtonResetCamera;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButtonManual;
    QRadioButton *radioButtonRealtime;
    QGroupBox *groupBoxManual;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLabel *label_8;
    QDateEdit *dateEditDate;
    QPushButton *pushButtonSetToCurrent;
    QTimeEdit *timeEditTime;
    QGroupBox *groupBoxAuto;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *comboBoxIntervalTime;
    QComboBox *comboBoxTimeUnit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBoxGraticules;
    QCheckBox *checkBoxInertia;
    QCheckBox *checkBoxAxis;
    QCheckBox *checkBoxLight;
    QCheckBox *checkBoxAutoRotate;
    QSpinBox *spinBoxSpeed;
    QLabel *label_23;
    QSpacerItem *verticalSpacer_2;
    QDockWidget *dockWidgetLog;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout_14;
    QPlainTextEdit *plainTextEditLog;

    void setupUi(QMainWindow *SatelliteSimClass)
    {
        if (SatelliteSimClass->objectName().isEmpty())
            SatelliteSimClass->setObjectName(QStringLiteral("SatelliteSimClass"));
        SatelliteSimClass->resize(1015, 1075);
        actionAbout = new QAction(SatelliteSimClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionNew = new QAction(SatelliteSimClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionExit = new QAction(SatelliteSimClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionStartSim = new QAction(SatelliteSimClass);
        actionStartSim->setObjectName(QStringLiteral("actionStartSim"));
        actionPauseSim = new QAction(SatelliteSimClass);
        actionPauseSim->setObjectName(QStringLiteral("actionPauseSim"));
        actionStopSim = new QAction(SatelliteSimClass);
        actionStopSim->setObjectName(QStringLiteral("actionStopSim"));
        actionOpenTLEFile = new QAction(SatelliteSimClass);
        actionOpenTLEFile->setObjectName(QStringLiteral("actionOpenTLEFile"));
        actionOpenCOEFile = new QAction(SatelliteSimClass);
        actionOpenCOEFile->setObjectName(QStringLiteral("actionOpenCOEFile"));
        actionPlusX = new QAction(SatelliteSimClass);
        actionPlusX->setObjectName(QStringLiteral("actionPlusX"));
        centralWidget = new QWidget(SatelliteSimClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SatelliteSimClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SatelliteSimClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SatelliteSimClass->setStatusBar(statusBar);
        dockWidgetObjects = new QDockWidget(SatelliteSimClass);
        dockWidgetObjects->setObjectName(QStringLiteral("dockWidgetObjects"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(dockWidgetContents);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButtonAdd = new QPushButton(tab);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));

        verticalLayout_3->addWidget(pushButtonAdd);

        pushButtonAddFromDB = new QPushButton(tab);
        pushButtonAddFromDB->setObjectName(QStringLiteral("pushButtonAddFromDB"));

        verticalLayout_3->addWidget(pushButtonAddFromDB);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        lineEditSearch = new QLineEdit(tab);
        lineEditSearch->setObjectName(QStringLiteral("lineEditSearch"));

        horizontalLayout_13->addWidget(lineEditSearch);

        pushButtonSearch = new QPushButton(tab);
        pushButtonSearch->setObjectName(QStringLiteral("pushButtonSearch"));

        horizontalLayout_13->addWidget(pushButtonSearch);


        verticalLayout_3->addLayout(horizontalLayout_13);

        treeWidgetObjects = new QTreeWidget(tab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidgetObjects->setHeaderItem(__qtreewidgetitem);
        treeWidgetObjects->setObjectName(QStringLiteral("treeWidgetObjects"));
        treeWidgetObjects->setMinimumSize(QSize(0, 250));
        treeWidgetObjects->header()->setVisible(false);

        verticalLayout_3->addWidget(treeWidgetObjects);

        groupBoxPara = new QGroupBox(tab);
        groupBoxPara->setObjectName(QStringLiteral("groupBoxPara"));
        verticalLayout_5 = new QVBoxLayout(groupBoxPara);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBoxPara);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        doubleSpinBoxSemimajorAxis = new QDoubleSpinBox(groupBoxPara);
        doubleSpinBoxSemimajorAxis->setObjectName(QStringLiteral("doubleSpinBoxSemimajorAxis"));
        doubleSpinBoxSemimajorAxis->setDecimals(3);
        doubleSpinBoxSemimajorAxis->setMaximum(1e+8);

        horizontalLayout_3->addWidget(doubleSpinBoxSemimajorAxis);

        label_9 = new QLabel(groupBoxPara);
        label_9->setObjectName(QStringLiteral("label_9"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(30, 0));

        horizontalLayout_3->addWidget(label_9);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBoxPara);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        doubleSpinBoxEccentricity = new QDoubleSpinBox(groupBoxPara);
        doubleSpinBoxEccentricity->setObjectName(QStringLiteral("doubleSpinBoxEccentricity"));
        doubleSpinBoxEccentricity->setDecimals(7);
        doubleSpinBoxEccentricity->setMaximum(0.999);
        doubleSpinBoxEccentricity->setSingleStep(0.01);

        horizontalLayout_4->addWidget(doubleSpinBoxEccentricity);

        label_14 = new QLabel(groupBoxPara);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);
        label_14->setMinimumSize(QSize(30, 0));

        horizontalLayout_4->addWidget(label_14);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBoxPara);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        doubleSpinBoxInclination = new QDoubleSpinBox(groupBoxPara);
        doubleSpinBoxInclination->setObjectName(QStringLiteral("doubleSpinBoxInclination"));
        doubleSpinBoxInclination->setDecimals(4);
        doubleSpinBoxInclination->setMaximum(180);

        horizontalLayout_2->addWidget(doubleSpinBoxInclination);

        label_10 = new QLabel(groupBoxPara);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(30, 0));

        horizontalLayout_2->addWidget(label_10);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(groupBoxPara);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        doubleSpinBoxArgumentOfPerigee = new QDoubleSpinBox(groupBoxPara);
        doubleSpinBoxArgumentOfPerigee->setObjectName(QStringLiteral("doubleSpinBoxArgumentOfPerigee"));
        doubleSpinBoxArgumentOfPerigee->setDecimals(4);
        doubleSpinBoxArgumentOfPerigee->setMaximum(360);

        horizontalLayout_5->addWidget(doubleSpinBoxArgumentOfPerigee);

        label_11 = new QLabel(groupBoxPara);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(30, 0));

        horizontalLayout_5->addWidget(label_11);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBoxPara);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        doubleSpinBoxLongitudeOfTheAscendingNode = new QDoubleSpinBox(groupBoxPara);
        doubleSpinBoxLongitudeOfTheAscendingNode->setObjectName(QStringLiteral("doubleSpinBoxLongitudeOfTheAscendingNode"));
        doubleSpinBoxLongitudeOfTheAscendingNode->setDecimals(4);
        doubleSpinBoxLongitudeOfTheAscendingNode->setMaximum(360);

        horizontalLayout->addWidget(doubleSpinBoxLongitudeOfTheAscendingNode);

        label_12 = new QLabel(groupBoxPara);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMinimumSize(QSize(30, 0));

        horizontalLayout->addWidget(label_12);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(groupBoxPara);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        doubleSpinBoxMeanAnomaly = new QDoubleSpinBox(groupBoxPara);
        doubleSpinBoxMeanAnomaly->setObjectName(QStringLiteral("doubleSpinBoxMeanAnomaly"));
        doubleSpinBoxMeanAnomaly->setDecimals(6);
        doubleSpinBoxMeanAnomaly->setMaximum(360);

        horizontalLayout_6->addWidget(doubleSpinBoxMeanAnomaly);

        label_13 = new QLabel(groupBoxPara);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setMinimumSize(QSize(30, 0));

        horizontalLayout_6->addWidget(label_13);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_5->addLayout(verticalLayout_2);


        verticalLayout_3->addWidget(groupBoxPara);

        groupBoxPos = new QGroupBox(tab);
        groupBoxPos->setObjectName(QStringLiteral("groupBoxPos"));
        verticalLayout_6 = new QVBoxLayout(groupBoxPos);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_17 = new QLabel(groupBoxPos);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_10->addWidget(label_17);

        doubleSpinBoxPitch = new QDoubleSpinBox(groupBoxPos);
        doubleSpinBoxPitch->setObjectName(QStringLiteral("doubleSpinBoxPitch"));

        horizontalLayout_10->addWidget(doubleSpinBoxPitch);

        label_22 = new QLabel(groupBoxPos);
        label_22->setObjectName(QStringLiteral("label_22"));
        sizePolicy.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(label_22);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_15 = new QLabel(groupBoxPos);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_8->addWidget(label_15);

        doubleSpinBoxYaw = new QDoubleSpinBox(groupBoxPos);
        doubleSpinBoxYaw->setObjectName(QStringLiteral("doubleSpinBoxYaw"));

        horizontalLayout_8->addWidget(doubleSpinBoxYaw);

        label_20 = new QLabel(groupBoxPos);
        label_20->setObjectName(QStringLiteral("label_20"));
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(label_20);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_16 = new QLabel(groupBoxPos);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_9->addWidget(label_16);

        doubleSpinBoxRoll = new QDoubleSpinBox(groupBoxPos);
        doubleSpinBoxRoll->setObjectName(QStringLiteral("doubleSpinBoxRoll"));

        horizontalLayout_9->addWidget(doubleSpinBoxRoll);

        label_21 = new QLabel(groupBoxPos);
        label_21->setObjectName(QStringLiteral("label_21"));
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(label_21);


        verticalLayout_6->addLayout(horizontalLayout_9);


        verticalLayout_3->addWidget(groupBoxPos);

        groupBoxUnderPoint = new QGroupBox(tab);
        groupBoxUnderPoint->setObjectName(QStringLiteral("groupBoxUnderPoint"));
        verticalLayout_7 = new QVBoxLayout(groupBoxUnderPoint);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        labelLon = new QLabel(groupBoxUnderPoint);
        labelLon->setObjectName(QStringLiteral("labelLon"));

        horizontalLayout_11->addWidget(labelLon);

        doubleSpinBoxLon = new QDoubleSpinBox(groupBoxUnderPoint);
        doubleSpinBoxLon->setObjectName(QStringLiteral("doubleSpinBoxLon"));
        doubleSpinBoxLon->setMinimum(-180);
        doubleSpinBoxLon->setMaximum(180);

        horizontalLayout_11->addWidget(doubleSpinBoxLon);

        label_18 = new QLabel(groupBoxUnderPoint);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);

        horizontalLayout_11->addWidget(label_18);


        verticalLayout_7->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        labelLat = new QLabel(groupBoxUnderPoint);
        labelLat->setObjectName(QStringLiteral("labelLat"));

        horizontalLayout_12->addWidget(labelLat);

        doubleSpinBoxLat = new QDoubleSpinBox(groupBoxUnderPoint);
        doubleSpinBoxLat->setObjectName(QStringLiteral("doubleSpinBoxLat"));
        doubleSpinBoxLat->setMinimum(-180);
        doubleSpinBoxLat->setMaximum(180);

        horizontalLayout_12->addWidget(doubleSpinBoxLat);

        label_19 = new QLabel(groupBoxUnderPoint);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(label_19);


        verticalLayout_7->addLayout(horizontalLayout_12);


        verticalLayout_3->addWidget(groupBoxUnderPoint);

        groupBoxFixLookaround = new QGroupBox(tab);
        groupBoxFixLookaround->setObjectName(QStringLiteral("groupBoxFixLookaround"));
        gridLayout_4 = new QGridLayout(groupBoxFixLookaround);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_26 = new QLabel(groupBoxFixLookaround);
        label_26->setObjectName(QStringLiteral("label_26"));
        sizePolicy.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(label_26, 0, 2, 1, 1);

        label_27 = new QLabel(groupBoxFixLookaround);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_4->addWidget(label_27, 1, 2, 1, 1);

        doubleSpinBoxPinLon = new QDoubleSpinBox(groupBoxFixLookaround);
        doubleSpinBoxPinLon->setObjectName(QStringLiteral("doubleSpinBoxPinLon"));
        doubleSpinBoxPinLon->setMinimum(-180);
        doubleSpinBoxPinLon->setMaximum(180);

        gridLayout_4->addWidget(doubleSpinBoxPinLon, 0, 1, 1, 1);

        doubleSpinBoxPinLat = new QDoubleSpinBox(groupBoxFixLookaround);
        doubleSpinBoxPinLat->setObjectName(QStringLiteral("doubleSpinBoxPinLat"));
        doubleSpinBoxPinLat->setMinimum(-90);
        doubleSpinBoxPinLat->setMaximum(90);
        doubleSpinBoxPinLat->setSingleStep(1);

        gridLayout_4->addWidget(doubleSpinBoxPinLat, 1, 1, 1, 1);

        label_24 = new QLabel(groupBoxFixLookaround);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_4->addWidget(label_24, 0, 0, 1, 1);

        label_25 = new QLabel(groupBoxFixLookaround);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_4->addWidget(label_25, 1, 0, 1, 1);

        pushButtonPinCamera = new QPushButton(groupBoxFixLookaround);
        pushButtonPinCamera->setObjectName(QStringLiteral("pushButtonPinCamera"));

        gridLayout_4->addWidget(pushButtonPinCamera, 2, 0, 1, 1);

        pushButtonResetCamera = new QPushButton(groupBoxFixLookaround);
        pushButtonResetCamera->setObjectName(QStringLiteral("pushButtonResetCamera"));

        gridLayout_4->addWidget(pushButtonResetCamera, 2, 1, 1, 1);


        verticalLayout_3->addWidget(groupBoxFixLookaround);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        radioButtonManual = new QRadioButton(groupBox_3);
        radioButtonManual->setObjectName(QStringLiteral("radioButtonManual"));

        gridLayout_3->addWidget(radioButtonManual, 1, 0, 1, 1);

        radioButtonRealtime = new QRadioButton(groupBox_3);
        radioButtonRealtime->setObjectName(QStringLiteral("radioButtonRealtime"));
        radioButtonRealtime->setChecked(true);

        gridLayout_3->addWidget(radioButtonRealtime, 0, 0, 1, 1);

        groupBoxManual = new QGroupBox(groupBox_3);
        groupBoxManual->setObjectName(QStringLiteral("groupBoxManual"));
        gridLayout = new QGridLayout(groupBoxManual);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_7 = new QLabel(groupBoxManual);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        label_8 = new QLabel(groupBoxManual);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        dateEditDate = new QDateEdit(groupBoxManual);
        dateEditDate->setObjectName(QStringLiteral("dateEditDate"));

        gridLayout->addWidget(dateEditDate, 0, 1, 1, 1);

        pushButtonSetToCurrent = new QPushButton(groupBoxManual);
        pushButtonSetToCurrent->setObjectName(QStringLiteral("pushButtonSetToCurrent"));

        gridLayout->addWidget(pushButtonSetToCurrent, 2, 0, 1, 2);

        timeEditTime = new QTimeEdit(groupBoxManual);
        timeEditTime->setObjectName(QStringLiteral("timeEditTime"));
        timeEditTime->setCurrentSection(QDateTimeEdit::HourSection);

        gridLayout->addWidget(timeEditTime, 1, 1, 1, 1);


        gridLayout_3->addWidget(groupBoxManual, 3, 0, 1, 1);

        groupBoxAuto = new QGroupBox(groupBox_3);
        groupBoxAuto->setObjectName(QStringLiteral("groupBoxAuto"));
        horizontalLayout_7 = new QHBoxLayout(groupBoxAuto);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        comboBoxIntervalTime = new QComboBox(groupBoxAuto);
        comboBoxIntervalTime->setObjectName(QStringLiteral("comboBoxIntervalTime"));

        horizontalLayout_7->addWidget(comboBoxIntervalTime);

        comboBoxTimeUnit = new QComboBox(groupBoxAuto);
        comboBoxTimeUnit->setObjectName(QStringLiteral("comboBoxTimeUnit"));

        horizontalLayout_7->addWidget(comboBoxTimeUnit);


        gridLayout_3->addWidget(groupBoxAuto, 2, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        checkBoxGraticules = new QCheckBox(groupBox_2);
        checkBoxGraticules->setObjectName(QStringLiteral("checkBoxGraticules"));
        checkBoxGraticules->setChecked(false);

        gridLayout_2->addWidget(checkBoxGraticules, 1, 0, 1, 1);

        checkBoxInertia = new QCheckBox(groupBox_2);
        checkBoxInertia->setObjectName(QStringLiteral("checkBoxInertia"));
        checkBoxInertia->setChecked(true);

        gridLayout_2->addWidget(checkBoxInertia, 0, 0, 1, 1);

        checkBoxAxis = new QCheckBox(groupBox_2);
        checkBoxAxis->setObjectName(QStringLiteral("checkBoxAxis"));
        checkBoxAxis->setChecked(true);

        gridLayout_2->addWidget(checkBoxAxis, 3, 0, 1, 1);

        checkBoxLight = new QCheckBox(groupBox_2);
        checkBoxLight->setObjectName(QStringLiteral("checkBoxLight"));
        checkBoxLight->setChecked(true);

        gridLayout_2->addWidget(checkBoxLight, 2, 0, 1, 1);

        checkBoxAutoRotate = new QCheckBox(groupBox_2);
        checkBoxAutoRotate->setObjectName(QStringLiteral("checkBoxAutoRotate"));

        gridLayout_2->addWidget(checkBoxAutoRotate, 4, 0, 1, 1);

        spinBoxSpeed = new QSpinBox(groupBox_2);
        spinBoxSpeed->setObjectName(QStringLiteral("spinBoxSpeed"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBoxSpeed->sizePolicy().hasHeightForWidth());
        spinBoxSpeed->setSizePolicy(sizePolicy1);
        spinBoxSpeed->setMinimum(1);
        spinBoxSpeed->setMaximum(3600);
        spinBoxSpeed->setValue(10);

        gridLayout_2->addWidget(spinBoxSpeed, 4, 2, 1, 1);

        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_23, 4, 1, 1, 1);


        verticalLayout_4->addWidget(groupBox_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        dockWidgetObjects->setWidget(dockWidgetContents);
        SatelliteSimClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetObjects);
        dockWidgetLog = new QDockWidget(SatelliteSimClass);
        dockWidgetLog->setObjectName(QStringLiteral("dockWidgetLog"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        horizontalLayout_14 = new QHBoxLayout(dockWidgetContents_2);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        plainTextEditLog = new QPlainTextEdit(dockWidgetContents_2);
        plainTextEditLog->setObjectName(QStringLiteral("plainTextEditLog"));
        plainTextEditLog->setStyleSheet(QLatin1String("background-color: rgb(48, 48, 48);\n"
"color: rgb(214, 214, 214);"));

        horizontalLayout_14->addWidget(plainTextEditLog);

        dockWidgetLog->setWidget(dockWidgetContents_2);
        SatelliteSimClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidgetLog);

        retranslateUi(SatelliteSimClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SatelliteSimClass);
    } // setupUi

    void retranslateUi(QMainWindow *SatelliteSimClass)
    {
        SatelliteSimClass->setWindowTitle(QApplication::translate("SatelliteSimClass", "\345\244\251\345\237\272\351\200\232\347\224\250\350\256\241\347\256\227\347\216\257\345\242\203\344\273\277\347\234\237\346\274\224\347\244\272\347\263\273\347\273\237", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("SatelliteSimClass", "\345\205\263\344\272\216", Q_NULLPTR));
        actionNew->setText(QApplication::translate("SatelliteSimClass", "\346\226\260\345\273\272", Q_NULLPTR));
        actionExit->setText(QApplication::translate("SatelliteSimClass", "\351\200\200\345\207\272", Q_NULLPTR));
        actionStartSim->setText(QApplication::translate("SatelliteSimClass", "\345\274\200\345\247\213\344\273\277\347\234\237", Q_NULLPTR));
        actionPauseSim->setText(QApplication::translate("SatelliteSimClass", "\346\232\202\345\201\234\344\273\277\347\234\237", Q_NULLPTR));
        actionStopSim->setText(QApplication::translate("SatelliteSimClass", "\346\201\242\345\244\215\344\273\277\347\234\237", Q_NULLPTR));
        actionOpenTLEFile->setText(QApplication::translate("SatelliteSimClass", "\346\211\223\345\274\200TLE\346\226\207\344\273\266", Q_NULLPTR));
        actionOpenCOEFile->setText(QApplication::translate("SatelliteSimClass", "\346\211\223\345\274\200COE\346\226\207\344\273\266", Q_NULLPTR));
        actionPlusX->setText(QApplication::translate("SatelliteSimClass", "PlusX", Q_NULLPTR));
        dockWidgetObjects->setWindowTitle(QApplication::translate("SatelliteSimClass", "\350\247\206\345\233\276", Q_NULLPTR));
        pushButtonAdd->setText(QApplication::translate("SatelliteSimClass", "\346\267\273\345\212\240\345\215\253\346\230\237", Q_NULLPTR));
        pushButtonAddFromDB->setText(QApplication::translate("SatelliteSimClass", "\344\273\216\346\225\260\346\215\256\345\272\223\346\267\273\345\212\240", Q_NULLPTR));
        lineEditSearch->setPlaceholderText(QApplication::translate("SatelliteSimClass", "\350\257\267\350\276\223\345\205\245\346\220\234\347\264\242\345\205\263\351\224\256\350\257\215", Q_NULLPTR));
        pushButtonSearch->setText(QApplication::translate("SatelliteSimClass", "\346\220\234\347\264\242", Q_NULLPTR));
        groupBoxPara->setTitle(QApplication::translate("SatelliteSimClass", "\345\217\202\346\225\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("SatelliteSimClass", "\351\225\277\345\215\212\350\275\264(a)\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("SatelliteSimClass", "(km)", Q_NULLPTR));
        label_4->setText(QApplication::translate("SatelliteSimClass", "\345\201\217\345\277\203\347\216\207(e)\357\274\232", Q_NULLPTR));
        label_14->setText(QString());
        label_2->setText(QApplication::translate("SatelliteSimClass", "\350\275\250\351\201\223\345\200\276\350\247\222(i)\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("SatelliteSimClass", "(\345\272\246)", Q_NULLPTR));
        label_5->setText(QApplication::translate("SatelliteSimClass", "\350\277\221\345\234\260\347\202\271\345\271\205\350\247\222(\317\211)\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("SatelliteSimClass", "(\345\272\246)", Q_NULLPTR));
        label->setText(QApplication::translate("SatelliteSimClass", "\345\215\207\344\272\244\347\202\271\350\265\244\347\273\217(\316\251)\357\274\232", Q_NULLPTR));
        label_12->setText(QApplication::translate("SatelliteSimClass", "(\345\272\246)", Q_NULLPTR));
        label_6->setText(QApplication::translate("SatelliteSimClass", "\345\271\263\350\277\221\347\202\271\350\247\222(M)\357\274\232", Q_NULLPTR));
        label_13->setText(QApplication::translate("SatelliteSimClass", "(\345\272\246)", Q_NULLPTR));
        groupBoxPos->setTitle(QApplication::translate("SatelliteSimClass", "\345\247\277\346\200\201", Q_NULLPTR));
        label_17->setText(QApplication::translate("SatelliteSimClass", "\344\277\257\344\273\260\350\247\222\357\274\232", Q_NULLPTR));
        label_22->setText(QApplication::translate("SatelliteSimClass", "(\345\272\246)", Q_NULLPTR));
        label_15->setText(QApplication::translate("SatelliteSimClass", "\345\201\217\350\210\252\350\247\222\357\274\232", Q_NULLPTR));
        label_20->setText(QApplication::translate("SatelliteSimClass", "(\345\272\246)", Q_NULLPTR));
        label_16->setText(QApplication::translate("SatelliteSimClass", "\347\277\273\346\273\232\350\247\222\357\274\232", Q_NULLPTR));
        label_21->setText(QApplication::translate("SatelliteSimClass", "(\345\272\246)", Q_NULLPTR));
        groupBoxUnderPoint->setTitle(QApplication::translate("SatelliteSimClass", "\346\230\237\344\270\213\347\202\271", Q_NULLPTR));
        labelLon->setText(QApplication::translate("SatelliteSimClass", "\347\273\217\345\272\246\357\274\232", Q_NULLPTR));
        label_18->setText(QApplication::translate("SatelliteSimClass", "(\345\272\246)", Q_NULLPTR));
        labelLat->setText(QApplication::translate("SatelliteSimClass", "\347\272\254\345\272\246\357\274\232", Q_NULLPTR));
        label_19->setText(QApplication::translate("SatelliteSimClass", "(\345\272\246)", Q_NULLPTR));
        groupBoxFixLookaround->setTitle(QApplication::translate("SatelliteSimClass", "\345\256\232\347\202\271\347\216\257\350\247\206", Q_NULLPTR));
        label_26->setText(QApplication::translate("SatelliteSimClass", "(\345\272\246)", Q_NULLPTR));
        label_27->setText(QApplication::translate("SatelliteSimClass", "(\345\272\246)", Q_NULLPTR));
        label_24->setText(QApplication::translate("SatelliteSimClass", "\347\273\217\345\272\246:", Q_NULLPTR));
        label_25->setText(QApplication::translate("SatelliteSimClass", "\347\272\254\345\272\246:", Q_NULLPTR));
        pushButtonPinCamera->setText(QApplication::translate("SatelliteSimClass", "\345\274\200\345\247\213\347\216\257\350\247\206", Q_NULLPTR));
        pushButtonResetCamera->setText(QApplication::translate("SatelliteSimClass", "\347\273\223\346\235\237\347\216\257\350\247\206", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SatelliteSimClass", "\345\215\253\346\230\237", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("SatelliteSimClass", "\346\250\241\345\274\217", Q_NULLPTR));
        radioButtonManual->setText(QApplication::translate("SatelliteSimClass", "\346\211\213\345\212\250", Q_NULLPTR));
        radioButtonRealtime->setText(QApplication::translate("SatelliteSimClass", "\350\207\252\345\212\250", Q_NULLPTR));
        groupBoxManual->setTitle(QApplication::translate("SatelliteSimClass", "\346\211\213\345\212\250", Q_NULLPTR));
        label_7->setText(QApplication::translate("SatelliteSimClass", "\346\227\245\346\234\237:", Q_NULLPTR));
        label_8->setText(QApplication::translate("SatelliteSimClass", "\346\227\266\351\227\264:", Q_NULLPTR));
        dateEditDate->setDisplayFormat(QApplication::translate("SatelliteSimClass", "yyyy-M-d", Q_NULLPTR));
        pushButtonSetToCurrent->setText(QApplication::translate("SatelliteSimClass", "\350\256\276\347\275\256\344\270\272\345\275\223\345\211\215", Q_NULLPTR));
        timeEditTime->setDisplayFormat(QApplication::translate("SatelliteSimClass", "h:m:s", Q_NULLPTR));
        groupBoxAuto->setTitle(QApplication::translate("SatelliteSimClass", "\350\207\252\345\212\250", Q_NULLPTR));
        comboBoxIntervalTime->clear();
        comboBoxIntervalTime->insertItems(0, QStringList()
         << QApplication::translate("SatelliteSimClass", "1", Q_NULLPTR)
         << QApplication::translate("SatelliteSimClass", "5", Q_NULLPTR)
         << QApplication::translate("SatelliteSimClass", "10", Q_NULLPTR)
         << QApplication::translate("SatelliteSimClass", "20", Q_NULLPTR)
         << QApplication::translate("SatelliteSimClass", "30", Q_NULLPTR)
         << QApplication::translate("SatelliteSimClass", "60", Q_NULLPTR)
        );
        comboBoxIntervalTime->setCurrentText(QApplication::translate("SatelliteSimClass", "1", Q_NULLPTR));
        comboBoxTimeUnit->clear();
        comboBoxTimeUnit->insertItems(0, QStringList()
         << QApplication::translate("SatelliteSimClass", "seconds", Q_NULLPTR)
         << QApplication::translate("SatelliteSimClass", "minutes", Q_NULLPTR)
         << QApplication::translate("SatelliteSimClass", "hours", Q_NULLPTR)
        );
        comboBoxTimeUnit->setCurrentText(QApplication::translate("SatelliteSimClass", "seconds", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("SatelliteSimClass", "\345\205\266\344\273\226", Q_NULLPTR));
        checkBoxGraticules->setText(QApplication::translate("SatelliteSimClass", "\346\230\276\347\244\272\347\273\217\347\272\254\347\275\221", Q_NULLPTR));
        checkBoxInertia->setText(QApplication::translate("SatelliteSimClass", "\345\220\257\347\224\250\346\203\257\346\200\247", Q_NULLPTR));
        checkBoxAxis->setText(QApplication::translate("SatelliteSimClass", "\346\230\276\347\244\272\345\235\220\346\240\207\350\275\264", Q_NULLPTR));
        checkBoxLight->setText(QApplication::translate("SatelliteSimClass", "\345\220\257\345\212\250\347\201\257\345\205\211", Q_NULLPTR));
        checkBoxAutoRotate->setText(QApplication::translate("SatelliteSimClass", "\345\220\257\347\224\250\350\207\252\350\275\254", Q_NULLPTR));
        label_23->setText(QApplication::translate("SatelliteSimClass", "\351\200\237\345\272\246:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SatelliteSimClass", "\350\256\276\347\275\256", Q_NULLPTR));
        dockWidgetLog->setWindowTitle(QApplication::translate("SatelliteSimClass", "\346\227\245\345\277\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SatelliteSimClass: public Ui_SatelliteSimClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SATELLITESIM_H
