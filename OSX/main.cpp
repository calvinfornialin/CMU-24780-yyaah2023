#include "fssimplewindow.h"
#include "Character.h"
#include "Stage.h"
#include "yspng.h"
#include "png.h"
#include "parameters.h"
#include "Hero.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	FsChangeToProgramDir();
    FsOpenWindow(16, 16, WINDOW_WID, WINDOW_HEI, 1);
    FsPollDevice();

    initPng();
    Hero player(400, 15);
    Stage stage1;
    while (1) {
        FsPollDevice();
        int key = FsInkey();

        int keyUp = FsGetKeyState(FSKEY_W);
        int keyLeft = FsGetKeyState(FSKEY_A);
        int keyRight = FsGetKeyState(FSKEY_D);

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
                // std::cout << "Current Position " << "x: " << player.getX() << "y: " << player.getY();
                break;
        }

        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        stage1.Draw();
        player.applyGravity();
        player.adaptVelocity(stage1);
        player.Update(stage1);
        player.Draw();

        FsSwapBuffers();
        FsSleep(20);
    }
}
