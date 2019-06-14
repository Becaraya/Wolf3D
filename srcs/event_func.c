/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:44:06 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/14 15:27:45 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	keyup_func(t_all *al, SDL_KeyboardEvent kev)
{
	kev.keysym.sym == SDLK_w ? al->k.w = 0 : 0;
	kev.keysym.sym == SDLK_a ? al->k.a = 0 : 0;
	kev.keysym.sym == SDLK_s ? al->k.s = 0 : 0;
	kev.keysym.sym == SDLK_d ? al->k.d = 0 : 0;
	kev.keysym.sym == SDLK_LEFT ? al->k.left = 0 : 0;
	kev.keysym.sym == SDLK_RIGHT ? al->k.righ = 0 : 0;
	kev.keysym.sym == SDLK_LSHIFT ? al->k.lshift = 0 : 0;
	kev.keysym.sym == SDLK_SPACE ? al->k.space = 0 : 0;
	kev.keysym.sym == SDLK_UP ? al->k.up = 0 : 0;
	kev.keysym.sym == SDLK_DOWN ? al->k.down = 0 : 0;
}

void	key_func(t_all *al)
{
	SDL_KeyboardEvent kev;

	kev = al->ev.key;
	if (al->ev.type == SDL_KEYDOWN)
	{
		kev.keysym.sym == SDLK_ESCAPE ? yeet(al) : 0;
		// kev.keysym.sym == SDLK_ESCAPE ? al->status = ST_PAUSE : 0;
		if (al->status == ST_GAME)
		{
			kev.keysym.sym == SDLK_w ? al->k.w = 1 : 0;
			kev.keysym.sym == SDLK_a ? al->k.a = 1 : 0;
			kev.keysym.sym == SDLK_s ? al->k.s = 1 : 0;
			kev.keysym.sym == SDLK_d ? al->k.d = 1 : 0;
			kev.keysym.sym == SDLK_LEFT ? al->k.left = 1 : 0;
			kev.keysym.sym == SDLK_RIGHT ? al->k.righ = 1 : 0;
			kev.keysym.sym == SDLK_UP ? al->k.up = 1 : 0;
			kev.keysym.sym == SDLK_DOWN ? al->k.down = 1 : 0;
			kev.keysym.sym == SDLK_LSHIFT ? al->k.lshift = 1 : 0;
			kev.keysym.sym == SDLK_SPACE ? al->k.space = 1 : 0;

		}
	}
	else
		keyup_func(al, kev);
}

void	mouse_func(t_all *al)
{
	printf("moootiooon  x>%u y>%u\n", al->ev.motion.x, al->ev.motion.y);
}
