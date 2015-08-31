#ifndef VENTANASOBRE_H
#define VENTANASOBRE_H

#include <QDialog>
#include "ui_ventanasobre.h"

class ventanaSobre : public QDialog, public Ui::ventanaSobre
{
	Q_OBJECT

public:
	ventanaSobre(QWidget *parent = 0);
	~ventanaSobre();
};

#endif // VENTANASOBRE_H
