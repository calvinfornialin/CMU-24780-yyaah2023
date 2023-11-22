#include "fssimplewindow.h"
#include "Character.h"
#include "Stage.h"
#include "yspng.h"
#include "png.h"
#include "parameters.h"

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
            case FSKEY_UP:
                player.Jump();
                break;
            case FSKEY_ESC:
                return 0;
        }

        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        stage1.Draw();
        player.Update();
        player.Draw();

        FsSwapBuffers();
        FsSleep(20);
    }
}
