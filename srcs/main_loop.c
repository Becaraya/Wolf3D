/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 11:47:13 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/14 14:16:38 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	print_surface(t_all *al, SDL_Surface *surface)
{
	int i;
	int j;

	i = 0;
	j = 0;
	SDL_UnlockSurface(surface);
	while (i < WIN_SIZEX * WIN_SIZEY)
	{
		al->pix[i] = *(unsigned int *)surface->pixels++;
		i++;
	}
	SDL_LockSurface(surface);
}

void	menu(t_all *al)
{
	print_surface(al, al->pct_menu);
	SDL_UpdateTexture(al->tex, 0, al->pix, WIN_SIZEX * sizeof(int));
	SDL_RenderCopy(al->ren, al->tex, 0, 0);
	SDL_RenderPresent(al->ren);
}


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
	al->dtime > 1000000 ? al->dtime = 1000000 : 0;
	al->last_time = al->curr_time;
	al->tgt_time = al->last_time + 1000000 / al->fps;
	//printf("%d fps\n", 1000000 / al->dtime);
}

void		main_loop(t_all *al)
{
	while (1)
	{
		// printf("keys> %d%d%d%d\n", al->k.w, al->k.a, al->k.s, al->k.d);
		while (SDL_PollEvent(&al->ev) != 0)
		{
			al->ev.type == SDL_QUIT ? yeet(al) : 0;
			if ((al->ev.type == SDL_KEYDOWN || al->ev.type == SDL_KEYUP) &&
				!al->ev.key.repeat)
				key_func(al);
			if (al->ev.type == SDL_MOUSEMOTION)
				mouse_func(al);
		}
		dtime(al);
		if (al->status == ST_GAME)
		{
			game(al);
			render(al);
		}
		else
			menu(al);
	}
}