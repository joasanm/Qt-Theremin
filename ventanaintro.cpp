#include "ventanaintro.h"

//constructor de la ventana
ventanaIntro::ventanaIntro(QWidget *parent)
	: QWidget(parent)
{
	vconf = 100;
	oconf = 7;
	setupUi(this);
}

ventanaIntro::~ventanaIntro()
{

}

//metodo referente al uso del boton "empezar"
void ventanaIntro::on_startButton_clicked(){
	
	t = new theremin();
	t->ui.centralWidget->leap.detectorMovimientos.setMaxVol(vconf);
	t->ui.centralWidget->leap.detectorMovimientos.setMaxOct(oconf);
	t->showMaximized();
	close();
}

//metodo referente al uso del boton "acerca de"
void ventanaIntro::on_aboutButton_clicked(){
	
	s = new ventanaSobre();
	s->activateWindow();
	s->show();
}

//metodo referente al uso del boton "configuracion"
void ventanaIntro::on_confButton_clicked(){

	ventanaConf conf(this);
	conf.vslider->setValue(vconf);
	conf.vvalue->setNum(vconf);
	conf.oslider->setValue(oconf);
	conf.ovalue->setNum(oconf);
	if(conf.exec()){
		vconf=conf.vslider->value();
		oconf=conf.oslider->value();
	}
}
