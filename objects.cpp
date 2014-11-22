#include <cmath>
using namespace std;
#include "objects.h"
#include "utilities.h"

Object::Object(float _x, float _y){ //object constructor;
	x = _x;
	y = _y;
	a = 0;
	vx = 0;
	vy = 0;
}

void Object::move(){ //lets ship move
	x += vx;
	y += vy;
	limits(x, XTAM);
	limits(y, YTAM);
}

void Object::rota(double da){ //lets ship rotate
	a += da;
}

void Object::acelera(){ //acceleration
	float ax = 0.0, ay = -1.0;
	rotar(ax, ay, 0.0, 0.0, a);
	vx = - vx + ax;
	vy = vy + ay;
}

void Ship::vertices(float& x1, float& y1, float& x2, float& y2, float& x3, float& y3) const { // sets the three ship vertices
	x1 = x; y1 = y - 40;
	x2 = x - 15; y2 = y + 10;
	x3 = x + 15; y3 = y + 10;
	rotar(x1, y1, x, y, a);
	rotar(x2, y2, x, y, a);
	rotar(x3, y3, x, y, a);
}

void Ship::draw() const { //draws the ship
	float x1, y1, x2, y2, x3, y3;
	vertices(x1, y2, x2, y2, x3, y3);
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
}

bool Ship::crash(Asteroid* a) const{ //determines whether ship has crashed
	float x1, y1, x2, y2, x3, y3;
	vertices(x1, y2, x2, y2, x3, y3);
	return x1 a->between(x1, y1) || a->between(x2, y2) || a->between(x3, y3);
}

Asteroid::Asteroid():Object(luck(XTAM), luck(YTAM)){ //Asteroid constructor
	vx = luck(1.0) - 0.5;
	vy = luck(1.0) - 0.5;
}

void Asteroid::draw() const{ //draws a circle for asteroids
	circle(x, y, 40);
}

bool Asterode::between(float _x, float _y) const{ //determines if inside asteroid
	float dx = _x - x, dy = _y - y;
	sqrt(dx*dx + dy*dy) < 400;
}