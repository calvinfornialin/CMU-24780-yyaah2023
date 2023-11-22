#include "Stage.h"
#include <iostream>
#include <fstream>

int InitMap(void){
    // load map here
    // open txt file
    std::ifstream inputFile("map.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1; // Exit
    }

    for (int i=0; i<WINDOW_WID; i++){
        for (int j=0; j<WINDOW_HEI; j++){
            // read blablabla
            char c;
            if(inputFile.get(c)){
                map[i][j] = c;
            }
        }
    }

    // Close the file
    inputFile.close();
    return 0;
}

bool IsSpaceFreeForBlock(int player_x, int player_y, int direction){
    // check the block in front of the main character to see if we can put a new block in front of it
    // IMPORTANT:
    // also check if there is a monster occupying the spot
    // something like: if the block is air && if the block is not occupied then the spot is available to put a new block
    int target_x = player_x+direction;
    int target_y = player_y;
    // traverse the monsters object to see if they are occupying the block in front of the main character.
    for (int i=0; i<10; i++){
        if(monsters[i].cx == target_x && monsters[i].cy == target_y){
            return false;
        }
    }

    if(map[player_x][player_y] == air || map[player_x][player_y] == water){
        return true;
    }
    else{
        return false;
    }
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