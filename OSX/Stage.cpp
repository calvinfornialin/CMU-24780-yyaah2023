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
    // check the block type in front of the main character to see if we can put a new block in front of it
    // IMPORTANT:
    // also check if there is a monster occupying the spot
    // something like: if the block is air && if the block is not occupied then the spot is available to put a new block
    if(map[player_x][player_y] == air)
}
bool BuildBlock(int blocktype){
    // put a new block in front of the main character
}
bool DestroyTerrain(int x, int y){
    // some blocks are designed to be destroyable by monster or projectile
    // Destroy the block here
}
bool IsCollisionWithTerrain(int projectile_x, int projectile_y){
    // check if the projectile hits the terrain
    // this is a interface designed for projectile class to call
}

bool IsMoveOK(int player_x, int player_y, char key){
    
}
void Draw(void);
void PlayStageSoundEffect(void);