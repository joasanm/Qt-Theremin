#pragma once
#include <QGLWidget>

#include <glut.h>
#include <UGKLeap.h>
#include <UGKSound.h>
#include "modelo.h"

class graficos : public QGLWidget
{
	Q_OBJECT
public:
	explicit graficos(QWidget *parent = 0);
	~graficos(void);
	void setXRotation(float angle);
	void setYRotation(float angle);
	UGK::CSound sonido;				//objeto de la clase audio
	UGK::UseLeap leap;				//objeto de la clase UGKLeap
	int estadoLeap;					//su valor es positivo o negativo dependiendo de si el Leap Motion esta conectado o desconectado
	bool afinado;					//booleano que confirma el uso del modo afinado
	bool piano;						//booleano que confirma el uso del piano de referencia
	modelo mod;						//objeto de la clase modelo

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
	void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
	void dibujarManos();
	void dibujarPiano();
	void textodisplay();
	//int modoAfinado(float n[],int i, int l, float f);
	int search(float n[],int i, int l, float f);
	void idle();

	QPoint lastPos;					//posicion anterior del raton
	float pcamara[3];				//posicion de la camara
	float xRot;						//angulo de la camara en el eje x
	float yRot;						//angulo de la camara en el eje y

    GLUquadricObj *quadratic;

	char texto[4][80];				//matriz con la informacion que se muestra en pantalla
	int filas;						//valor del numero de filas de la matriz texto
	float relacion;					//valor con la relacion entre la tasa de muestreo y la frecuencia de la nota A3
	int nota;						//valor que contiene la posicion del array de frecuencias/notas

};

