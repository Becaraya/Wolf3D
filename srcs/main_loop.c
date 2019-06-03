/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 11:47:13 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/03 17:17:28 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h> // pk t'as viré ma libft c'est tellement casse couilles de
// debugger sans printf x)

static void	dtime(t_all *al)
{
	struct timeval	tv;

	gettimeofday(&tv, (void *)al->v0id);
	al->curr_time = tv.tv_sec * 1000000 + tv.tv_usec;
	if (al->curr_time < al->tgt_time)
	{
		usleep(al->tgt_time - al->curr_time);
		al->curr_time = al->tgt_time;
	}
	al->dtime = al->curr_time - al->last_time;
	al->last_time = al->curr_time;
	al->tgt_time = al->last_time + 1000000 / al->fps;
	//printf("%d fps\n", 1000000 / al->dtime);//
}

static void	key_func(t_all *al)
{
	al->ev.key.keysym.sym == SDLK_ESCAPE ? yeet(al) : 0;
}

static void	mouse_func(t_all *al)
{
	printf("moootiooon  x>%u y>%u\n", al->ev.motion.x, al->ev.motion.y);
}

void		main_loop(t_all *al)
{
	while (1)
	{
		dtime(al);
		while (SDL_PollEvent(&al->ev) != 0)
		{
			al->ev.type == SDL_QUIT ? yeet(al) : 0;
			if ((al->ev.type == SDL_KEYDOWN || al->ev.type == SDL_KEYUP) &&
				!al->ev.key.repeat)
				key_func(al);
			if (al->ev.type == SDL_MOUSEMOTION)
				mouse_func(al);
		}
	}
}