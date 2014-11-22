#ifndef OBJECTS_H
#define OBJECTS_H

const float XTAM = 640, YTAM = 480; // The size of the game screen

//The classes, with Ship and Asteroid being child-objects (not sure if that's the correct term) of the class Object.

class Object{
protected:
	float x, y, a, vx, vy;
public:
	Object(float _x, float _y);
	void move();
	void rota(double da);
	void acelera();
}

class Asteroid : public Object {
public:
	Asteroid();
	void draw() const;
	bool dentro(float x, float y) const;
};

class Ship : public Object {
	void vertices(float& x1, float& y1, float& x2, float& y2, float& x3, float& y3) const;
public:
	Ship(float _x, float _y) : Object(_x, _y){}
	void draw() const;
	bool crash(Asteroid* a) const;
};

#endif // OBJECTS_H