#include <cstdio>
#include "Character.h"
#include "fssimplewindow.h"
#include "parameters.h"
#include "png.h"
#include "Stage.h"
#include <iostream>
#include <stdio.h>

const int Character::CharacterWidth = 64;
const int Character::CharacterHeight = 64;
const int Character::CharacterSpeed = 15;
const int Character::JumpSpeed = 20;
const int Character::Gravity = 1;
const int Character::GroundHeight = (WINDOW_HEI-64-1);
int Character::maxMultiJump = 2;
int Character::multiJumpCnt = maxMultiJump;
Direction Character::direction = right;

Character::Character(int initialX)
        : x(initialX), y(GroundHeight), vx(0), vy(0){
}

int Character::getX(){
    return x;
}

int Character::getY(){
    return y;
}

void Character::Draw() const {
    int winWid,winHei;
    FsGetWindowSize(winWid,winHei);
    if(direction == right){
        DrawPng((double)x, (double)y, enum_character_right);
    }
    else if(direction == left){
        DrawPng((double)x, (double)y, enum_character_left);
    }
}

void Character::MoveLeft() {
    direction = left;
    vx = -CharacterSpeed;
}

void Character::MoveRight() {
    direction = right;
    vx = CharacterSpeed;
}

void Character::Jump(Stage& stage) {
    if (Character::isOnTheGround(stage) || multiJumpCnt) {
        multiJumpCnt -= 1;
        vy = -JumpSpeed;
    }
}

void Character::applyGravity() {
    vy += Gravity;
}

bool Character::isOnTheGround(Stage& stage){
    int left_edge = x;
    int right_edge = x+CharacterWidth-1;
    int top_edge = y-(CharacterHeight-1);
    int bottom_edge = y;

    int stepped_pixel = bottom_edge+1;
    for(int j=left_edge/64; j<=right_edge/64; j++){
        if(stage.map[(WINDOW_HEI_BLOCK-1) - stepped_pixel/64][j] != 'a'){
            // std::cout << "On the Ground\n";
            return true;
        }
    }
    // std::cout << "In the Air\n";
    return false;
}

void Character::Update(Stage& stage) {
    x += vx;
    vx = 0;
    y += vy;
    if(Character::isOnTheGround(stage)){
        multiJumpCnt = maxMultiJump;
    }
}

bool Character::chkPosValid(Stage& stage, int left_edge, int right_edge, int top_edge, int bottom_edge){
    // std::cout<<"top_edge: "<< top_edge << " bottom_edge: " << bottom_edge <<std::endl;
    // std::cout<<"left_edge: "<< left_edge << " right_edge: " << right_edge <<std::endl;
    for(int i=((WINDOW_HEI_BLOCK-1) - bottom_edge/64); i<=((WINDOW_HEI_BLOCK-1) - top_edge/64); i++){
        for(int j=left_edge/64; j<=right_edge/64; j++){
            // std::cout<<"i: "<< i << " j: " << j <<std::endl;
            if(stage.map[i][j] != 'a'){
                // std::cout<< "FAILED" <<std::endl;
                return false;
            }
        }
    }
    // std::cout<< "OK" <<std::endl;
    return true;
}

int Character::adaptVelocity(Stage& stage){
    // std::cout << "vy: " << vy << std::endl;
    int left_edge = x;
    int right_edge = x+CharacterWidth-1;
    int top_edge = y-(CharacterHeight-1);
    int bottom_edge = y;
    int adapted_vx = 0;
    int adapted_vy = 0;
    if(vx>0){
        for(int i=1; i<=vx; i++){
            if(Character::chkPosValid(stage, left_edge+i, right_edge+i, top_edge, bottom_edge) == true){
                adapted_vx = i;
            }
            else{
                break;
            }
        }
    }
    else if(vx<0){
        for(int i=-1; i>=vx; i--){
            if(Character::chkPosValid(stage, left_edge+i, right_edge+i, top_edge, bottom_edge) == true){
                adapted_vx = i;
            }
            else{
                break;
            }
        }
    }

    if(vy>0){
        for(int i=1; i<=vy; i++){
            if(Character::chkPosValid(stage, left_edge, right_edge, top_edge+i, bottom_edge+i) == true){
                adapted_vy = i;
            }
            else{
                break;
            }
        }
    }
    else if(vy<0){
        for(int i=-1; i>=vy; i--){
            if(Character::chkPosValid(stage, left_edge, right_edge, top_edge+i, bottom_edge+i) == true){
                adapted_vy = i;
            }
            else{
                break;
            }
        }
    }

    vx = adapted_vx;
    vy = adapted_vy;
    // std::cout << "adapted_vy: " << vy <<std::endl;
    return 0;
}