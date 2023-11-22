#include "fssimplewindow.h"
#include "Character.h"

int main(void) {
    FsOpenWindow(16, 16, 800, 600, 1);
    FsPollDevice();

    Character player(400);

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

        player.Update();
        player.Draw();

        FsSwapBuffers();
        FsSleep(20);
    }
}
