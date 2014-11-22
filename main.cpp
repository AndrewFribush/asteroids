using namespace thane;
#include <cstdlib>
#include <list>
using namespace std;

#include "objects.h"

int main(){
	srand(time(0)); //Seeds the rand based on the time so as to prevent asteroids from spawning in the same place each game.
	window(XTAM, YTAM); //Creates the game screen
	Ship N(XTAM / 2, YTAM / 2); //Creates the player ship in the center
	list<Asteroid*> A;
	list<Asteroid*>::iterator it;
	for (int i = 0; i < 1; i++){
		A.push_back(new Asteroid());
	}
	int t = key(); //t is key input for later use
	bool game_over = false;
	while( t != ESCAPE && !game_over){ //ends game on escape or when over
		N.move(); //while game runs, the ship continues to move.
		for(it = A.begin(); it != A.end(); it++){ 
			(*it)->move();
		}
		
		for(it = A.begin(); it != A.end(); it++){ //if the ship crashes, the game ends.
			if(N.crash(*it)){
				game over = true;
			}
		}
		
		
		if ( t == RIGHT){ //what happens for what keys;
			N.rota(-10);
		}
		else if ( t == LEFT){
			N.rota(10);
		}
		else if (t == UP){
			N.acelera();
		}
		
		erase(); //erases old board
		N.draw(); //draws new one
		for(it = A.begin(); it != A.end(); it++){
			(*it)->draw();
		}
		refresh();
		
		wait(10); //so the game doesn't flicker
		t = key();
	}
	wclose();
	return 0;
}