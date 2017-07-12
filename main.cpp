#include <iostream>
#include <common.h>
#include <font.h>
#include "draw.h"


// using namespace std;
// GLuint Font::program;
FT_Face Font::face;
// GLint Font::uniform_color;

Font mFont("./dump/FreeSans.ttf");
ClassDraw& mDraw = ClassDraw::getInstance(600.0, 600.0);


struct MPXY{
    int x;
    int y;
}mPxyLast;



void TimerButton(int value)
{
    mDraw.buttonInc();
    glutTimerFunc(1000, TimerButton, 0);
}

void TimerButtonClick(int value)
{
    mDraw.buttonInc2();
    glutTimerFunc(50, TimerButtonClick, 0);
}

void Timer(int value)
{
    myDrum.roll();
    myDrum2.roll();
    myDrum3.roll();
    myDrum4.roll();
    myDrum5.roll();
    glutTimerFunc(100, Timer, 0);
}

void reshape(int w, int h)
{
   
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glViewport(0, 0, (GLsizei) mDraw.WinWidth(), (GLsizei) mDraw.WinHeight());
   glOrtho(0, mDraw.WinWidth(),0, mDraw.WinHeight(),-5,10);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}



void myMouseFunc(int button, int state, int ax, int ay)
{
    
    mPxyLast.x -= ax;
    mPxyLast.y -= ay;

    // char buf[30];
    // buf[0]=0;
    // sprintf(buf, "press %d %d", mPxyLast.x, mPxyLast.y); 
    

    if(state == 1){

        if(ax > 366 && ay > 465 && ax < 500 && ay < 586){
            // sprintf(buf, "press %d %d", ax, ay); 
            // glutSetWindowTitle(buf);  
            // std::cout << button << " " << state << std::endl;

            myDrum.go();
            myDrum2.go();
            myDrum3.go();
            myDrum4.go();
            myDrum5.go(); 
            mDraw.buttonClick(); 
        }
    }


    mPxyLast.x = ax;
    mPxyLast.y = ay;
}





int main(int argc, char** argv){

   std::srand(unsigned(std::time(0)));

    queuedMilliseconds=0;
    prev0=0;
    fps=30;
    responseTime=(1/fps)*1000;



    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(mDraw.WinWidth(), mDraw.WinHeight());
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Casino"); 

    GLenum glew_status = glewInit();

    if (!GLEW_VERSION_2_0) {
        fprintf(stderr, "No support for OpenGL 2.0 found\n");
        return 1;
    }

    glutTimerFunc(50, Timer, 0);
    glutTimerFunc(1000, TimerButton, 0);
    glutTimerFunc(100, TimerButtonClick, 0);

    // glutMotionFunc(MousePressedMove);
    glutMouseFunc(myMouseFunc);
    // glutPassiveMotionFunc(MouseMove);

    

    // glutReshapeFunc(reshape);
    mDraw.Init();
    if (mFont.init_resources()) {
        glutDisplayFunc(Draw);
        glutIdleFunc(mixedStepLoop);
        glutMainLoop();
    }

    // glutDisplayFunc(Draw);
    // glutMotionFunc(MousePressedMove);
    // glutPassiveMotionFunc(MouseMove);
    // glutMouseFunc(MousePressed);
    
    // glutTimerFunc(500, Timer2, 0);
    // Initialize();

    
    // glutMainLoop();    

    return 0;
}