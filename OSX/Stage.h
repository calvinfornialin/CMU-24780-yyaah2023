#pragma once

#ifndef Stage_H
#define Stage_H

#define WINDOW_WID (800)
#define WINDOW_HEI (600)

#include "Character.h"

enum terrainType {grace, mud, air, wood, brick, water};
unsigned char map[WINDOW_WID][WINDOW_HEI];
Character monsters[10];

class Terrain
{
    int InitMap(void);
    bool IsSpaceFreeForBlock(int player_x, int player_y, int direction);
    bool BuildBlock(int blocktype);
    bool DestroyTerrain(int x, int y);
    bool IsCollisionWithTerrain(int projectile_x, int projectile_y);
};

class Stage
{
    bool IsMoveOK(int player_x, int player_y, char key);
    void Draw(void);
    void PlayStageSoundEffect(void);
};

#endif