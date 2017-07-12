#ifndef DRUM_H
#define DRUM_H

#include <common.h>
#include "include.h"

#include <random>


class ClassDrum{
private:
  float cordX, cordY;
  static int count;
  int localcount;
  float floatroll;
  float speed;
  int stop;
  bool start;
  std::random_device rd;
public:
  ClassDrum(float y, float x, float sp = 0.01):cordY(y), cordX(x), floatroll(0.0f),speed(sp), start(false){  
          localcount = count;
          count++; 
          floatroll = 0;
          initRandom();
      };
  ~ClassDrum(){};
  void initRandom(){    
    stop = 25;
    speed = 0.01;    
    stop += localcount*5+(rd() % 5);  speed += 0.003*float((rd() % 20));  
    // std::cout << stop << std::endl;
  }
  void draw();
  void roll();
  void go();
};


#endif