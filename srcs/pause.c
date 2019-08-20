/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:15:01 by becaraya          #+#    #+#             */
/*   Updated: 2019/08/20 17:49:44 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		button_res(t_all *al)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 480)
	{
		while (y < 112)
		{
			al->pix[WIN_SIZEX * (y + 100) + (x + 410)] = al->b_resume[(y
			+ 200) * TEXT_SIZE + (x + 20)];
			y++;
		}
		y = 0;
		x++;
	}
}

static void		button_quit(t_all *al)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 300)
	{
		while (y < 112)
		{
			al->pix[WIN_SIZEX * (y + 460) + (x + 490)] = al->b_quit[(y
			+ 200) * TEXT_SIZE + (x + 108)];
			y++;
		}
		y = 0;
		x++;
	}
}

static void		button_sett(t_all *al)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 480)
	{
		while (y < 112)
		{
			al->pix[WIN_SIZEX * (y + 280) + (x + 410)] = al->b_setting[(y
			+ 200) * TEXT_SIZE + (x + 20)];
			y++;
		}
		y = 0;
		x++;
	}
}

void			game_pause(t_all *al)
{
	render(al);
	button_res(al);
	button_quit(al);
	button_sett(al);
	SDL_ShowCursor(1);
	SDL_UpdateTexture(al->tex, 0, al->pix, WIN_SIZEX * sizeof(int));
	SDL_RenderCopy(al->ren, al->tex, 0, 0);
	SDL_RenderPresent(al->ren);
}
