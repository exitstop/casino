#ifndef COMMON_H
#define COMMON_H

#include "drum.h"
#include <cstdlib>
#include <ctime>


extern class ClassDraw& mDraw;
extern class Font mFont;
extern double queuedMilliseconds,prev0,fps,responseTime;
extern float black[4];
extern float red[4];
extern float transparent_green[4];

extern class ClassDrum myDrum;
extern class ClassDrum myDrum2;
extern class ClassDrum myDrum3;
extern class ClassDrum myDrum4;
extern class ClassDrum myDrum5;


void Draw();
class classDraw;





// namespace kolos{


// } // end namespace kolos

#endif