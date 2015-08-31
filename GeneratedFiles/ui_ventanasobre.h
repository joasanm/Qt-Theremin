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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitButton;

    void setupUi(QWidget *ventanaSobre)
    {
        if (ventanaSobre->objectName().isEmpty())
            ventanaSobre->setObjectName(QStringLiteral("ventanaSobre"));
        ventanaSobre->resize(589, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ventanaSobre->sizePolicy().hasHeightForWidth());
        ventanaSobre->setSizePolicy(sizePolicy);
        ventanaSobre->setMinimumSize(QSize(589, 300));
        ventanaSobre->setMaximumSize(QSize(589, 300));
        ventanaSobre->setFocusPolicy(Qt::ClickFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/pic/Resources/iconos/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        ventanaSobre->setWindowIcon(icon);
        groupBox = new QGroupBox(ventanaSobre);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 551, 221));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 23, 64, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 291, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 130, 531, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 150, 521, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(460, 20, 81, 61));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/iconos/Theremin.png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 170, 191, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 80, 441, 16));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 100, 311, 16));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 190, 511, 16));
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
        groupBox->setTitle(QApplication::translate("ventanaSobre", "Theremin Digital", 0));
        label->setText(QApplication::translate("ventanaSobre", "Versi\303\263n 1.0.0", 0));
        label_2->setText(QApplication::translate("ventanaSobre", "Theremin Digital es un simulador del instrumento Theremin", 0));
        label_3->setText(QApplication::translate("ventanaSobre", "Programado con el UPV Game Kernel.", 0));
        label_4->setText(QApplication::translate("ventanaSobre", "Copyright 2011 Departamento de Sistemas Inform\303\241ticos y Computaci\303\263n. Todos los derechos reservados.", 0));
        label_5->setText(QString());
        label_6->setText(QApplication::translate("ventanaSobre", "Iconos de la propiedad de Icons DB", 0));
        label_7->setText(QApplication::translate("ventanaSobre", "Programado por Joan Sancho", 0));
        label_8->setText(QApplication::translate("ventanaSobre", "Idea original de Ram\303\263n Pascual Moll\303\241", 0));
        label_9->setText(QApplication::translate("ventanaSobre", "Copyright 2011 Icons DB. Todos los derechos reservados.", 0));
        exitButton->setText(QApplication::translate("ventanaSobre", "Volver", 0));
    } // retranslateUi

};

namespace Ui {
    class ventanaSobre: public Ui_ventanaSobre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANASOBRE_H
