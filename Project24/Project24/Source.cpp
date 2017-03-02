#include<stdlib.h>
#include"SDL/include/SDL.h"



#pragma comment (lib, "SDL/libx86/SDL2.lib")
#pragma comment (lib, "SDL/libx86/SDL2main.lib")

int main(int argc, char* args[] )
{
	bool quit = false;
	SDL_Quit();
	SDL_Window* window;
	SDL_Renderer* Renderer;
	SDL_Init(SDL_INIT_EVERYTHING);

	// Creating a rectangle
	SDL_Rect r;
	r.x = 100;
	r.y = 100;
	r.w = 50;
	r.h = 50;


	//creating the red window
	SDL_CreateWindowAndRenderer(740, 680, SDL_WINDOW_RESIZABLE, &window, &Renderer);
	
	while(quit == false)
	{
		SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
		

		//Clear the entire screen to our selected color.
		SDL_RenderClear(Renderer);

		//Up until now everything was drawn behind the scenes.This will show the new,
		//SDL_RenderPresent(Renderer);
		
	

			
			
			
			// The colour of the rectangle
			SDL_SetRenderDrawColor(Renderer, 0, 0, 255, 255);

			//Now the rectangle will be rendered
			SDL_RenderFillRect(Renderer, &r);

			//Up until now everything was drawn behind the scenes.This will show the new,
			SDL_RenderPresent(Renderer);

			//The time before it dis appears

				//TO quit with the key esc.
				SDL_Event event;
				while (SDL_PollEvent(&event))
				{

					switch (event.key.keysym.sym)
					{
					case SDLK_ESCAPE: quit = true;
						break;
					case SDLK_UP: r.y = r.y - 25;
						break;
					case SDLK_DOWN: r.y = r.y + 25;
						break;
					case SDLK_LEFT: r.x = r.x - 25;
						break;
					case SDLK_RIGHT: r.x = r.x + 25;
						break;
					}


		}
		
	}

	SDL_Quit();
	return(0);
}