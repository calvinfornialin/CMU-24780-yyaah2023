#include <cstdio>
#include "Character.h"
#include "fssimplewindow.h"

const int Character::CharacterWidth = 50;
const int Character::CharacterHeight = 50;
const int Character::CharacterSpeed = 15;
const int Character::JumpSpeed = 15;
const int Character::Gravity = 1;
const int Character::GroundHeight = 550;

Character::Character(int initialX)
        : x(initialX), y(GroundHeight), vx(0), vy(0), isJumping(false) {
}

void Character::Draw() const {
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + CharacterWidth, y);
    glVertex2i(x + CharacterWidth, y + CharacterHeight);
    glVertex2i(x, y + CharacterHeight);
    glEnd();
}

void Character::MoveLeft() {
    vx = -CharacterSpeed;
}

void Character::MoveRight() {
    vx = CharacterSpeed;
}

void Character::Jump() {
    printf("vx when jump %d\n", vx);
    if (!isJumping) {
        vy = -JumpSpeed;
        isJumping = true;
    }
}

void Character::Update() {

    x += vx;
    vx = 0;
    y += vy;

    vy += Gravity;

    if (y >= GroundHeight) {
        y = GroundHeight;
        isJumping = false;
    }
}
