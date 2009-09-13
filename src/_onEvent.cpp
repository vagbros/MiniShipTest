/*
 * _onEvent.cpp
 *
 *  Created on: Sep 13, 2009
 *      Author: davide
 */

#include "MiniShip.h"

void MiniShip::onEvent(SDL_Event* Event) {
    if(Event -> type == SDL_QUIT) {
        Running = false;
    }
    if( Event -> type == SDL_KEYDOWN ) {
    	switch( Event->key.keysym.sym ) {
    	case SDLK_UP: spritePosition.y--;
    	break;
    	case SDLK_DOWN: spritePosition.y++;
    	break;
    	case SDLK_LEFT: spritePosition.x--;
    	break;
    	case SDLK_RIGHT: spritePosition.x++;
    	break;
    	}
    }
}
