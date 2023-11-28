#include "Hero.h"
#include "png.h"
#include "Character.h"

Hero::Hero(int initialX, int speed) : Character(initialX, GroundHeight, speed) {
    runningRight.push_back(running_right_1);
    runningRight.push_back(running_right_2);
    runningRight.push_back(running_right_3);
    runningRight.push_back(running_right_4);
    runningRight.push_back(running_right_5);
    runningRight.push_back(running_right_6);
    runningLeft.push_back(running_left_1);
    runningLeft.push_back(running_left_2);
    runningLeft.push_back(running_left_3);
    runningLeft.push_back(running_left_4);
    runningLeft.push_back(running_left_5);
    runningLeft.push_back(running_left_6);
}

void Hero::Draw() const {
    int winWid, winHei;
    FsGetWindowSize(winWid, winHei);
    if (direction == right) {
        if (running) {
            DrawPng((double)x, (double)y, runningRight[currentFrame]);
        } else {
            DrawPng((double) x, (double) y, enum_character_right);
        }
    } else if (direction == left) {
        if (running) {
            DrawPng((double)x, (double)y, runningLeft[currentFrame]);
        } else {
            DrawPng((double) x, (double) y, enum_character_left);
        }
    }

    for (Projectile projectile : Projectiles) {
        projectile.Draw(255, 255, 255);
    }
}

void Hero::MoveLeft() {
    direction = left;
    vx = -CharacterSpeed;
    running = true;
}

void Hero::MoveRight() {
    direction = right;
    vx = CharacterSpeed;
    running = true;
}

void Hero::Jump(Stage &stage) {
    if (Character::isOnTheGround(stage) || multiJumpCnt) {
        multiJumpCnt -= 1;
        vy = -JumpSpeed;
    }
}

void Hero::Update(Stage &stage, double dt) {
    frameCounter++;
    if (frameCounter >= 3) {
        frameCounter = 0;
        currentFrame++;
        if (currentFrame >= numRunningFrames) {
            currentFrame = 0;
        }
    }
    x += vx;
    vx = 0;
    y += vy;
    if (Character::isOnTheGround(stage)) {
        multiJumpCnt = maxMultiJump;
    }
    // DELETE INACTIVE PROJECTILES
    /*
    for (Projectile projectile : Projectiles) {
        if (projectile.isActive() == false) {
            Projectiles.erase(std::remove(Projectiles.begin(), Projectiles.end(), projectile), Projectiles.end()); 
        }
    }
    */

    // UPDATE PROJECTILES
    for (Projectile& projectile : Projectiles) {
        projectile.moveProjectile(dt, WINDOW_WID, WINDOW_HEI, 0, 0);
    }
    //std::cout << "\ndt value: " << dt << std::endl;
    //std::cout << "\nprojectile vector size: " << Projectiles.size() << std::endl;
}

void Hero::Stop() {
    running = false;
}

void Hero::projectileCollision() {

}


