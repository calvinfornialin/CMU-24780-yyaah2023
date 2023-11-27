#pragma once

#include "yspng.h"

extern YsRawPngDecoder grass;
extern YsRawPngDecoder character_right;
extern YsRawPngDecoder character_left;

enum pngFile{
    enum_grass,
    enum_character_right,
    enum_character_left,
    running_right_1,
    running_right_2,
    running_right_3,
    running_right_4,
    running_right_5,
    running_right_6,
    running_left_1,
    running_left_2,
    running_left_3,
    running_left_4,
    running_left_5,
    running_left_6,

};

void DrawPng(double x, double y, pngFile file);
int initPng(void);