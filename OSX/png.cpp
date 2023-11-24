#include "yspng.h"
#include "png.h"
#include <iostream>
#include "fssimplewindow.h"

YsRawPngDecoder grass;
YsRawPngDecoder character_right;
YsRawPngDecoder character_left;

int initPng(void){
    if(YSOK!=grass.Decode("png/grass.png"))
	{
		std::cout << "PNG load error." << std::endl;
		return 1;
	}
    if(YSOK!=character_right.Decode("png/character_right.png"))
	{
		std::cout << "PNG load error." << std::endl;
		return 1;
	}
    if(YSOK!=character_left.Decode("png/character_left.png"))
	{
		std::cout << "PNG load error." << std::endl;
		return 1;
	}
	character_right.Flip();
	character_left.Flip();
	grass.Flip();
    return 0;
}

void DrawPng(double x, double y, pngFile file)
{
    glRasterPos2d(x,y-1);
	switch(file){
		case enum_grass:
			glDrawPixels(grass.wid,grass.hei,GL_RGBA,GL_UNSIGNED_BYTE,grass.rgba);
			break;
		case enum_character_right:
			glDrawPixels(character_right.wid,character_right.hei,GL_RGBA,GL_UNSIGNED_BYTE,character_right.rgba);
			break;
		case enum_character_left:
			glDrawPixels(character_left.wid,character_left.hei,GL_RGBA,GL_UNSIGNED_BYTE,character_left.rgba);
			break;
		default:
			break;
	}
	
    return;
}