/********************************************************************************
** Form generated from reading UI file 'theremin.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEREMIN_H
#define UI_THEREMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include "graficos.h"

QT_BEGIN_NAMESPACE

class Ui_thereminClass
{
public:
    QAction *actionPlay;
    QAction *actionStop;
    QAction *actionSinus;
    QAction *actionQuad;
    QAction *actionSaw;
    QAction *actionTriangle;
    graficos *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *thereminClass)
    {
        if (thereminClass->objectName().isEmpty())
            thereminClass->setObjectName(QStringLiteral("thereminClass"));
        thereminClass->resize(632, 454);
        QIcon icon;
        icon.addFile(QStringLiteral(":/pic/Resources/iconos/Theremin.png"), QSize(), QIcon::Normal, QIcon::Off);
        thereminClass->setWindowIcon(icon);
        actionPlay = new QAction(thereminClass);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/pic/Resources/iconos/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon1);
        actionStop = new QAction(thereminClass);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/pic/Resources/iconos/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon2);
        actionSinus = new QAction(thereminClass);
        actionSinus->setObjectName(QStringLiteral("actionSinus"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("Resources/iconos/sine_wave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSinus->setIcon(icon3);
        actionQuad = new QAction(thereminClass);
        actionQuad->setObjectName(QStringLiteral("actionQuad"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/pic/Resources/iconos/Square_wave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuad->setIcon(icon4);
        actionSaw = new QAction(thereminClass);
        actionSaw->setObjectName(QStringLiteral("actionSaw"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/pic/Resources/iconos/Sawtooth_wave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaw->setIcon(icon5);
        actionTriangle = new QAction(thereminClass);
        actionTriangle->setObjectName(QStringLiteral("actionTriangle"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/pic/Resources/iconos/Triangle_wave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTriangle->setIcon(icon6);
        centralWidget = new graficos(thereminClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        thereminClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(thereminClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 632, 21));
        thereminClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(thereminClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        thereminClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(thereminClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        thereminClass->setStatusBar(statusBar);

        mainToolBar->addAction(actionPlay);
        mainToolBar->addAction(actionStop);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSinus);
        mainToolBar->addAction(actionQuad);
        mainToolBar->addAction(actionSaw);
        mainToolBar->addAction(actionTriangle);

        retranslateUi(thereminClass);

        QMetaObject::connectSlotsByName(thereminClass);
    } // setupUi

    void retranslateUi(QMainWindow *thereminClass)
    {
        thereminClass->setWindowTitle(QApplication::translate("thereminClass", "Theremin", 0));
        actionPlay->setText(QApplication::translate("thereminClass", "Play sound", 0));
        actionStop->setText(QApplication::translate("thereminClass", "Stop sound", 0));
        actionSinus->setText(QApplication::translate("thereminClass", "Sinus form", 0));
        actionQuad->setText(QApplication::translate("thereminClass", "Quadratic form", 0));
        actionSaw->setText(QApplication::translate("thereminClass", "Saw tooth form", 0));
        actionTriangle->setText(QApplication::translate("thereminClass", "Triangle form", 0));
    } // retranslateUi

};

namespace Ui {
    class thereminClass: public Ui_thereminClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEREMIN_H
