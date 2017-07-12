CXXFLAG = -std=c++14
LIBS = -lm  -lGL -lglut -lGLU -lSOIL -lGLEW -lfreetype -lglfw 
casino: main.cpp common.h casino.cpp drum.cpp font.cpp draw.cpp casino.h drum.h font.h draw.h freetype.cpp freetype.h
	$(CXX) $(CXXFLAG) main.cpp common.h casino.cpp drum.cpp font.cpp draw.cpp  ./common/shader_utils.o -I. -o $@ $(LIBS) -I/usr/include/freetype2 

clean:
	rm casino