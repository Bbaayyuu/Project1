#include<stdlib.h>
#include"SDL/include/SDL.h"
#include"SDL/include/SDL_image.h"


#pragma comment (lib, "SDL/libx86/SDL2.lib")
#pragma comment (lib, "SDL/libx86/SDL2main.lib")
#pragma comment (lib, "SDL/libx86/SDL2_image.lib")
#define MAX_BULLETS 40
int main(int argc, char* args[] )
{
	bool fire = false;
	bool quit = false;

	//SDL_Quit();
	SDL_Window* window;
	SDL_Renderer* Renderer;
	SDL_Init(SDL_INIT_EVERYTHING);

	//creating the red window
	SDL_CreateWindowAndRenderer(980, 700, SDL_WINDOW_RESIZABLE, &window, &Renderer);

	//Creating the texture of the image from a surface.
	SDL_Surface* image;
	image = IMG_Load("Spaceship.png");
	SDL_Texture* marc2 = SDL_CreateTextureFromSurface(Renderer, image);
	SDL_FreeSurface(image);

	//Texture for the enemies
	SDL_Surface* image5;
	image5 = SDL_LoadBMP("Enemy.bmp");
	SDL_Texture* marc6 = SDL_CreateTextureFromSurface(Renderer, image5);
	SDL_FreeSurface(image5);


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

	SDL_Surface* image4;
	image4 = SDL_LoadBMP("Back.bmp");
	SDL_Texture* marc5 = SDL_CreateTextureFromSurface(Renderer, image4);
	SDL_FreeSurface(image4);


	// Creating a rectangle
	SDL_Rect r;
	r.x = 100;
	r.y = 100;
	r.w = 80;
	r.h = 80;

	// Creating a rect for the enemies.
	SDL_Rect r2;
	r2.x = 1000;
	r2.y = 200;
	r2.w = 60;
	r2.h = 60;


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
	q.h = 700;

	SDL_Rect w;
	w.x = 1640;
	w.y = 0;
	w.w = 1640;
	w.h = 700;

	
	while(quit == false)
	{
		SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
		

		//Clear the entire screen to our selected color.
		SDL_RenderClear(Renderer);

		//To include the image in the size of the rectangle.
		SDL_RenderDrawRect(Renderer, &r);
		SDL_RenderFillRect(Renderer, &r);
		SDL_RenderCopy(Renderer, marc5, NULL, &w);
		SDL_RenderCopy(Renderer, marc4, NULL, &q);
		SDL_RenderCopy(Renderer, marc2, NULL, &r);
		SDL_RenderCopy(Renderer, marc6, NULL, &r2);
		
		//Movement of the background
		
		r2.x--;
		/*if (r2.x == -50)
		{
			quit = true;
			break;
			SDL_Quit;
		}*/

		//To move the background.
		q.x--;
		w.x--;
		if (q.x == -1640)
		{
			q.x = 1640;
		}
		if (w.x == -1640)
		{
			w.x = 1640;
		}


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
					case SDLK_UP: r.y = r.y - 35;
						break;
					case SDLK_DOWN: r.y = r.y + 35;
						break;
					case SDLK_LEFT: r.x = r.x - 35;
						break;
					case SDLK_RIGHT: r.x = r.x + 35;
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
			
			SDL_Delay(1);
			
	}

	SDL_Quit();
	return(0);
}