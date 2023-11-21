#include "Stage.h"

void InitMap(void){
    // load map here
    // open txt file and load the characters into map array
    for (int i=0; i<WINDOW_WID; i++){
        for (int j=0; j<WINDOW_HEI; j++){
            // read blablabla
            // map[i][j] = something
        }
    }
}

bool IsBlockPlacable(int player_x, int player_y, int direction){
    if(map[player_x][player_y] == air)
}
bool BuildBlock(int blocktype);
bool DestroyTerrain(int x, int y);
bool IsCollisionWithTerrain(int projectile_x, int projectile_y);

bool IsMoveOK(int player_x, int player_y, char key);
void Draw(void);
void PlayStageSoundEffect(void);