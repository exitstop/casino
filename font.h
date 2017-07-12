#ifndef FONT_H
#define FONT_H

#include "include.h"

struct point {
    GLfloat x;
    GLfloat y;
    GLfloat s;
    GLfloat t;
};



class Font{
private:	
	GLint attribute_coord;
	GLint uniform_tex;	
	GLuint vbo;
	FT_Library ft;


	
	const char *fontfilename;
public:	
	Font();
	Font(const char *fontfilename_);
	~Font(){};
	int init_resources();
	void render_text(const char *text, float x, float y, float sx, float sy);
	void free_resources();
	void print(int color);
	static GLuint program;
	static FT_Face face;
	static GLint uniform_color;


};


namespace kolos{

}// end namespace kolos

#endif