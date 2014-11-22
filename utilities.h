#ifndef UTIL_H
#define UTIL_H

//Just some utilities that didn't fit elsewhere. Rotar helps with rotation, limits causes things to not fly otuside the screen but return on the otherside, and luck is for randomization
void rotar(float& x, float& y, float cx, float cy, float da)
void limits(float& f, float max)
float luck(float max)

#endif // UTIL_H