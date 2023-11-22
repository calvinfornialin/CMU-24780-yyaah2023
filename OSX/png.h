#pragma once

#include "yspng.h"

extern YsRawPngDecoder grass;
extern YsRawPngDecoder character;

enum pngFile{
    enum_grass,
    enum_character
};

void DrawPng(double x, double y, pngFile file);
int initPng(void);