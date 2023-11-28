#pragma once

#ifndef Hero_H
#define Hero_H

#include "Character.h"
#include "png.h"

class Hero : public Character {
public:
    Hero(int initialX, int speed);

    void Draw() const override;

    void MoveLeft() override;

    void MoveRight() override;

    void Update(Stage &stage) override;

    void Stop();

    void Jump(Stage &stage);

private:
    int JumpSpeed = 20;
    int maxMultiJump = 2;
    int multiJumpCnt = 0;
    Direction direction = Direction::right;
    bool running = false;
    int currentFrame = 0;
    int frameCounter = 0;
    int numRunningFrames = 6;
    std::vector<pngFile> runningRight;
    std::vector<pngFile> runningLeft;
};

#endif