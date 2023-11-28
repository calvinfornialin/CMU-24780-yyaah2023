#ifndef FINALPROJECT_ROBOT_H
#define FINALPROJECT_ROBOT_H


#include "Character.h"

class Robot : public Character {

public:
    Robot(int initialX, int initialY, int speed);

    void Draw() const override;

    void MoveLeft() override;

    void MoveRight() override;

    void Update(Stage &stage) override;

    bool OnTheGround(Stage &stage, int x_pos, int y_pos);

private:
    Direction direction = Direction::right;
};


#endif