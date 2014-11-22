#include <cstdlib>
#include <cmath>
using namespace std;
#include "utilities.h"

void rotar(float& x, float& y, float cx, float cy, float da){
	float dx = x - cx;
	float dy = y - cy;
	float r = sqrt(dx*dx + dy*dy);
	float a = atan2(dy, dx);
	a -= da/ 180 * M_PI;
	x= cy + r * cos(a);
	y = cy + r * sin(a);
}

void limits(float& f, float max){
	if(f > max){
		f -= max;
	}
	else if (f < 0){
		f += max;
	}
}

float luck(float max){
	return max * (float(rand()) / float(RAND_MAX));
}