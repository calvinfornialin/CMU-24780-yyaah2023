#include "Robot.h"
#include "png.h"
#include "Character.h"

Robot::Robot(int initialX, int initialY, int speed) : Character(initialX, initialY, speed) {

}

void Robot::Draw() const {
    int winWid, winHei;
    FsGetWindowSize(winWid, winHei);
    if (direction == right) {
        DrawPng((double)x, (double)y, robot_right);
    } else {
        DrawPng((double)x, (double)y, robot_left);
    }
}

void Robot::MoveLeft() {
    x -= CharacterSpeed;
}

void Robot::MoveRight() {
    x += CharacterSpeed;
}

void Robot::Update(Stage &stage) {
    int winWid, winHei;
    FsGetWindowSize(winWid, winHei);
    if (direction == right) {
        if (!OnTheGround(stage, x + CharacterSpeed + CharacterWidth, y) || x + CharacterWidth >= winWid) { // about to fall
            direction = left;
            MoveLeft();
        } else {
            MoveRight();
        }
    } else {
        if (!OnTheGround(stage, x - CharacterSpeed - CharacterWidth, y) || x - CharacterWidth < 0) { // about to fall
            direction = right;
            MoveRight();
        } else {
            MoveLeft();
        }
    }
}

bool Robot::OnTheGround(Stage &stage, int x_pos, int y_pos) {
    int left_edge = x_pos;
    int right_edge = x_pos + CharacterWidth - 1;
    int top_edge = y_pos - (CharacterHeight - 1);
    int bottom_edge = y_pos;

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