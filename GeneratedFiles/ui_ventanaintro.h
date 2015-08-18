/********************************************************************************
** Form generated from reading UI file 'ventanaintro.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAINTRO_H
#define UI_VENTANAINTRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ventanaIntro
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *startButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *confButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *aboutButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *exitButton;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;

    void setupUi(QWidget *ventanaIntro)
    {
        if (ventanaIntro->objectName().isEmpty())
            ventanaIntro->setObjectName(QStringLiteral("ventanaIntro"));
        ventanaIntro->setWindowModality(Qt::NonModal);
        ventanaIntro->resize(685, 471);
        QIcon icon;
        icon.addFile(QStringLiteral(":/pic/Resources/iconos/Theremin.png"), QSize(), QIcon::Normal, QIcon::Off);
        ventanaIntro->setWindowIcon(icon);
        ventanaIntro->setAutoFillBackground(false);
        layoutWidget = new QWidget(ventanaIntro);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 420, 661, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        startButton = new QPushButton(layoutWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        horizontalLayout->addWidget(startButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        confButton = new QPushButton(layoutWidget);
        confButton->setObjectName(QStringLiteral("confButton"));

        horizontalLayout->addWidget(confButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        aboutButton = new QPushButton(layoutWidget);
        aboutButton->setObjectName(QStringLiteral("aboutButton"));

        horizontalLayout->addWidget(aboutButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        exitButton = new QPushButton(layoutWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        horizontalLayout->addWidget(exitButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label = new QLabel(ventanaIntro);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 691, 411));
        label->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/introduccion.png")));
        label->setScaledContents(true);

        retranslateUi(ventanaIntro);
        QObject::connect(exitButton, SIGNAL(clicked()), ventanaIntro, SLOT(close()));

        QMetaObject::connectSlotsByName(ventanaIntro);
    } // setupUi

    void retranslateUi(QWidget *ventanaIntro)
    {
        ventanaIntro->setWindowTitle(QApplication::translate("ventanaIntro", "Theremin", 0));
        startButton->setText(QApplication::translate("ventanaIntro", "Empezar", 0));
        confButton->setText(QApplication::translate("ventanaIntro", "Configuraci\303\263n", 0));
        aboutButton->setText(QApplication::translate("ventanaIntro", "Acerca de", 0));
        exitButton->setText(QApplication::translate("ventanaIntro", "Salir", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ventanaIntro: public Ui_ventanaIntro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAINTRO_H
