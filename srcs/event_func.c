/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:44:06 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/03 17:45:20 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h> // pk t'as viré ma libft c'est tellement casse couilles de
// debugger sans printf x)

static void	keyup_func(t_all *al, SDL_KeyboardEvent kev)
{
	kev.keysym.sym == SDLK_w ? al->k.w = 0 : 0;
	kev.keysym.sym == SDLK_a ? al->k.a = 0 : 0;
	kev.keysym.sym == SDLK_s ? al->k.s = 0 : 0;
	kev.keysym.sym == SDLK_d ? al->k.d = 0 : 0;
}

void	key_func(t_all *al)
{
	SDL_KeyboardEvent kev;

	kev = al->ev.key;
	if (al->ev.type == SDL_KEYDOWN)
	{
		kev.keysym.sym == SDLK_ESCAPE ? yeet(al) : 0;
		kev.keysym.sym == SDLK_w ? al->k.w = 1 : 0;
		kev.keysym.sym == SDLK_a ? al->k.a = 1 : 0;
		kev.keysym.sym == SDLK_s ? al->k.s = 1 : 0;
		kev.keysym.sym == SDLK_d ? al->k.d = 1 : 0;
	}
	else
		keyup_func(al, kev);
}

void	mouse_func(t_all *al)
{
	printf("moootiooon  x>%u y>%u\n", al->ev.motion.x, al->ev.motion.y);
}
