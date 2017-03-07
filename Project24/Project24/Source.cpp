#include<stdlib.h>
#include"SDL/include/SDL.h"


#pragma comment (lib, "SDL/libx86/SDL2.lib")
#pragma comment (lib, "SDL/libx86/SDL2main.lib")

#define MAX_BULLETS 25
int main(int argc, char* args[] )
{
	bool fire = false;
	bool quit = false;
	//SDL_Quit();
	SDL_Window* window;
	SDL_Renderer* Renderer;
	SDL_Init(SDL_INIT_EVERYTHING);

	//creating the red window
	SDL_CreateWindowAndRenderer(1640, 980, SDL_WINDOW_RESIZABLE, &window, &Renderer);

	//Creating the texture of the image from a surface.
	SDL_Surface* image;
	image = SDL_LoadBMP("Ship.bmp");
	SDL_Texture* marc2 = SDL_CreateTextureFromSurface(Renderer, image);
	SDL_FreeSurface(image);

	//Creating the texture for the bullets.
	SDL_Surface* image2;
	image2 = SDL_LoadBMP("Bullet.bmp");
	SDL_Texture* marc3 = SDL_CreateTextureFromSurface(Renderer, image2);
	SDL_FreeSurface(image2);

	//Creating the texture for the background.
	SDL_Surface* image3;
	image3 = SDL_LoadBMP("Back.bmp");
	SDL_Texture* marc4 = SDL_CreateTextureFromSurface(Renderer, image3);
	SDL_FreeSurface(image3);

	// Creating a rectangle
	SDL_Rect r;
	r.x = 100;
	r.y = 100;
	r.w = 80;
	r.h = 80;

	// Creating the shoots.
	SDL_Rect s[MAX_BULLETS];
	int bullet = 0;
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		s[i].x;
		s[i].y;
		s[i].w = 20;
		s[i].h = 20;
	}
	// Creating a background(provisional)
	SDL_Rect q;
	q.x = 0;
	q.y = 0;
	q.w = 1640;
	q.h = 980;
	
	while(quit == false)
	{
		SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
		

		//Clear the entire screen to our selected color.
		SDL_RenderClear(Renderer);

		//To include the image in the size of the rectangle.
		SDL_RenderDrawRect(Renderer, &r);
		SDL_RenderFillRect(Renderer, &r);
		SDL_RenderCopy(Renderer, marc4, NULL, &q);
		SDL_RenderCopy(Renderer, marc2, NULL, &r);
		

		for (int i = 0; i < MAX_BULLETS; i++)
		{
			s[i].x++;
			SDL_RenderCopy(Renderer, marc3, NULL, &s[i]);
		}


		SDL_RenderPresent(Renderer);
		//Now the rectangle will be rendered
		SDL_RenderFillRect(Renderer, &r);

		//Up until now everything was drawn behind the scenes.This will show the new,
		//SDL_RenderPresent(Renderer);


			//TO quit with the key esc and movemnet with  arrows.
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{

				if (event.type == SDL_KEYDOWN)
				{
					switch (event.key.keysym.sym)
					{
					case SDLK_ESCAPE: quit = true;
						break;
					case SDLK_UP: r.y = r.y - 15;
						break;
					case SDLK_DOWN: r.y = r.y + 15;
						break;
					case SDLK_LEFT: r.x = r.x - 15;
						break;
					case SDLK_RIGHT: r.x = r.x + 15;
						break;
					case SDLK_SPACE:
						fire = true;
						s[bullet].x = r.x + 80;
						s[bullet].y = r.y + 35;
						bullet++;
						if (bullet > MAX_BULLETS)
						{
							bullet = 0;
						}
						break;
					}
				
				}
			}
			
			SDL_Delay(0);
			
	}

	SDL_Quit();
	return(0);
}