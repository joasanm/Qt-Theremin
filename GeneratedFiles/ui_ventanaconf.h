/********************************************************************************
** Form generated from reading UI file 'ventanaconf.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANACONF_H
#define UI_VENTANACONF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ventanaConf
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *ovalue;
    QSpacerItem *horizontalSpacer_2;
    QSlider *oslider;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *vvalue;
    QSpacerItem *horizontalSpacer;
    QSlider *vslider;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *apliButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ventanaConf)
    {
        if (ventanaConf->objectName().isEmpty())
            ventanaConf->setObjectName(QStringLiteral("ventanaConf"));
        ventanaConf->resize(513, 306);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ventanaConf->sizePolicy().hasHeightForWidth());
        ventanaConf->setSizePolicy(sizePolicy);
        ventanaConf->setMinimumSize(QSize(513, 306));
        ventanaConf->setMaximumSize(QSize(513, 306));
        ventanaConf->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/pic/Resources/iconos/services.png"), QSize(), QIcon::Normal, QIcon::Off);
        ventanaConf->setWindowIcon(icon);
        layoutWidget = new QWidget(ventanaConf);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(22, 22, 471, 271));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        ovalue = new QLabel(groupBox);
        ovalue->setObjectName(QStringLiteral("ovalue"));

        horizontalLayout->addWidget(ovalue);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        oslider = new QSlider(groupBox);
        oslider->setObjectName(QStringLiteral("oslider"));
        oslider->setMinimum(1);
        oslider->setMaximum(8);
        oslider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(oslider);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        vvalue = new QLabel(groupBox);
        vvalue->setObjectName(QStringLiteral("vvalue"));

        horizontalLayout_2->addWidget(vvalue);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        vslider = new QSlider(groupBox);
        vslider->setObjectName(QStringLiteral("vslider"));
        vslider->setMaximum(100);
        vslider->setPageStep(10);
        vslider->setSliderPosition(100);
        vslider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(vslider);


        verticalLayout_3->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        apliButton = new QPushButton(layoutWidget);
        apliButton->setObjectName(QStringLiteral("apliButton"));

        horizontalLayout_3->addWidget(apliButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(ventanaConf);
        QObject::connect(cancelButton, SIGNAL(clicked()), ventanaConf, SLOT(close()));
        QObject::connect(apliButton, SIGNAL(clicked()), ventanaConf, SLOT(accept()));
        QObject::connect(oslider, SIGNAL(valueChanged(int)), ovalue, SLOT(setNum(int)));
        QObject::connect(vslider, SIGNAL(valueChanged(int)), vvalue, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(ventanaConf);
    } // setupUi

    void retranslateUi(QDialog *ventanaConf)
    {
        ventanaConf->setWindowTitle(QApplication::translate("ventanaConf", "Configuraci\303\263n", 0));
        groupBox->setTitle(QApplication::translate("ventanaConf", "Configuraci\303\263n", 0));
        label->setText(QApplication::translate("ventanaConf", "N\303\272mero de octavas: ", 0));
        ovalue->setText(QString());
        label_2->setText(QApplication::translate("ventanaConf", "M\303\241ximo nivel de volumen: ", 0));
        vvalue->setText(QString());
        apliButton->setText(QApplication::translate("ventanaConf", "Aplicar", 0));
        cancelButton->setText(QApplication::translate("ventanaConf", "Cancelar", 0));
    } // retranslateUi

};

namespace Ui {
    class ventanaConf: public Ui_ventanaConf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANACONF_H
