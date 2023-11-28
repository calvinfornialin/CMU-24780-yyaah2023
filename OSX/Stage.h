#pragma once

#ifndef Stage_H
#define Stage_H

// #include "Character.h"

// enum terrainType {grace, mud, air, wood, brick, water};
// unsigned char map[WINDOW_WID][WINDOW_HEI];
// Character monsters[10];

#include "yspng.h"
#include "fssimplewindow.h"
#include "parameters.h"
#include <iostream>

// class Terrain
// {
//     int InitMap(void);
//     bool IsSpaceFreeForBlock(int player_x, int player_y, int direction);
//     bool BuildBlock(int blocktype);
//     bool DestroyTerrain(int x, int y);
//     bool IsCollisionWithTerrain(int projectile_x, int projectile_y);
// };

class Stage
{
public:
    char map[WINDOW_HEI/64+2][WINDOW_WID/64] = {
        {'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'},
        {'a', 'g', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'g', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'g', 'g', 'g', 'g', 'g', 'g', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'g', 'g', 'g', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'g', 'g', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'g', 'g', 'g'},
        {'a', 'g', 'g', 'g', 'g', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'g', 'g', 'g', 'g', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}
    };

    // bool IsMoveOK(int player_x, int player_y, char key);
    void Draw(void);
    // void PlayStageSoundEffect(void);
};

#endif
