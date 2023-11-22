#include "yspng.h"
#include "png.h"
#include <iostream>
#include "fssimplewindow.h"

YsRawPngDecoder grass;
YsRawPngDecoder character;

int initPng(void){
    if(YSOK!=grass.Decode("png/grass.png"))
	{
		std::cout << "PNG load error." << std::endl;
		return 1;
	}
    if(YSOK!=character.Decode("png/character.png"))
	{
		std::cout << "PNG load error." << std::endl;
		return 1;
	}
	grass.Flip();
	character.Flip();
    return 0;
}

void DrawPng(double x, double y, pngFile file)
{
    glRasterPos2d(x,y);
	switch(file){
		case enum_grass:
			glDrawPixels(grass.wid,grass.hei,GL_RGBA,GL_UNSIGNED_BYTE,grass.rgba);
			break;
		case enum_character:
			glDrawPixels(character.wid,character.hei,GL_RGBA,GL_UNSIGNED_BYTE,character.rgba);
			break;
		default:
			break;
	}
	
    return;
}