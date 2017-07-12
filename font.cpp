#include "font.h"


Font::Font(const char *fontfilename_):fontfilename(fontfilename_){
	// fontfilename = fontfilename_;
}

int Font::init_resources() {
    /* Initialize the FreeType2 library */
    if (FT_Init_FreeType(&ft)) {
        fprintf(stderr, "Could not init freetype library\n");
        return 0;
    }

    /* Load a font */
    if (FT_New_Face(ft, fontfilename, 0, &face)) {
        fprintf(stderr, "Could not open font %s\n", fontfilename);
        return 0;
    }

    glGenBuffers(1, &vbo);

    return 1;
}


void Font::render_text(const char *text, float x, float y, float sx, float sy) {
    const char *p;
    FT_GlyphSlot g = face->glyph;

    /* Create a texture that will be used to hold one "glyph" */
    GLuint tex;
    GLuint myImage[8];

    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    /* We require 1 byte alignment when uploading texture data */
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    /* Clamping to edges is important to prevent artifacts when scaling */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    /* Linear filtering usually looks best for text */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    glEnable(GL_TEXTURE_2D);

    /* Loop through all characters */
    for (p = text; *p; p++) {
        // std::cout << *p;
        
        if (FT_Load_Char(face, *p, FT_LOAD_RENDER))
            continue;

        /* Upload the "bitmap", which contains an 8-bit grayscale image, as an alpha texture */
        
         glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, g->bitmap.width, g->bitmap.rows, 0, GL_ALPHA, GL_UNSIGNED_BYTE, g->bitmap.buffer);


        /* Calculate the vertex and texture coordinates */
        float x2 = x + g->bitmap_left * sx;
        float y2 = -y - g->bitmap_top * sy;
        // float w = g->bitmap.width * sx;
        float w = g->bitmap.width * sx;
        float h = g->bitmap.rows * sy;
        // float h = g->bitmap.rows * sy;

        // point box[4] = {
        //     {x2,     -y2,       0, 0},
        //     {x2 + w, -y2,       1, 0},
        //     {x2,     -y2 - h,   1, 1},
        //     {x2 + w, -y2 - h,   0, 1},
        // };



        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);          glVertex3f(x2,     -y2, 0);
            glTexCoord2f(1, 0);          glVertex3f(x2 + w, -y2, 0);
            glTexCoord2f(1, 1);          glVertex3f(x2 + w, -y2 - h, 0) ;                        
            glTexCoord2f(0, 1);          glVertex3f(x2,     -y2 - h, 0);
        glEnd();



        /* Advance the cursor to the start of the next character */
        x += (g->advance.x >> 6) * sx;
        y += (g->advance.y >> 6) * sy;
    }

    // glDisableVertexAttribArray(attribute_coord);
    glDeleteTextures(1, &tex);
}



void Font::free_resources() {
    // glDeleteProgram(Font::program);
}
