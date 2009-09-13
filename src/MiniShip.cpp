/*
 * GamePrototype.cpp
 *
 *  Created on: Sep 11, 2009
 *      Author: davide
 */

#include "MiniShip.h"
#include <string>

using namespace std;

SDL_Surface* MiniShip::loadImage(string filename) {
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = SDL_LoadBMP( filename.c_str() );

    //If nothing went wrong in loading the image
    if( loadedImage != NULL ) {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

    //Return the optimized image
    return optimizedImage;
}

void applySurface( int x, int y, SDL_Surface* source, SDL_Surface* destination ) {
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

MiniShip::MiniShip() {
	screen = NULL;
	sprite = NULL;
	Running = true;
}

int MiniShip::onExecute() {
	if (onInit() == false) {
		return -1;
	}

	while(Running) {
		while(SDL_PollEvent(&Event)) {
			onEvent(&Event);
		}
		onLoop();
		onRender();
	}

	onCleanup();
	return 0;
}

int main(int argc, char* argv[]) {
	MiniShip gp;
	return gp.onExecute();
}


void MiniShip::onRender() {
	if (backposition.y + SCROLL_OFSSET < 0) {
		backposition.y += SCROLL_OFSSET;
	}
	else {
		backposition.y = -480;
	}
	applySurface(backposition.x, backposition.y, background, screen);
	applySurface(spritePosition.x, spritePosition.y, sprite, screen);
    SDL_Flip(screen);
}

void MiniShip::onCleanup() {
    SDL_FreeSurface(screen);
    SDL_Quit();
}
