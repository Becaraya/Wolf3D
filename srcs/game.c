/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:39:58 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/06 16:49:08 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	rotate(t_all *al)
{
	if (al->k.left)
		al->play.dir -= LOOK_SENS * al->dtime / 1000000;
	if (al->k.righ)
		al->play.dir += LOOK_SENS * al->dtime / 1000000;
	while (al->play.dir > M_2PI)
		al->play.dir -= M_2PI;
	while (al->play.dir < 0)
		al->play.dir += M_2PI;
	//printf("%.3f, dtime:%d\n", al->play.dir, al->dtime);
}

static void	walls(t_all *al, double x, double y)
{
	al->play.posx += x;
	al->play.posy += y;
	// add wall hitboxes
}

static void	move(t_all *al)
{
	double dist;

	dist = al->play.speed * al->dtime / 1000000;
	al->k.lshift ? dist *= 1.8 : 0;
	if (al->k.w)
		walls(al, sin(al->play.dir) * dist, cos(al->play.dir) * dist);
	if (al->k.s)
		walls(al, -sin(al->play.dir) * dist, -cos(al->play.dir) * dist);
	if (al->k.a)
		walls(al, -cos(al->play.dir) * dist, sin(al->play.dir) * dist);
	if (al->k.d)
		walls(al, cos(al->play.dir) * dist, -sin(al->play.dir) * dist);
	// printf("x%.1f y%.1f, dtime:%d\n", al->play.posx, al->play.posy, al->dtime);
}

void		game(t_all *al)
{
	move(al);
	rotate(al);
}
