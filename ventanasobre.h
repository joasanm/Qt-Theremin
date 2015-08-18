#ifndef VENTANASOBRE_H
#define VENTANASOBRE_H

#include <QWidget>
#include "ui_ventanasobre.h"

class ventanaSobre : public QWidget, public Ui::ventanaSobre
{
	Q_OBJECT

public:
	ventanaSobre(QWidget *parent = 0);
	~ventanaSobre();
};

#endif // VENTANASOBRE_H
