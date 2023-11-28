#include "yspng.h"
#include "png.h"
#include <iostream>
#include "fssimplewindow.h"

YsRawPngDecoder grass;
YsRawPngDecoder facing_right;
YsRawPngDecoder facing_left;
YsRawPngDecoder right_1;
YsRawPngDecoder right_2;
YsRawPngDecoder right_3;
YsRawPngDecoder right_4;
YsRawPngDecoder right_5;
YsRawPngDecoder right_6;
YsRawPngDecoder left_1;
YsRawPngDecoder left_2;
YsRawPngDecoder left_3;
YsRawPngDecoder left_4;
YsRawPngDecoder left_5;
YsRawPngDecoder left_6;
YsRawPngDecoder rbt_left;
YsRawPngDecoder rbt_right;

int initPng(void) {
    if (YSOK != grass.Decode("png/grass.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    grass.Flip();

    if (YSOK != facing_right.Decode("png/facing_right.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    facing_right.Flip();

    if (YSOK != facing_left.Decode("png/facing_left.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    facing_left.Flip();

    // right
    if (YSOK != right_1.Decode("png/r1.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    right_1.Flip();

    if (YSOK != right_2.Decode("png/r2.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    right_2.Flip();

    if (YSOK != right_3.Decode("png/r3.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    right_3.Flip();

    if (YSOK != right_4.Decode("png/r4.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    right_4.Flip();

    if (YSOK != right_5.Decode("png/r5.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    right_5.Flip();

    if (YSOK != right_6.Decode("png/r6.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    right_6.Flip();

    // left
    if (YSOK != left_1.Decode("png/l1.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    left_1.Flip();

    if (YSOK != left_2.Decode("png/l2.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    left_2.Flip();

    if (YSOK != left_3.Decode("png/l3.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    left_3.Flip();

    if (YSOK != left_4.Decode("png/l4.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    left_4.Flip();

    if (YSOK != left_5.Decode("png/l5.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    left_5.Flip();

    if (YSOK != left_6.Decode("png/l6.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    left_6.Flip();

    // robot
    if (YSOK != rbt_left.Decode("png/robot_left.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    rbt_left.Flip();

    if (YSOK != rbt_right.Decode("png/robot_right.png")) {
        std::cout << "PNG load error." << std::endl;
        return 1;
    }
    rbt_right.Flip();

    return 0;
}

void DrawPng(double x, double y, pngFile file) {
    glRasterPos2d(x, y - 1);
    switch (file) {
        case enum_grass:
            glDrawPixels(grass.wid, grass.hei, GL_RGBA, GL_UNSIGNED_BYTE, grass.rgba);
            break;
        case enum_character_left:
            glDrawPixels(facing_left.wid, facing_left.hei, GL_RGBA, GL_UNSIGNED_BYTE, facing_left.rgba);
            break;
        case enum_character_right:
            glDrawPixels(facing_right.wid, facing_right.hei, GL_RGBA, GL_UNSIGNED_BYTE, facing_right.rgba);
            break;
        case running_right_1:
            glDrawPixels(right_1.wid, right_1.hei, GL_RGBA, GL_UNSIGNED_BYTE, right_1.rgba);
            break;
        case running_right_2:
            glDrawPixels(right_2.wid, right_2.hei, GL_RGBA, GL_UNSIGNED_BYTE, right_2.rgba);
            break;
        case running_right_3:
            glDrawPixels(right_3.wid, right_3.hei, GL_RGBA, GL_UNSIGNED_BYTE, right_3.rgba);
            break;
        case running_right_4:
            glDrawPixels(right_4.wid, right_4.hei, GL_RGBA, GL_UNSIGNED_BYTE, right_4.rgba);
            break;
        case running_right_5:
            glDrawPixels(right_5.wid, right_5.hei, GL_RGBA, GL_UNSIGNED_BYTE, right_5.rgba);
            break;
        case running_right_6:
            glDrawPixels(right_6.wid, right_6.hei, GL_RGBA, GL_UNSIGNED_BYTE, right_6.rgba);
            break;
        case running_left_1:
            glDrawPixels(left_1.wid, left_1.hei, GL_RGBA, GL_UNSIGNED_BYTE, left_1.rgba);
            break;
        case running_left_2:
            glDrawPixels(left_2.wid, left_2.hei, GL_RGBA, GL_UNSIGNED_BYTE, left_2.rgba);
            break;
        case running_left_3:
            glDrawPixels(left_3.wid, left_3.hei, GL_RGBA, GL_UNSIGNED_BYTE, left_3.rgba);
            break;
        case running_left_4:
            glDrawPixels(left_4.wid, left_4.hei, GL_RGBA, GL_UNSIGNED_BYTE, left_4.rgba);
            break;
        case running_left_5:
            glDrawPixels(left_5.wid, left_5.hei, GL_RGBA, GL_UNSIGNED_BYTE, left_5.rgba);
            break;
        case running_left_6:
            glDrawPixels(left_6.wid, left_6.hei, GL_RGBA, GL_UNSIGNED_BYTE, left_6.rgba);
            break;
        case robot_left:
            glDrawPixels(rbt_left.wid, rbt_left.hei, GL_RGBA, GL_UNSIGNED_BYTE, rbt_left.rgba);
            break;
        case robot_right:
            glDrawPixels(rbt_right.wid, rbt_right.hei, GL_RGBA, GL_UNSIGNED_BYTE, rbt_right.rgba);
            break;
        default:
            break;
    }

    return;
}