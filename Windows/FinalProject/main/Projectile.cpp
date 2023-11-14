#include <math.h>
#include "Projectile.h"
#include "fssimplewindow.h"

const double MD_PI = 3.14159265;

Projectile::Projectile() 
{
	cx = 0;
	cy = 0;
	rad = 3;
	vx = 0;
	vy = 0;
    active = false;
}
void Projectile::Draw(int r, int g, int b)
{
    if (active)
    {
        glColor3ub(r, g, b);
        glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i < 360; i += 15)
        {
            double angle = i * MD_PI / 180;
            double x = cx + rad * cos(angle);
            double y = cy + rad * sin(angle);
            glVertex2d(x, y);
        }
        glEnd();
    }
}
void Projectile::moveProjectile(double dt, int wWidth, int wHeight, int charX, int charY)
{
    if (active)
    {
        double angle = atan2(vy, vx);
        double v = sqrt(pow(vx, 2) + pow(vy, 2));
        vx = v * cos(angle);
        vy = v * sin(angle);
        cx = cx + vx * dt;
        cy = cy + vy * dt;

        //reset upon hitting a wall
        if (cx <= 0)
        {
            resetProjectile(charX, charY);
        }
        else if (cy <= 0)
        {
            resetProjectile(charX, charY);
        }
        else if (cy >= wHeight)
        {
            resetProjectile(charX, charY);
        }
        else if (cx >= wWidth)
        {
            resetProjectile(charX, charY);
        }
    }
}
void Projectile::Collision(int windowWidth, int windowHeight)
{
    // idk, figure out some collision or something
    if (active)
    {

    }
}
void Projectile::resetProjectile(int charX, int charY)
{
    vx = 0;
    vy = 0;
    cx = 0;
    cy = 0;
    active = false;
}

void Projectile::fireProjectile(int charX, int charY, double v_x, double v_y)
{
    vx = v_x;
    vy = v_y;
    cx = charX;
    cy = charY;
    active = true;
}

bool Projectile::isActive()
{
    return active;
}