// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include "Projectile.h"

int wWidth = 800;
int wHeight = 600;

int main()
{   
    srand((int)time(nullptr));
    FsOpenWindow(0, 0, wWidth, wHeight, 1);
    FsPassedTime();
    Projectile test;


    while (1)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        FsPollDevice();
        auto ms = FsPassedTime();
        double dt = (double)ms / 1000.0;

        auto key = FsInkey();
        if (FSKEY_ESC == key)
        {
            break;
        }

        //test fire projectile
        if (test.isActive() == false)
        {
            test.fireProjectile(300, 300, 100, 100);
        }

        test.moveProjectile(dt, wWidth, wHeight, 400, 300);

        test.Collision(wWidth, wHeight);

        test.Draw(247, 147, 30);

        FsSwapBuffers();
        FsSleep(5);
    }
    return 0;
}

