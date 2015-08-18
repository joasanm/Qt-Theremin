#ifndef THEREMIN_H
#define THEREMIN_H

#include <QtWidgets/QMainWindow>
#include "ui_theremin.h"
#include "ventanaconf.h"
#include "ventanasobre.h"

class theremin : public QMainWindow
{
	Q_OBJECT

public:
	explicit theremin(QWidget *parent = 0);
	~theremin();
	Ui::thereminClass ui;
	ventanaSobre* s;

private:
	void createActions();
	int lastPressed;

private slots:
	void soundS();
	void soundQ();
	void soundT();
	void soundD();
	void soundPlay();
	void stopSound();
	void modAfinado();
	void mostrarPiano();
	void vconfig();
	void aboutButton();
	void salir();
	void on_actionPlay_triggered();
	void on_actionStop_triggered();
	void on_actionSinus_triggered();
	void on_actionQuad_triggered();
	void on_actionSaw_triggered();
	void on_actionTriangle_triggered();
};

#endif // THEREMIN_H
