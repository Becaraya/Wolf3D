/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:37:30 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/19 20:04:00 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_rect(t_all *al, int origx, int y, int col)
{
	int tgtx;
	int tgty;
	int x;

	tgtx = origx + al->mnmp_sc;
	tgty = y + al->mnmp_sc;
	while (y < tgty)
	{
		x = origx;
		while (x < tgtx)
		{
			al->pix[y * WIN_SIZEX + x] = col;
			x++;
		}
		y++;
	}
}

void	minimap(t_all *al)
{
	int x;
	int y;

	y = 0;
	while (y < al->y_mx_map)
	{
		x = 0;
		while (x < al->x_mx_map)
		{
			draw_rect(al, MINIMAP_PX + x * al->mnmp_sc, MINIMAP_PY + y
				* al->mnmp_sc, al->map[y][x] ? MINIMAP_FGCOL : MINIMAP_BGCOL);
			x++;
		}
		y++;
	}
	x = 0;
	while (x < WIN_SIZEX)
	{
		cast_ray(al, x++);
		draw_line(al);
	}
}
