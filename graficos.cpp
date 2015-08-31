#include <QtWidgets>
#include <QtOpenGL>

#include "graficos.h"

#define PI 3.1415926

//array de frecuencias
float nfrec[110]=
{0.00,16.35, 17.32, 18.35, 19.45, 20.60, 21.83, 23.12, 24.50, 25.96, 27.50, 29.14, 30.87,
32.70, 34.65, 36.71, 38.89, 41.20, 43.65, 46.25, 49.00, 51.91, 55.00, 58.27, 61.74,
65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47,
130.81, 138.59, 146.83, 155.56, 164.81, 174.61, 185.00, 196.00, 207.65, 220.00, 233.08, 246.94,
261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88,
523.25, 554.37, 587.33, 622.25, 659.25, 698.46, 739.99, 783.99, 830.61, 880.00, 932.33, 987.77,
1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22, 1760.00, 1864.66, 1975.53,
2093.00, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44, 3520.00, 3729.31, 3951.07,
4186.01, 4434.92, 4698.63, 4978.03, 5274.04, 5587.65, 5919.91, 6271.93, 6644.88, 7040.00, 7458.62, 7902.13, 8372.01};

//array con las notas equivalentes a los valores del array de frecuencias respecto a sus posiciones
char notas[110][4]=
{"~~","C0","C#0","D0","D#0","E0","F0","F#0","G0","G#0","A0","A#0","B0",
"C1","C#1","D1","D#1","E1","F1","F#1","G1","G#1","A1","A#1","B1",
"C2","C#2","D2","D#2","E2","F2","F#2","G2","G#2","A2","A#2","B2",
"C3","C#3","D3","D#3","E3","F3","F#3","G3","G#3","A3","A#3","B3",
"C4","C#4","D4","D#4","E4","F4","F#4","G4","G#4","A4","A#4","B4",
"C5","C#5","D5","D#5","E5","F5","F#5","G5","G#5","A5","A#5","B5",
"C6","C#6","D6","D#6","E6","F6","F#6","G6","G#6","A6","A#6","B6",
"C7","C#7","D7","D#7","E7","F7","F#7","G7","G#7","A7","A#7","B7",
"C8","C#8","D8","D#8","E8","F8","F#8","G8","G#8","A8","A#8","B8","C9",};

//creador del objeto graficos
graficos::graficos(QWidget *parent) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent){

	quadratic = gluNewQuadric();
	filas = 4;
	relacion = 48000.0f/440.0f;
	pcamara[0] = 0;
	pcamara[1] = 13;
	pcamara[2] = 10;
	xRot = 0;
	yRot = 0;
	afinado = false;
	piano = false;

	QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(0);
}

graficos::~graficos(void)
{
}

//metodo que normaliza el angulo que recibe
static void qNormalizeAngle(float &angle){
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}

//calculo del angulo sobre el eje x
void graficos::setXRotation(float angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
		pcamara[0] = 10*sin((xRot/16)*PI/180);
    }
}

//calculo del angulo sobre el eje y
void graficos::setYRotation(float angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
		pcamara[1] = 10*cos((yRot/16)*PI/180);
    }
}

//metodo que se ejecuta al inicio del sistema gráfico
void graficos::initializeGL()
{
	estadoLeap=leap.leapInit();
	sonido.DSPInit();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);    // Uses default lighting parameters
	glEnable(GL_DEPTH_TEST);
	//glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_NORMALIZE);

	mod.init();

}

//metodo que dibuja el escenario
void graficos::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//situo y oriento la camara
		gluLookAt(pcamara[0],pcamara[1]+3,pcamara[2],	//ojo
				  0,3,0,	//punto al que miro
				  0,1,0);	//vertical subjetiva

		//dibujar theremin

		mod.model();

		//si se reconocen manos, dibujarlas

		if(leap.detectorMovimientos.getNumManos()>0) dibujarManos();
	
	glPopMatrix();

	//dibujar piano de referencia

	if(piano) dibujarPiano();

	//mostrar informacion

	textodisplay();


	idle();
}

//metodo que redimensiona el escenario
void graficos::resizeGL(int width, int height)
{
    //int side = qMin(width, height);
    //glViewport((width - side) / 2, (height - side) / 2, side, side);

	glViewport(0,0,width,height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

	glOrtho(-10,10,-(float)height*10/width,(float)height*10/width,-1,1000);

    
}

//metodo que responde al uso del raton
void graficos::mousePressEvent(QMouseEvent *event){
	lastPos = event->pos();
}

//metodo que responde al movimiento del raton
void graficos::mouseMoveEvent(QMouseEvent *event){
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
		setXRotation(xRot + 8 * dx);
        setYRotation(yRot + 8 * dy);
    } /*else if (event->buttons() & Qt::RightButton) {
		pcamara[1] = 10*sin(dy*PI/360);
		pcamara[2] = 10*cos(dx*PI/360);
    }*/

    lastPos = event->pos();
}

//metodo que dibuja las manos partiendo de la informacion que genera el Leap Motion
void graficos::dibujarManos(){

	//GLfloat c1[]={0.8f, 0.8f, 0.8f, 1.0f};
	GLfloat c1[]={0.9f, 0.9f, 0.0f, 1.0f};
	
	//GLfloat c2[]={0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat c2[]={0.0f, 0.0f, 0.0f, 1.0f};
	
	//GLfloat c3[]={0.2f, 0.2f, 0.2f, 1.0f};
	GLfloat c3[]={0.6f, 0.6f, 0.0f, 1.0f};
	
	//GLfloat c4[]={0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat c4[]={0.0f, 0.0f, 0.0f, 1.0f};

	//GLfloat c1[]={0.8f, 0.8f, 0.8f, 1.0f};
	GLfloat c5[]={0.9f, 0.0f, 0.0f, 1.0f};
	
	//GLfloat c2[]={0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat c6[]={0.0f, 0.0f, 0.0f, 1.0f};
	
	//GLfloat c3[]={0.2f, 0.2f, 0.2f, 1.0f};
	GLfloat c7[]={0.6f, 0.0f, 0.0f, 1.0f};
	
	//GLfloat c4[]={0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat c8[]={0.0f, 0.0f, 0.0f, 1.0f};

	glPushMatrix();
	glScalef(0.02,0.02,0.02);

	//dibujar palma de las manos

	for(int i=0; i<leap.detectorMovimientos.getNumManos(); i++){
		
		glPushMatrix();
			//glColor3f(1,1,0);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, c1);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, c2);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, c3);
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, c4);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.5f);
			//glEnable(GL_CULL_FACE);

			glTranslatef(leap.detectorMovimientos.getPalma(i).x, leap.detectorMovimientos.getPalma(i).y, leap.detectorMovimientos.getPalma(i).z);
			glMultMatrixf(leap.detectorMovimientos.getDireccionMano(i).toArray4x4());
			glRotatef(-90,1,0,0);
			glTranslatef(0,-25,0);
			glutSolidTorus(2.5,25,20,20);
			glPushMatrix();
				//glColor3f(1,0,0);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, c5);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, c6);
				glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, c7);
				glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, c8);
				glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.5f);
        
				//glEnable(GL_CULL_FACE);
				glScalef(1,1,0.5);
				glutSolidSphere(20,20,20);
			glPopMatrix();
		glPopMatrix();
	}

	for(int i=0; i<leap.detectorMovimientos.getNumManos()*20; i++){

		//dibujar puntos de flexion de las manos

		glPushMatrix();
			//glColor3f(1,0,0);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, c5);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, c6);
				glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, c7);
				glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, c8);
				glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.5f);
        
			//glEnable(GL_CULL_FACE);
			glTranslatef(leap.detectorMovimientos.getHands(i).x,leap.detectorMovimientos.getHands(i).y,leap.detectorMovimientos.getHands(i).z);
			glMultMatrixf(leap.detectorMovimientos.getDireccionHueso(i).toArray4x4());
			glScalef(1,0.5,1);
			glutSolidSphere(leap.detectorMovimientos.getAnchuraHueso(i),20,20);
		glPopMatrix();

		//dibujar huesos de las manos
	
		if(i%4!=0){
			glPushMatrix();
				//glColor3f(1,1,0);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, c1);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, c2);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, c3);
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, c4);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.5f);
			//glEnable(GL_CULL_FACE);
        
				//glEnable(GL_CULL_FACE);
				glTranslatef(leap.detectorMovimientos.getPosicionHueso(i).x,leap.detectorMovimientos.getPosicionHueso(i).y,leap.detectorMovimientos.getPosicionHueso(i).z);
				glMultMatrixf(leap.detectorMovimientos.getDireccionHueso(i).toArray4x4());
				glScalef(1,0.5,1);
				gluCylinder(quadratic,leap.detectorMovimientos.getAnchuraHueso(i),leap.detectorMovimientos.getAnchuraHueso(i),leap.detectorMovimientos.getLongitudHueso(i),20,1);
			glPopMatrix();
		}

	}

	glPopMatrix();

}

//metodo que dibuja el texto quue hay en la matriz texto
void graficos::textodisplay(){

	glDisable(GL_LIGHTING);
	glPushAttrib(GL_CURRENT_BIT);
		//glRotatef(xRot/16,0,1,0);
		//glRotatef(yRot/16,1,0,0);

		glPushMatrix();
			glTranslatef(-3,5,0);
			glScalef(0.7,0.7,0.7);
			glRotatef(-45,1,0,0);
	
			for(int l=0; l<filas; l++){
				int letras = (int)strlen(texto[l]);
				glPushMatrix();
				glTranslatef(-8.0,4.0-(1*l),0);
				glScalef(0.005,0.005,0.005);
				for (int i=0; i<letras; i++){
					glColor3f(1.0,1.0,1.0);
					glLineWidth(3);
					glutStrokeCharacter(GLUT_STROKE_ROMAN, texto[l][i]);
				}
				glPopMatrix();
			}
		glPopMatrix();
	glPopAttrib();
	glEnable(GL_LIGHTING);

}

//metodo que dibuja un teclado de piano, marcando la nota que genera el theremin
void graficos::dibujarPiano(){

	glDisable(GL_LIGHTING);
	glPushAttrib(GL_CURRENT_BIT);
	float k=0.0;
	glPushMatrix();
	glTranslatef(-6,3,4);
	glScalef(0.25,0.5,0.5);
	glRotatef(40,1,0,0);

	for(int i=10;i<98;i++){				
		if(i%12==1 || i%12==3 || i%12==5 || i%12==6 || i%12==8 || i%12==10 || i%12==0){
			glPushMatrix();
				if(i==nota) glColor3f(1,0,0);
				else glColor3f(1,1,1);
				glBegin(GL_QUAD_STRIP);
					glVertex3f(k,1,0);
					glVertex3f(k,1,2);
					glVertex3f(k+1,1,0);
					glVertex3f(k+1,1,2);
				glEnd();
				glColor3f(0,0,0);
				glLineWidth(3);
				glBegin(GL_LINE_STRIP);
					glVertex3f(k,1,0);
					glVertex3f(k+1,1,0);
					glVertex3f(k+1,1,2);
					glVertex3f(k,1,2);
				glEnd();
			glPopMatrix();
			k=k+1.0;
		}
		else{
			glPushMatrix();
			if(i==nota) glColor3f(1,0,0);
			else glColor3f(0,0,0);
			glBegin(GL_QUAD_STRIP);
				glVertex3f(k-0.25,2,0);
				glVertex3f(k-0.25,2,1);
				glVertex3f(k+0.25,2,0);
				glVertex3f(k+0.25,2,1);
			glEnd();
			glPopMatrix();
		}
	}
	glPopMatrix();
	glPopAttrib();

	glEnable(GL_LIGHTING);
}

//metodo que busca la posicion en la array frecuencias mas cercana a una frecuencia dada
int graficos::search(float n[],int i, int l, float f){
	
	if(i+1==l){
		float t=(n[l]-n[i])/2;
		if(f<n[i]+t) return i;
		else return l;
	}
	int p = (l-i)/2;
	if(f<n[i+p]) search(n,i,i+p,f);
	else search(n,i+p,l,f);

}

//hace lo mismo que search(), pero sirve para el modo afinado del theremin
/*
int graficos::modoAfinado(float n[],int i, int l, float f){

	if(i+1==l) return i;
	int p = (l-i)/2;
	if(f<n[i+p]) modoAfinado(n,i,i+p,f);
	else modoAfinado(n,i+p,l,f);

}*/

//metodo que actualiza la pantalla, la frecuencia y el volumen que genera el theremin, y el contenido de la matriz texto
void graficos::idle(){

	float frec;
	float volumen;
	char newText[80];

	//actualizar frecuencia de sonido

	frec=leap.detectorMovimientos.getFreq();
	if (frec<0) frec=0.00;

	if(afinado){ 
		nota=search(nfrec,0,109,frec);
		//nota=modoAfinado(nfrec,0,109,frec);
		sonido.setDSPFreq(nfrec[nota]*relacion);
		strcpy_s(texto[0],"Modo afinado: ON");
		sprintf_s(newText,"Frecuencia: %0.2f Hz",nfrec[nota]);
		strcpy_s(texto[1],newText);
		sprintf_s(newText,"Nota: %s",notas[nota]);
		strcpy_s(texto[2],newText);
	}
	else{ 
		float f=frec*relacion;
		sonido.setDSPFreq(f);
		strcpy_s(texto[0],"Modo afinado: OFF");
		sprintf_s(newText,"Frecuencia: %0.2f Hz",frec);
		strcpy_s(texto[1],newText);
		nota=search(nfrec,0,109,frec);
		sprintf_s(newText,"Nota: %s",notas[nota]);
		strcpy_s(texto[2],newText);
	}

	//actualizar volumen

	volumen=leap.detectorMovimientos.getVolumen();
	sonido.setDSPVolumen(volumen);
	sprintf_s(newText,"Volumen: %0.1f %%",volumen*100);
	strcpy_s(texto[3],newText);

}