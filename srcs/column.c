/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:46:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/19 19:54:55 by becaraya         ###   ########.fr       */
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

void	column(t_all *al, int x, double dist)
{
	int wall_height;
	int y;

	y = -1;
	while (y++ < (WIN_SIZEY / 2) + ((al->play.look_up < (WIN_SIZEY / 2))
		? al->play.look_up : (WIN_SIZEY / 2)))
		(y < (WIN_SIZEY) && y >= 0) ? al->pix[WIN_SIZEX * y + x] = 0xf17d3c : 0;
	y--;
	while (y++ <= WIN_SIZEY)
		(y < WIN_SIZEY && y >= 0) ? al->pix[WIN_SIZEX * y + x] = 0x98dbe0 : 0;
	if (dist == 0)
		return ;
	wall_height = ((1 / dist) * 0.9 * WIN_SIZEX);
	y = (WIN_SIZEY / 2 - (wall_height) / 2) + al->play.look_up;
	while (y < (WIN_SIZEY / 2 + wall_height / 2) + al->play.look_up)
	{
		if (y <= WIN_SIZEY && y > 0)
			al->pix[WIN_SIZEX * (y - 1) + x] = al->hit == 1 ?
				shade(0xaba09d, al->play.brightness / dist)
					: shade(0xadc3c5, al->play.brightness / dist);
		y++;
	}
}
