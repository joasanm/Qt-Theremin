#include "theremin.h"

#include <QtWidgets>

//creador de la ventana
theremin::theremin(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	createActions();
}

theremin::~theremin()
{
	//delete ui;
}

//creador de la barra de menu
void theremin::createActions(){
	QAction *a1;
	QMenu *m;
	QIcon icon;
	QIcon icon2;
	QIcon icon3;
	QIcon icon4;

	m = ui.menuBar->addMenu("Menu");

	a1 = new QAction(tr("Activar sonido"),this);
    icon.addFile(QStringLiteral(":/pic/Resources/iconos/play.png"), QSize(), QIcon::Normal, QIcon::Off);
    a1->setIcon(icon);
	a1->setShortcut(tr("Space"));
	connect(a1,SIGNAL(triggered()),this,SLOT(soundPlay()));
	m->addAction(a1);

	a1 = new QAction(tr("Detener sonido"),this);
	icon.addFile(QStringLiteral(":/pic/Resources/iconos/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
    a1->setIcon(icon);
	a1->setShortcut(tr("M"));
	connect(a1,SIGNAL(triggered()),this,SLOT(stopSound()));
	m->addAction(a1);

	m->addSeparator();

	a1 = new QAction(tr("Modo afinado"),this);
	icon2.addFile(QStringLiteral(":/pic/Resources/iconos/tune.png"), QSize(), QIcon::Normal, QIcon::Off);
    a1->setIcon(icon2);
	a1->setShortcut(tr("A"));
	connect(a1,SIGNAL(triggered()),this,SLOT(modAfinado()));
	m->addAction(a1);

	a1 = new QAction(tr("Mostrar piano"),this);
	icon.addFile(QStringLiteral(":/pic/Resources/iconos/Piano.png"), QSize(), QIcon::Normal, QIcon::Off);
    a1->setIcon(icon);
	a1->setShortcut(tr("H"));
	connect(a1,SIGNAL(triggered()),this,SLOT(mostrarPiano()));
	m->addAction(a1);

	m->addSeparator();

	a1 = new QAction(tr("Configuraci\303\263n"),this);
	icon3.addFile(QStringLiteral(":/pic/Resources/iconos/services.png"), QSize(), QIcon::Normal, QIcon::Off);
    a1->setIcon(icon3);
	connect(a1,SIGNAL(triggered()),this,SLOT(vconfig()));
	m->addAction(a1);

	m->addSeparator();

	a1 = new QAction(tr("Salir"),this);
	icon4.addFile(QStringLiteral(":/pic/Resources/iconos/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
    a1->setIcon(icon4);
	a1->setShortcut(tr("Esc"));
	connect(a1,SIGNAL(triggered()),this,SLOT(salir()));
	m->addAction(a1);

	ui.menuBar->addMenu(m);

	m = ui.menuBar->addMenu("Audio");

	a1 = new QAction(tr("Onda sinusoidal"),this);
	icon.addFile(QStringLiteral(":/pic/Resources/iconos/sine_wave.png"), QSize(), QIcon::Normal, QIcon::Off);
    a1->setIcon(icon);
	a1->setShortcut(tr("S"));
	connect(a1,SIGNAL(triggered()),this,SLOT(soundS()));
	m->addAction(a1);

	a1 = new QAction(tr("Onda cuadrada"),this);
	icon.addFile(QStringLiteral(":/pic/Resources/iconos/Square_wave.png"), QSize(), QIcon::Normal, QIcon::Off);
    a1->setIcon(icon);
	a1->setShortcut(tr("Q"));
	connect(a1,SIGNAL(triggered()),this,SLOT(soundQ()));
	m->addAction(a1);

	a1 = new QAction(tr("Onda dientes sierra"),this);
	icon.addFile(QStringLiteral(":/pic/Resources/iconos/Sawtooth_wave.png"), QSize(), QIcon::Normal, QIcon::Off);
    a1->setIcon(icon);
	a1->setShortcut(tr("D"));
	connect(a1,SIGNAL(triggered()),this,SLOT(soundD()));
	m->addAction(a1);

	a1 = new QAction(tr("Onda triangular"),this);
	icon.addFile(QStringLiteral(":/pic/Resources/iconos/Triangle_wave.png"), QSize(), QIcon::Normal, QIcon::Off);
    a1->setIcon(icon);
	a1->setShortcut(tr("T"));
	connect(a1,SIGNAL(triggered()),this,SLOT(soundT()));
	m->addAction(a1);

	ui.menuBar->addMenu(m);

	m = ui.menuBar->addMenu("Ayuda");

	a1 = new QAction(tr("Acerca de"),this);
	icon4.addFile(QStringLiteral(":/pic/Resources/iconos/info.png"), QSize(), QIcon::Normal, QIcon::Off);
    a1->setIcon(icon4);
	connect(a1,SIGNAL(triggered()),this,SLOT(aboutButton()));
	m->addAction(a1);

	ui.menuBar->addMenu(m);

	setMenuBar(ui.menuBar);
}

//funciones que activan el sonido

void theremin::soundS(){
	stopSound();
	ui.centralWidget->sonido.activeDSPSound('s');
	lastPressed=0;
}

void theremin::soundQ(){
	stopSound();
	ui.centralWidget->sonido.activeDSPSound('q');
	lastPressed=1;
}

void theremin::soundD(){
	stopSound();
	ui.centralWidget->sonido.activeDSPSound('d');
	lastPressed=2;
}

void theremin::soundT(){
	stopSound();
	ui.centralWidget->sonido.activeDSPSound('t');
	lastPressed=3;
}

void theremin::soundPlay(){
	switch (lastPressed){
	case 1:
		soundQ();
		break;
	case 2:
		soundD();
		break;
	case 3:
		soundT();
		break;
	default:
		soundS();
		break;
	}
}

//funcion que detiene el sonido
void theremin::stopSound(){
	ui.centralWidget->sonido.stopDSPSound();
}

//metodo que abre la ventana "configuracion"
void theremin::vconfig(){
	ventanaConf conf(this);
	conf.vslider->setValue(ui.centralWidget->leap.detectorMovimientos.getMaxVol());
	conf.vvalue->setNum(ui.centralWidget->leap.detectorMovimientos.getMaxVol());
	conf.oslider->setValue(ui.centralWidget->leap.detectorMovimientos.getMaxOct());
	conf.ovalue->setNum(ui.centralWidget->leap.detectorMovimientos.getMaxOct());
	if(conf.exec()){
		ui.centralWidget->leap.detectorMovimientos.setMaxVol(conf.vslider->value());
		ui.centralWidget->leap.detectorMovimientos.setMaxOct(conf.oslider->value());
	}
}

//metodo que abre la ventana "acerca de"
void theremin::aboutButton(){
	
	ventanaSobre s(this);
	s.exec();
}

//metodo que cambia la forma de genrerar frecuencias de sonido
void theremin::modAfinado(){
	if(ui.centralWidget->afinado) ui.centralWidget->afinado=false;
	else ui.centralWidget->afinado=true;
}

//metodo que muestra un teclado en la pantalla
void theremin::mostrarPiano(){
	if(ui.centralWidget->piano) ui.centralWidget->piano=false;
	else ui.centralWidget->piano=true;
}

//metodo para cerrar el programa
void theremin::salir(){
	ui.centralWidget->estadoLeap=ui.centralWidget->leap.leapExit();
	ui.centralWidget->sonido.close();
	close();
}

//funciones que se activan al presionar cada boton

void theremin::on_actionPlay_triggered(){soundPlay();}
void theremin::on_actionStop_triggered(){stopSound();}
void theremin::on_actionSinus_triggered(){soundS();}
void theremin::on_actionQuad_triggered(){soundQ();}
void theremin::on_actionSaw_triggered(){soundD();}
void theremin::on_actionTriangle_triggered(){soundT();}