#include "fssimplewindow.h"
#include "Character.h"
#include "Stage.h"
#include "yspng.h"
#include "png.h"
#include "parameters.h"
#include "Hero.h"
#include "Robot.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	FsChangeToProgramDir();
    FsOpenWindow(16, 16, WINDOW_WID, WINDOW_HEI, 1);
    FsPollDevice();
    FsPassedTime();

    initPng();
    Hero player(400, 15);
    Robot r1(613, 511, 5);
    Robot r2(238, 383, 5);
    Robot r3(178, 63, 5);
    Stage stage1;
    while (1) {
        FsPollDevice();
        auto ms = FsPassedTime();
        double dt = (double)ms/1000.0;
        int key = FsInkey();

        int keyUp = FsGetKeyState(FSKEY_W);
        int keyLeft = FsGetKeyState(FSKEY_A);
        int keyRight = FsGetKeyState(FSKEY_D);
        int keyShoot = FsGetKeyState(FSKEY_SPACE);

        if (keyUp && keyLeft) {
            player.MoveLeft();
            player.Jump(stage1);
        } else if (keyUp && keyRight) {
            player.MoveRight();
            player.Jump(stage1);
        } else if (keyUp) {
            player.Jump(stage1);
        } else if (keyLeft) {
            player.MoveLeft();
        } else if (keyRight) {
            player.MoveRight();
        } else {
            player.Stop();
        }

        if (keyShoot) {
            player.shoot(44, 800, 0);
        }

        switch (key) {
            case FSKEY_ESC:
                return 0;
            case FSKEY_P:
                std::cout << "Current Position " << "x: " << player.getX() << " y: " << player.getY() << std::endl;
                break;
            case FSKEY_V:
                player.currentPosValid(stage1);
                break;
            default:
//                 std::cout << "Current Position " << "x: " << player.getX() << "y: " << player.getY() << "\n";
                break;
        }

        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        stage1.Draw();
        player.applyGravity();
        player.adaptVelocity(stage1);
        player.Update(stage1, dt);
        player.Draw();

//        std::cout << "Current Position " << "x: " << r1.getX() << "y: " << r1.getY() << "\n";
        r1.Update(stage1, dt);
        r1.applyGravity();
        r1.adaptVelocity(stage1);
        r1.Draw();

        r2.Update(stage1, dt);
        r2.applyGravity();
        r2.adaptVelocity(stage1);
        r2.Draw();

        r3.Update(stage1, dt);
        r3.applyGravity();
        r3.adaptVelocity(stage1);
        r3.Draw();

        FsSwapBuffers();
        FsSleep(20);
    }
}
