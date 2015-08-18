#ifndef VENTANACONF_H
#define VENTANACONF_H

#include <QDialog>
#include "ui_ventanaconf.h"

class ventanaConf : public QDialog, public Ui::ventanaConf
{
	Q_OBJECT

public:
	ventanaConf(QWidget *parent = 0);
	~ventanaConf();
};

#endif // VENTANACONF_H
