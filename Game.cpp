#include "Game.h"

Game::Game()
{
	m_Window = nullptr;
	m_Renderer = nullptr;

	//start up
	SDL_Init(SDL_INIT_VIDEO);

	//create the window
	//Title, initial x position, initial y position, width in pixels, height in pixels, window behaviour flags
	m_Window = SDL_CreateWindow("My First Window", 250, 50, 640, 480, 0);

	if (!m_Window) 
	{
		printf("WINDOW initialisation failed: %s\n", SDL_GetError());
		printf("Press any key to continue\n");
		getchar();
		return;
	}

	//now create the renderer
	//link renderer to newly created window,index rendering driver, renderer behaviour flags
	m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);

	if (!m_Renderer) 
	{
		printf("RENDERER initialisation failed: %s\n", SDL_GetError());
		printf("Press any key to continue\n");
		getchar();
		return;
	}
}

Game::~Game()
{
	//clean up
	//Destroy in reverse order they were created
	if (m_Renderer) 
	{
		SDL_DestroyRenderer(m_Renderer);
	}

	if (m_Window) 
	{
		SDL_DestroyWindow(m_Window);
	}
}

void Game::SetDisplayColour(void)
{
	if (m_Renderer) 
	{
		//Target renderer, red, green, blue, alpha
		int result = SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);

		//wipe the display to the colour we just set
		SDL_RenderClear(m_Renderer);

		//show what we've drawn
		SDL_RenderPresent(m_Renderer);

		//pause for 5 seconds
		SDL_Delay(5000);
	}


}

