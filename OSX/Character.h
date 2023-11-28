#pragma once
#ifndef Character_H
#define Character_H

#include "Stage.h"
#include "Projectile.h"


enum Direction {
    right,
    left
};

class Character {

protected:

    int x;
    int y;
    int vx;
    int vy;
    Direction direction;
    int CharacterSpeed;
    static const int CharacterWidth = 64;
    static const int CharacterHeight = 64;
    static const int Gravity = 1;
    static const int GroundHeight = (WINDOW_HEI - 64 - 1);
    std::vector<Projectile> Projectiles;

public:
    Character(int initialX, int initialY, int speed);

    virtual void Draw() const = 0;

    virtual void MoveLeft() = 0;

    virtual void MoveRight() = 0;

    virtual void Update(Stage &stage, double dt) = 0;
    
    virtual void projectileCollision() = 0;

    int adaptVelocity(Stage &stage);

    bool chkPosValid(Stage &stage, int left_edge, int right_edge, int top_edge, int bottom_edge);

    int getX() const;

    int getY() const;

    void applyGravity();

    bool isOnTheGround(Stage &stage);

    bool currentPosValid(Stage &stage);

    // void shoot(Hero &hero, int hei, double vx, double vy);

};

#endif