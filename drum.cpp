#include <common.h>
#include "include.h"
#include "draw.h"



void ClassDrum::draw(){

	glPushMatrix();
		glTranslatef(cordY,cordX,0.0f);
		glColor3f(1.0f,1.0f,1.0f);
		glBegin(GL_QUADS);
			//glTexCoord2f(0.0, 0.0); // glVertex3f(0,   0.1,    0);
			//glTexCoord2f(1.0, 0.0); // glVertex3f(0.3, 0.1,    0);
			//glTexCoord2f(1.0, -1.0); //glVertex3f(0.3, 0.9,    0);                        
			//glTexCoord2f(0.0, -1.0); //glVertex3f(0,   0.9,    0);
			glVertex3f(0,   0.1,    0);
			glVertex3f(0.3, 0.1,    0);
			glVertex3f(0.3, 0.9,    0);                        
			glVertex3f(0,   0.9,    0);
		glEnd();
		char buf[] = "X01";
		buf[2]=0x30+localcount;
		#define H -0.9

		if(floatroll >= 0.6){floatroll=0;}

		#define CT 0.6

		buf[1]=0x30;
		mDraw.print(buf, 0.01, 0.7+CT+floatroll, black, 100, H);
		buf[1]=0x31;
		mDraw.print(buf, 0.01, 0.5+CT+floatroll, black, 100, H);
		buf[1]=0x32;
		mDraw.print(buf, 0.01, 0.3+CT+floatroll, black, 100, H);

		#define CC 0

		// #################################################
		buf[1]=0x30;
		mDraw.print(buf, 0.01, 0.7+CC+floatroll, black, 100, H);
		buf[1]=0x31;
		mDraw.print(buf, 0.01, 0.5+CC+floatroll, black, 100, H);
		buf[1]=0x32;
		mDraw.print(buf, 0.01, 0.3+CC+floatroll, black, 100, H);
		// #################################################

		#define CD -0.6

		buf[1]=0x30;
		mDraw.print(buf, 0.01, 0.7+CD+floatroll, black, 100, H);
		buf[1]=0x31;
		mDraw.print(buf, 0.01, 0.5+CD+floatroll, black, 100, H);
		buf[1]=0x32;
		mDraw.print(buf, 0.01, 0.3+CD+floatroll, black, 100, H);


	glPopMatrix();


}

void ClassDrum::go(){
	floatroll = 0;
	start = true;
}

void ClassDrum::roll(){

	if(start == true){

		if(stop > 0) { 
			floatroll+=speed+0.003; stop--; 
		}else if(stop == 0){ 
			stop--;
			start =false;
			initRandom();			
			// floatroll = 0.2;
			// floatroll = 0.4;

			if(floatroll > 0 && floatroll < 0.15){
				floatroll = 0.0;
			}
			if(floatroll > 0.15 && floatroll < 0.35){
				floatroll = 0.2;
			}
			if(floatroll > 0.35 && floatroll < 0.55){
				floatroll = 0.4;
			}
			if(floatroll > 0.55 && floatroll < 0.75){
				floatroll = 0.6;
			}
			if(floatroll > 0.75 && floatroll < 0.95){
				floatroll = 0;
			}
			// std::cout << stop += (rand() % 30) << std::endl;


		}
	}
	
	
}
