#ifndef DRAW_H
#define DRAW_H

#include <common.h>
#include "include.h"





void display();

class ClassDrawDestroyer;

  
class ClassDraw
{
  private:
    static ClassDraw* p_instance;
    static ClassDrawDestroyer destroyer;
    int buttonInt;
    float winWidth;
    float winHeight;
    bool clickButton;
  protected: 
    ClassDraw(float width, float height):winWidth(width), winHeight(height), buttonInt(0), clickButton(false){ /* winWidth = width;  winHeight = height;*/  }
    ClassDraw( const ClassDraw& );
    ClassDraw& operator=( ClassDraw& );
   ~ClassDraw();
    friend class ClassDrawDestroyer;
  public:
    static ClassDraw& getInstance(float width, float height);  
    void Init(); 
    // void Draw();  
    float WinWidth();  
    float WinHeight();  
    void print(const char* text, float x, float y, float* color, int size, float h);
    void button();
    void buttonInc();
    void buttonInc2();
    void buttonClick();
    void initDraw();
    GLuint dlist[6];
    GLuint myImage[8];
    char opt1;
};
  
  
void mixedStepLoop();

class ClassDrawDestroyer 
{
  private:
    ClassDraw* p_instance;
  public:    
    ~ClassDrawDestroyer();
    void initialize( ClassDraw* p );
};




#endif