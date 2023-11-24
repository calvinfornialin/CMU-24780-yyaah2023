#pragma once

#include "yspng.h"

extern YsRawPngDecoder grass;
extern YsRawPngDecoder character_right;
extern YsRawPngDecoder character_left;

enum pngFile{
    enum_grass,
    enum_character_right,
    enum_character_left
};

void DrawPng(double x, double y, pngFile file);
int initPng(void);