#include "Character.h"
#include "parameters.h"
#include "Stage.h"
#include <iostream>

Character::Character(int initialX, int initialY, int speed)
        : x(initialX), y(initialY), vx(0), vy(0), direction(Direction::right), CharacterSpeed(speed) {
}

int Character::getX() const {
    return x;
}

int Character::getY() const {
    return y;
}

void Character::applyGravity() {
    vy += Gravity;
}

bool Character::isOnTheGround(Stage &stage) {
    int left_edge = x;
    int right_edge = x + CharacterWidth - 1;
    int top_edge = y - (CharacterHeight - 1);
    int bottom_edge = y;

    int stepped_pixel = bottom_edge + 1;
    for (int j = left_edge / 64; j <= right_edge / 64; j++) {
        if (stage.map[(WINDOW_HEI_BLOCK - 1) - stepped_pixel / 64][j] != 'a') {
            // std::cout << "On the Ground\n";
            return true;
        }
    }
    // std::cout << "In the Air\n";
    return false;
}

bool Character::currentPosValid(Stage &stage) {
    int left_edge = x;
    int right_edge = x + CharacterWidth - 1;
    int top_edge = y - (CharacterHeight - 1);
    int bottom_edge = y;
    std::cout << "top_edge: " << top_edge << " bottom_edge: " << bottom_edge << std::endl;
    std::cout << "left_edge: " << left_edge << " right_edge: " << right_edge << std::endl;
    for (int i = ((WINDOW_HEI_BLOCK - 1) - bottom_edge / 64); i <= ((WINDOW_HEI_BLOCK - 1) - top_edge / 64); i++) {
        for (int j = left_edge / 64; j <= right_edge / 64; j++) {
            // std::cout<<"i: "<< i << " j: " << j <<std::endl;
            if (stage.map[i][j] != 'a') {
                std::cout << "FAILED" << std::endl;
                return false;
            }
        }
    }
    std::cout << "OK" << std::endl;
    return true;
}

bool Character::chkPosValid(Stage &stage, int left_edge, int right_edge, int top_edge, int bottom_edge) {
    // std::cout<<"top_edge: "<< top_edge << " bottom_edge: " << bottom_edge <<std::endl;
    // std::cout<<"left_edge: "<< left_edge << " right_edge: " << right_edge <<std::endl;
    for (int i = ((WINDOW_HEI_BLOCK - 1) - bottom_edge / 64); i <= ((WINDOW_HEI_BLOCK - 1) - top_edge / 64); i++) {
        for (int j = left_edge / 64; j <= right_edge / 64; j++) {
            // std::cout<<"i: "<< i << " j: " << j <<std::endl;
            if (stage.map[i][j] != 'a') {
                // std::cout<< "FAILED" <<std::endl;
                return false;
            }
        }
    }
    // std::cout<< "OK" <<std::endl;
    return true;
}

int Character::adaptVelocity(Stage &stage) {
    int left_edge = x;
    int right_edge = x + CharacterWidth - 1;
    int top_edge = y - (CharacterHeight - 1);
    int bottom_edge = y;
    int adapted_vx = 0;
    int adapted_vy = 0;
    if (vx > 0) {
        for (int i = 1; i <= vx; i++) {
            if (Character::chkPosValid(stage, left_edge + i, right_edge + i, top_edge, bottom_edge) == true) {
                adapted_vx = i;
            } else {
                break;
            }
        }
    } else if (vx < 0) {
        for (int i = -1; i >= vx; i--) {
            if (Character::chkPosValid(stage, left_edge + i, right_edge + i, top_edge, bottom_edge) == true) {
                adapted_vx = i;
            } else {
                break;
            }
        }
    }

    if (vy > 0) {
        for (int i = 1; i <= vy; i++) {
            if (Character::chkPosValid(stage, left_edge, right_edge, top_edge + i, bottom_edge + i) == true) {
                adapted_vy = i;
            } else {
                break;
            }
        }
    } else if (vy < 0) {
        for (int i = -1; i >= vy; i--) {
            if (Character::chkPosValid(stage, left_edge, right_edge, top_edge + i, bottom_edge + i) == true) {
                adapted_vy = i;
            } else {
                break;
            }
        }
    }

    if (Character::chkPosValid(stage, left_edge + adapted_vx, right_edge + adapted_vx, top_edge + adapted_vy,
                               bottom_edge + adapted_vy) == true) {
        vx = adapted_vx;
        vy = adapted_vy;
    } else {
        vx = 0;
        vy = adapted_vy;
    }
    return 0;
}