#pragma once
#ifndef Character_H
#define Character_H

#include "Stage.h"


class Character {

protected:

    int x;
    int y;
    int vx;
    int vy;
    static int maxMultiJump;
    static int multiJumpCnt;
    static const int CharacterWidth;
    static const int CharacterHeight;
    static const int CharacterSpeed;
    static const int JumpSpeed;
    static const int Gravity;
    static const int GroundHeight;

public:
    Character(int initialX);

    void Draw() const;

    void MoveLeft();

    void MoveRight();

    void Jump(Stage& stage);

    void Update(Stage& stage);

    int adaptVelocity(Stage& stage);

    bool chkPosValid(Stage& stage, int left_edge, int right_edge, int top_edge, int bottom_edge);

    int getX(void);

    int getY(void);

    void applyGravity(void);

    bool isOnTheGround(Stage& stage);
};

#endif