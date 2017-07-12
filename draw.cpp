#include <font.h>
#include <common.h>
#include "draw.h"
#include "include.h"
#include "fps.h"

// freetype::font_data our_font;


float black[4] = { 0, 0, 0, 1 };
float red[4] = { 1, 0, 0, 1 };
float transparent_green[4] = { 0, 1, 0, 0.5 };


ClassDraw * ClassDraw::p_instance = 0;
ClassDrawDestroyer ClassDraw::destroyer;
int ClassDrum::count = 0;



ClassDrum myDrum (-0.95, 0, 0.09);
ClassDrum myDrum2(-0.55, 0, 0.07);
ClassDrum myDrum3(-0.15, 0, 0.05);
ClassDrum myDrum4(0.25, 0,  0.03);
ClassDrum myDrum5(0.65, 0,  0.06);

  
ClassDrawDestroyer::~ClassDrawDestroyer() {   
    delete p_instance; 
}
void ClassDrawDestroyer::initialize( ClassDraw* p ) {
    p_instance = p; 
}
ClassDraw& ClassDraw::getInstance(float width, float height){
    if(!p_instance){
        p_instance = new ClassDraw(width, height);
        destroyer.initialize( p_instance);     
    }
    return *p_instance;
}


void ClassDraw::Init(){




//#####################################################################################


	if (! glfwInit ())
	{
	    // Ошибка инициализации
	}
	
	glViewport( 0, 0, winWidth, winHeight );
	glMatrixMode( GL_PROJECTION );            // Выбор матрицы проекций
    glLoadIdentity();              // Сброс матрицы проекции
 
    // Вычисление соотношения геометрических размеров для окна
    // gluPerspective( -1.0f, (GLfloat)winWidth/(GLfloat)winHeight, 0.1f, 100.0f );
 
    glMatrixMode( GL_MODELVIEW );            // Выбор матрицы вида модели
    glLoadIdentity(); 

	// glClearColor(0.5, 0.7, 0.3, 1.0);
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();

	// glOrtho(0, winWidth, winHeight, 0, -1.0, 1.0);
	// // gluPerspective( 45.0f, (GLfloat)winWidth/(GLfloat)winHeight, 0.1f, 100.0f );

	// glMatrixMode(GL_MODELVIEW);
	// glLoadIdentity();

	// // glTranslatef(200, 200, 0);

	// // glTranslatef(-200, -200, 0);

	// // glShadeModel(GL_SMOOTH);

	// // glClear(GL_COLOR_BUFFER_BIT);
	
	// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// glShadeModel(GL_SMOOTH);
	// // glEnable(GL_BLEND);


	
	// unsigned char* image;
	// int width, height;
	// glGenTextures(8,myImage);

	// char file_path[] = "image/1.png";

	// glBindTexture(GL_TEXTURE_2D, myImage[0]);  //texture 1 active 
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	
	// image = SOIL_load_image( file_path, &width, &height, 0, SOIL_LOAD_RGBA );
	// glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
	// SOIL_free_image_data( image );

	// glEnable(GL_TEXTURE_2D);


//-----------------------------------------------------------------------------------------------------------


	// mDraw.dlist[0]=glGenLists(1);
	// glNewList(mDraw.dlist[0], GL_COMPILE);
	// 	glBegin(GL_QUADS);
	// 		glTexCoord2f(0.0, 0.0); glVertex3f(0,450.0/2,0);
	// 		glTexCoord2f(1.0, 0.0); glVertex3f(45,450.0/2,0);
	// 		glTexCoord2f(1.0, -1.0); glVertex3f(45,(450.0/2)+45,0);                        
	// 		glTexCoord2f(0.0, -1.0); glVertex3f(0,(450.0/2)+45,0);
	// 	glEnd();
	// glEndList();

 //    glPushMatrix();
 //    	// glTranslatef(movementX,movementY,0);
 //    	glBindTexture(GL_TEXTURE_2D, mDraw.myImage[0]);
 //    	glCallList(mDraw.dlist[0]);
 //    glPopMatrix();	
		

	// glBegin(GL_TRIANGLES);
 //            glVertex3f( 0.0f, 1.0f, 0.0f);  // Вверх
 //            glColor3d(1,0,0);
 //            // glUniform4f(Font::uniform_color, 1.0f, 0.0f, 1.0f, 0.0f);
 //            glVertex3f(-1.0f,-1.0f, 0.0f);  // Слева снизу
 //            glVertex3f( 1.0f,-0.5f, 0.0f);  // Справа снизу
 //    glEnd();
	/* Enable smooth shading */
	// glShadeModel( GL_SMOOTH );

	// /* Set the background black */
	// glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

	// /* Depth buffer setup */
	// glClearDepth( 1.0f );

	// /* Enables Depth Testing */
	// glEnable( GL_DEPTH_TEST );

	// /* The Type Of Depth Test To Do */
	// glDepthFunc( GL_LEQUAL );

	// /* Really Nice Perspective Calculations */
	// glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

	// our_font.init("Test.ttf", 16);


}

ClassDraw::~ClassDraw(){
	// GlfwTerminate ();
}

void ClassDraw::buttonClick(){
	clickButton = true; buttonInt = 1;
}
void ClassDraw::buttonInc(){

	if(!clickButton){
		if(buttonInt != 1){
			buttonInt++;

		}else{
			buttonInt = 0;
		}
	}
}

void ClassDraw::buttonInc2(){

	if(clickButton){
		if(buttonInt != 4){
			buttonInt++;

		}else{
			buttonInt = 0; clickButton = false;
		}
	}
}


void ClassDraw::button(){
	glPushMatrix();
		glTranslatef(0.2, -1, -0.96	);
		glBindTexture(GL_TEXTURE_2D, mDraw.myImage[buttonInt]);		
		glCallList(mDraw.dlist[0]);
	glPopMatrix();
}


void ClassDraw::print(const char* text, float y, float x, float* color,int size, float h){
	float sx = 1.0 / glutGet(GLUT_WINDOW_WIDTH);
	float sy = 1.0 / glutGet(GLUT_WINDOW_HEIGHT);

	// glUseProgram(Font::program);

	FT_Set_Pixel_Sizes(Font::face, 0, size);                   
	// glUniform4fv(Font::uniform_color, 1, red);
	glPushMatrix();
		glTranslatef(0, 0, h);
		glColor3f(color[0], color[1], color[2]);
		mFont.render_text(text, y, x, sx, sy);
		glColor3f(1.0f,1.0f,1.0f);
	glPopMatrix();
}

void ClassDraw::initDraw(){
	glShadeModel(GL_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	unsigned char* image;
	int width, height;
	glGenTextures(6, mDraw.myImage);

	char file_path[] = "image/xx_00000.png";

	for(int i = 0; i < 6; i++){
		file_path[13] = 0x30 + i;
		
		glBindTexture(GL_TEXTURE_2D, mDraw.myImage[i]);  //texture 1 active 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		
		image = SOIL_load_image( file_path, &width, &height, 0, SOIL_LOAD_RGBA );
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
		SOIL_free_image_data( image );

		
	}


	glEnable(GL_TEXTURE_2D);

	mDraw.dlist[0]=glGenLists(1);

	#define H1 0
	#define DIV1 0.5
	glNewList(mDraw.dlist[0], GL_COMPILE);

		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, H1);
			glTexCoord2f(1.0, 0.0); glVertex3f(DIV1, 0, H1);
			glTexCoord2f(1.0, -1.0); glVertex3f(DIV1, DIV1, H1);                        
			glTexCoord2f(0.0, -1.0); glVertex3f(0, DIV1, H1);
		glEnd();

	glEndList();

}


void Draw(){
	glClearColor(0.5, 0.7, 0.7, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	// glLoadIdentity();
    
	glEnable(GL_DEPTH_TEST);	
	glEnable(GL_BLEND);



	if(mDraw.opt1==0)
	{
		
		mDraw.initDraw();

		mDraw.opt1=1;
	}else{


		//  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


		myDrum.draw();	
		myDrum2.draw();	
		myDrum3.draw();	
		myDrum4.draw();	
		myDrum5.draw();	

		#define H -0.95


		// glPushMatrix();
		// 	// glTranslatef(0,0,0.0f);
		// 	glColor3f(0.5, 1, 0.7);
		// 	glBegin(GL_QUADS);
		// 		glTexCoord2f(0.0, 0.0);  glVertex3f(-1,   -1,    H);
		// 		glTexCoord2f(1.0, 0.0);  glVertex3f(1,    -1,    H);
		// 		glTexCoord2f(1.0, -1.0); glVertex3f(1,    0.2,   H);                        
		// 		glTexCoord2f(0.0, -1.0); glVertex3f(-1,   0.2,   H);
		// 	glEnd();
		// 	glColor3f(1, 1, 1);
		// glPopMatrix();

		glPushMatrix();
			// glTranslatef(0,0,0.0f);
			glColor3f(0.5, 1, 0.7);
			glBegin(GL_QUADS);
				glVertex3f(-1,   -1,    H);
				glVertex3f(1,    -1,    H);
				glVertex3f(1,    0.2,   H);                        
				glVertex3f(-1,   0.2,   H);
			glEnd();
			glColor3f(1, 1, 1);
		glPopMatrix();


		glPushMatrix();
			// glTranslatef(0,0,0.0f);
			glColor3f(0.5, 0.7, 0.7);
			glBegin(GL_QUADS);
				glVertex3f(-1,   1,     H);
				glVertex3f(1,    1,     H);
				glVertex3f(1,    0.9,   H);                        
				glVertex3f(-1,   0.9,   H);
			glEnd();
			glColor3f(1, 1, 1);
		glPopMatrix();


		mDraw.button();

		
		char fpsbuf[30];
		sprintf(fpsbuf,"FPS: %.f", calcFPS() );
		mDraw.print(fpsbuf, 0.7f, -0.9f, red, 50, -1);
	}

	 
	


	glDisable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);

	glFinish();

	glutSwapBuffers();
}


float ClassDraw::WinWidth(){
	return winWidth;
}

float ClassDraw::WinHeight(){
	return winHeight;
}



// void display() {
//     float sx = 1.0 / glutGet(GLUT_WINDOW_WIDTH);
//     float sy = 1.0 / glutGet(GLUT_WINDOW_HEIGHT);

//     glUseProgram(Font::program);

//     /* White background */
//     glClearColor(1, 1, 1, 1);
//     glClear(GL_COLOR_BUFFER_BIT);

//     /* Enable blending, necessary for our alpha texture */
//     glEnable(GL_BLEND);
//     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

//     GLfloat black[4] = { 0, 0, 0, 1 };
//     GLfloat red[4] = { 1, 0, 0, 1 };
//     GLfloat transparent_green[4] = { 0, 1, 0, 0.5 };   



//     FT_Set_Pixel_Sizes(Font::face, 0, 30);                   /// Размер шрифта
//     glUniform4fv(Font::uniform_color, 1, red);
//     mFont.render_text("FPS: 30", 0.7, -0.9, sx, sy);

//     glutSwapBuffers();
// }

double queuedMilliseconds,prev0,fps,responseTime;

void mixedStepLoop()
{
    
    

    double now = glutGet(GLUT_ELAPSED_TIME);
    double timeElapsedMs =(now-prev0);
    queuedMilliseconds += timeElapsedMs ;
    while(queuedMilliseconds >= responseTime) 
    {
       // update();
        queuedMilliseconds -= responseTime;
        glutPostRedisplay();
    }
    prev0=now;
}

