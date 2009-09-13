/*
 * _onInit.cpp
 *
 *  Created on: Sep 13, 2009
 *      Author: davide
 */

#include "MiniShip.h"

bool MiniShip::onInit() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}

	if((screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
	{
        return false;
    }
	SDL_WM_SetCaption("miniship", NULL);
	background = loadImage("background.bmp");
	sprite = loadImage("miniship.bmp");
	spritePosition.x=390;
	spritePosition.y=225;
	return true;
}
