#pragma once
#ifndef Projectile_H
#define Projectile_H

class Projectile
{
	int cx, cy;
	int rad;
	double vx, vy;
	bool active;
public:
	Projectile();
	void Draw(int r, int g, int b);
	void moveProjectile(double dt, int wWidth, int wHeight, int charX, int charY);
	bool Collision(int x1, int y1, int x2, int y2);
	void resetProjectile(int charX, int charY);
	void fireProjectile(int charX, int charY, double v_x, double v_y);
	bool isActive();
};

#endif

