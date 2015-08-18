/********************************************************************************
** Form generated from reading UI file 'ventanasobre.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANASOBRE_H
#define UI_VENTANASOBRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ventanaSobre
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitButton;

    void setupUi(QWidget *ventanaSobre)
    {
        if (ventanaSobre->objectName().isEmpty())
            ventanaSobre->setObjectName(QStringLiteral("ventanaSobre"));
        ventanaSobre->resize(589, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/pic/Resources/iconos/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        ventanaSobre->setWindowIcon(icon);
        groupBox = new QGroupBox(ventanaSobre);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 551, 221));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        layoutWidget = new QWidget(ventanaSobre);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 260, 551, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        exitButton = new QPushButton(layoutWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        horizontalLayout->addWidget(exitButton);


        retranslateUi(ventanaSobre);
        QObject::connect(exitButton, SIGNAL(clicked()), ventanaSobre, SLOT(close()));

        QMetaObject::connectSlotsByName(ventanaSobre);
    } // setupUi

    void retranslateUi(QWidget *ventanaSobre)
    {
        ventanaSobre->setWindowTitle(QApplication::translate("ventanaSobre", "Acerca de", 0));
        groupBox->setTitle(QApplication::translate("ventanaSobre", "Theremin", 0));
        label->setText(QApplication::translate("ventanaSobre", "Esta aplicaci\303\263n se basa en librer\303\255as dise\303\261adas por el DSIC y QT", 0));
        exitButton->setText(QApplication::translate("ventanaSobre", "Volver", 0));
    } // retranslateUi

};

namespace Ui {
    class ventanaSobre: public Ui_ventanaSobre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANASOBRE_H
