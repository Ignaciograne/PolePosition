//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 540;


//SDL_Window* currentWindow = NULL; //Window
//SDL_Surface* currentScreenSurface = NULL; //Surface contained by the window
//SDL_Surface* backgroundSurface = NULL;

bool init(SDL_Window* *currentWindow, SDL_Surface* *currentScreenSurface){ //Initialize window
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initiliaze! SDL_Error: %s\n", SDL_GetError());
		success = false;
	} else {
		*currentWindow = SDL_CreateWindow("Pole Position", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (currentWindow == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		} else {
			*currentScreenSurface = SDL_GetWindowSurface(*currentWindow);
		}
	}
	return success;
}

bool loadMedia(SDL_Surface* *backgroundSurface){ //Loads media
	bool success = true;

	*backgroundSurface = SDL_LoadBMP("wallpaper.bmp");
	if (backgroundSurface == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", "wallpaper.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

bool loadMediaConfig(SDL_Surface* *backgroundSurface){ //Loads media
	bool success = true;

	*backgroundSurface = SDL_LoadBMP("configScreen.bmp");
	if (backgroundSurface == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", "configScreen.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

void closeWindow(SDL_Window* *currentWindow, SDL_Surface* *backgroundSurface){ //Shuts down SDL
	//Deallocate surface
	SDL_FreeSurface(*backgroundSurface);
	*backgroundSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(*currentWindow);
	*currentWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

///////////////////////////////////////////////
void configWindow(){
	SDL_Window* configWindow = NULL;
	SDL_Surface* configScreenSurface = NULL;
	SDL_Surface* backgroundSurface = NULL;

	if (!init(&configWindow, &configScreenSurface)){
		printf("Failed to initialize config window!\n");
	} else {
		if (!loadMediaConfig(&backgroundSurface)) {
			printf("Failed to load media in config window!\n");
		} else {
			SDL_BlitSurface(backgroundSurface, NULL, configScreenSurface, NULL);
			SDL_UpdateWindowSurface(configWindow);

			bool quit = false;
			SDL_Event e;

			while (!quit) {
				while (SDL_PollEvent(&e) != 0) {
					if (e.type == SDL_QUIT){
						closeWindow(&configWindow, &backgroundSurface);
						quit = true;
					}
					if (e.type == SDL_MOUSEBUTTONDOWN) {
						printf("Entrando trando ando");
					}
				}
			SDL_BlitSurface(backgroundSurface, NULL, configScreenSurface, NULL);
			SDL_UpdateWindowSurface(configWindow);
			}
		}
	}
}

int main(int argc, char* args[]){
	SDL_Window* currentWindow = NULL; //Window
	SDL_Surface* currentScreenSurface = NULL; //Surface contained by the window
	SDL_Surface* backgroundSurface = NULL;

	if (!init(&currentWindow, &currentScreenSurface)) { // Initialize
		printf("Failed to initialize main window!\n");
	} else {
		if (!loadMedia(&backgroundSurface)) { // Load media
			printf("Failed to load media in main window!\n");
		} else {
			SDL_BlitSurface(backgroundSurface, NULL, currentScreenSurface, NULL);
			SDL_UpdateWindowSurface(currentWindow);

			bool quit = false; // Flag for quitting loop
        		SDL_Event e;

		        while (!quit) {
                		while (SDL_PollEvent(&e) != 0) {
		                        if (e.type == SDL_QUIT)
                		                quit = true;
					if (e.type == SDL_MOUSEBUTTONDOWN) {
						//if (e.button.x > x && e.button.x < x ) // If clicked inside the "start"
						printf("x: %d \n", e.button.x);
						printf("y: %d \n", e.button.y);
						//closeWindow(&currentWindow, &backgroundSurface);
						//configWindow(); //Open configuration window
						//loadMediaConfig(&backgroundSurface);
						//if (e.button.x > x && e.button.x < x) // If clicked inside the hole
						//if (e.button.x > x && e.button.x < x) // If clicked inside the life
						//if (e.button.x > x && e.button.x < x) // If clicked inside the turbo
					}
                		}
			SDL_BlitSurface(backgroundSurface, NULL, currentScreenSurface, NULL);
                	SDL_UpdateWindowSurface(currentWindow);
        		}
		}
	}

	closeWindow(&currentWindow, &backgroundSurface);

	return 0;
}
