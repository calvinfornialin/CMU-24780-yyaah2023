#include "fssimplewindow.h"
#include "Character.h"
#include "Stage.h"
#include "yspng.h"
#include "png.h"
#include "parameters.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	FsChangeToProgramDir();
    FsOpenWindow(16, 16, WINDOW_WID, WINDOW_HEI, 1);
    FsPollDevice();

    initPng();
    Character player(400);
    Stage stage1;
    while (1) {
        FsPollDevice();
        int key = FsInkey();

        switch (key) {
            case FSKEY_LEFT:
                player.MoveLeft();
                break;
            case FSKEY_RIGHT:
                player.MoveRight();
                break;
            case FSKEY_SPACE:
                player.Jump(stage1);
                break;
            case FSKEY_ESC:
                return 0;
                break;
            case FSKEY_P:
                std::cout << "Current Position " << "x: " << player.getX() << " y: " << player.getY() << std::endl;
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
