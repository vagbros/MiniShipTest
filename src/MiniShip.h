/*
 * GamePrototype.h
 *
 *  Created on: Sep 11, 2009
 *      Author: davide
 */

#ifndef MINISHIP_H_
#define MINISHIP_H_
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCROLL_OFSSET 1
#include <SDL/SDL.h>
#include <string>

using namespace std;

class MiniShip {
private:
	bool Running;
	SDL_Surface *screen;
	SDL_Surface *sprite;
	SDL_Surface *background;
	SDL_Rect backposition;
	SDL_Rect spritePosition;
	SDL_Event Event;

public:
	MiniShip();
	int onExecute();
	bool onInit();
	void onEvent(SDL_Event*);
	void onLoop();
	void onRender();
	void onCleanup();
	SDL_Surface* loadImage(string filename);
};

#endif /* MINISHIP_H_ */
