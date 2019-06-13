/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:17:01 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/12 19:40:03 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	plot_pix(t_all *al, int x, int y, int col)
{
	if (x < 0 || x >= WIN_SIZEX || y < 0 || y >= WIN_SIZEY)
		return ;
	al->pix[y * WIN_SIZEX + x] = col;
}

static void	draw_bresenham_flat(t_all *al, t_dot d1, t_dot d2)
{
	t_bren b;

	b.dx = d2.x - d1.x;
	b.dy = d2.y - d1.y;
	b.yi = 1;
	if (b.dy < 0)
	{
		b.yi = -1;
		b.dy = -b.dy;
	}
	b.d = b.dy * 2 - b.dx;
	b.x = d1.x;
	b.y = d1.y;
	while (b.x < d2.x)
	{
		plot_pix(al, b.x, b.y, MINIMAP_RAYCOL);
		if (b.d > 0)
		{
			b.y += b.yi;
			b.d -= b.dx * 2;
		}
		b.d += b.dy * 2;
		b.x++;
	}
}

static void	draw_bresenham_high(t_all *al, t_dot d1, t_dot d2)
{
	t_bren b;

	b.dx = d2.x - d1.x;
	b.dy = d2.y - d1.y;
	b.xi = 1;
	if (b.dx < 0)
	{
		b.xi = -1;
		b.dx = -b.dx;
	}
	b.d = b.dx * 2 - b.dy;
	b.x = d1.x;
	b.y = d1.y;
	while (b.y < d2.y)
	{
		plot_pix(al, b.x, b.y, MINIMAP_RAYCOL);
		if (b.d > 0)
		{
			b.x += b.xi;
			b.d -= b.dy * 2;
		}
		b.d += b.dx * 2;
		b.y++;
	}
}

/*
** draw_line
** draw a line using bresenham algorythm
*/

/*
** to increase performances and trigger na#is add the return
** inwin(d1) && inwin(d2) ? mlx_pixel_put(pa->mlx, pa->win, d1.x, d2.y,
** 	pa->color) : 0;
** return ;
*/

void		draw_line(t_all *al)
{
	t_dot d1;
	t_dot d2;

	d1.x = al->play.posx * al->mnmp_sc + MINIMAP_PX;
	d1.y = al->play.posy * al->mnmp_sc + MINIMAP_PY;
	d2.x = al->hitx * al->mnmp_sc + MINIMAP_PX;
	d2.y = al->hity * al->mnmp_sc + MINIMAP_PY;
	if (abs(abs(d2.y - d1.y) - abs(d2.x - d1.x)) > 10000)
		return ;
	if (abs(d2.y - d1.y) < abs(d2.x - d1.x))
		d1.x < d2.x ? draw_bresenham_flat(al, d1, d2) :
		draw_bresenham_flat(al, d2, d1);
	else
		d1.y < d2.y ? draw_bresenham_high(al, d1, d2) :
		draw_bresenham_high(al, d2, d1);
}
