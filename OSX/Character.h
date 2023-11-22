#pragma once
#ifndef Character_H
#define Character_H


class Character {
protected:
    int x;
    int y;
    int vx;
    int vy;
    bool isJumping;

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

    void Jump();

    void Update();
};

#endif