#ifndef VENTANAINTRO_H
#define VENTANAINTRO_H

#include <QWidget>
#include "ui_ventanaintro.h"
#include "theremin.h"
#include "ventanasobre.h"
#include "ventanaconf.h"

class ventanaIntro : public QWidget, public Ui::ventanaIntro
{
	Q_OBJECT

public:
	ventanaIntro(QWidget *parent = 0);
	~ventanaIntro();
	theremin* t;
	//ventanaSobre* s;

private:
	Ui::ventanaIntro ui;
	int vconf;
	int oconf;

private slots:
	void on_startButton_clicked();
	void on_aboutButton_clicked();
	void on_confButton_clicked();

};

#endif // VENTANAINTRO_H
