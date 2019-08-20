/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:46:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/08/20 17:46:25 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		shade(int col, double shade)
{
	int r;
	int g;
	int b;

	r = 0;
	g = 0;
	b = 0;
	shade = shade > 1 ? 1 : shade;
	r = col >> 16 & 0xff;
	g = col >> 8 & 0xff;
	b = col & 0xff;
	return (((int)(r * shade) << 16)
			+ ((int)(g * shade) << 8) + ((int)(b * shade)));
}

int		anim_tex(t_all *al, int x, int y)
{
	return (al->text4[al->last_time % 1000000 / 100000][y * TEXT_SIZE + x]);
}

int		texture_color(t_all *al, double vperc)
{
	int x;
	int y;

	x = al->hperc * TEXT_SIZE;
	y = vperc * TEXT_SIZE;
	if (al->hit == 1)
		return (al->text1[y * TEXT_SIZE + x]);
	if (al->hit == 2)
		return (al->text2[y * TEXT_SIZE + x]);
	if (al->hit == 3)
		return (al->text30[y * TEXT_SIZE + x]);
	if (al->hit == 4)
		return (al->text31[y * TEXT_SIZE + x]);
	if (al->hit == 5)
		return (al->text32[y * TEXT_SIZE + x]);
	if (al->hit == 6)
		return (anim_tex(al, x, y));
	return (0);
}

void	column(t_all *al, int x, double dist)
{
	int wall_height;
	int y;
	int starty;

	y = -1;
	while (y++ < (WIN_SIZEY / 2) + ((al->play.look_up < (WIN_SIZEY / 2))
		? al->play.look_up : (WIN_SIZEY / 2)))
		(y < (WIN_SIZEY) && y >= 0) ? al->pix[WIN_SIZEX * y + x] = 0x050505 : 0;
	y--;
	while (y++ <= WIN_SIZEY)
		(y < WIN_SIZEY && y >= 0) ? al->pix[WIN_SIZEX * y + x] = 0x050505 : 0;
	if (dist == 0)
		return ;
	wall_height = ((1 / dist) * 0.9 * WIN_SIZEX);
	y = (WIN_SIZEY / 2 - (wall_height) / 2) + al->play.look_up;
	starty = y;
	while (y < (WIN_SIZEY / 2 + wall_height / 2) + al->play.look_up)
	{
		if (y <= WIN_SIZEY && y > 0)
			al->pix[WIN_SIZEX * (y - 1) + x] = shade(texture_color(al,
				(double)(y - starty) / wall_height), al->play.brightness
				/ dist);
		y++;
	}
}
