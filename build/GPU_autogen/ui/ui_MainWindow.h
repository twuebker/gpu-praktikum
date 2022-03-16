/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *leftLayout;
    QHBoxLayout *toggleLayout;
    QCheckBox *toggleSimulation;
    QCheckBox *toggleFastplace;
    QPushButton *pushButton;
    QPushButton *placeAsteroids;
    QLabel *label;
    QSlider *animationSpeedSlider;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGraphicsView *asteroidsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1448, 867);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 1429, 791));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftLayout = new QVBoxLayout();
        leftLayout->setObjectName(QStringLiteral("leftLayout"));
        leftLayout->setSizeConstraint(QLayout::SetMinimumSize);
        toggleLayout = new QHBoxLayout();
        toggleLayout->setObjectName(QStringLiteral("toggleLayout"));
        toggleSimulation = new QCheckBox(horizontalLayoutWidget);
        toggleSimulation->setObjectName(QStringLiteral("toggleSimulation"));
        toggleSimulation->setMaximumSize(QSize(150, 16777215));

        toggleLayout->addWidget(toggleSimulation);

        toggleFastplace = new QCheckBox(horizontalLayoutWidget);
        toggleFastplace->setObjectName(QStringLiteral("toggleFastplace"));

        toggleLayout->addWidget(toggleFastplace);


        leftLayout->addLayout(toggleLayout);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        leftLayout->addWidget(pushButton);

        placeAsteroids = new QPushButton(horizontalLayoutWidget);
        placeAsteroids->setObjectName(QStringLiteral("placeAsteroids"));

        leftLayout->addWidget(placeAsteroids);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        leftLayout->addWidget(label);

        animationSpeedSlider = new QSlider(horizontalLayoutWidget);
        animationSpeedSlider->setObjectName(QStringLiteral("animationSpeedSlider"));
        animationSpeedSlider->setMinimum(1);
        animationSpeedSlider->setMaximum(1000);
        animationSpeedSlider->setOrientation(Qt::Horizontal);

        leftLayout->addWidget(animationSpeedSlider);

        scrollArea = new QScrollArea(horizontalLayoutWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMaximumSize(QSize(350, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 348, 625));
        scrollArea->setWidget(scrollAreaWidgetContents);

        leftLayout->addWidget(scrollArea);


        horizontalLayout->addLayout(leftLayout);

        asteroidsView = new QGraphicsView(horizontalLayoutWidget);
        asteroidsView->setObjectName(QStringLiteral("asteroidsView"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(asteroidsView->sizePolicy().hasHeightForWidth());
        asteroidsView->setSizePolicy(sizePolicy);
        asteroidsView->setMinimumSize(QSize(1050, 0));
        asteroidsView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout->addWidget(asteroidsView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1448, 37));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        toggleSimulation->setText(QApplication::translate("MainWindow", "Toggle Simulation", Q_NULLPTR));
        toggleFastplace->setText(QApplication::translate("MainWindow", "Toggle FastPlace", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        placeAsteroids->setText(QApplication::translate("MainWindow", "Switch Placing Asteroids / ForceFields", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Interval to run kernel in ms:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
