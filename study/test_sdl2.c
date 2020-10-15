/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sdl2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:58:19 by xtang             #+#    #+#             */
/*   Updated: 2020/10/15 23:16:52 by tiantian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdbool.h>

int		randint(int rmin, int rmax)
{
	return (rand() % rmax + rmin);
}

void	key_event(SDL_Renderer *renderer)
{
	int			flag;
	SDL_Event	event;
	const char	*key;

	flag = 1;
	while (flag)
	{
	// Process events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				flag = 0;
			else if (event.type == SDL_KEYDOWN)
			{
				key = SDL_GetKeyName(event.key.keysym.sym);
				if (strcmp(key, "C") == 0)
					SDL_SetRenderDrawColor(renderer, randint(0, 255),\
							randint(0, 255), randint(0, 255), randint(0, 255));
			}
		}
		// clear screen
		SDL_RenderClear(renderer);
		// Draw and show what was drawn
		SDL_RenderPresent(renderer);
	}
}

int		main(void)
{
	int				width;
	int				height;
	SDL_Window		*window;
	SDL_Renderer	*renderer;

	width = 800;
	height = 600;
	//Initialize the random number generator
	srand((unsigned int)time(NULL));
	//Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);
	//create an SDL window
	window = SDL_CreateWindow("Hello, SDL2", SDL_WINDOWPOS_UNDEFINED,\
				SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
	//Create a renderer (accelerated and in sync with the display refresh rate)
	renderer = SDL_CreateRenderer(window, -1,\
				SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	// Initial renderer color
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	key_event(renderer);
	// releae resources
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
