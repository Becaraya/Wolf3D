/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:39:58 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/17 17:31:30 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	rotate(t_all *al)
{
	if (al->k.left)
		al->play.dir += LOOK_SENS * al->dtime / 1000000;
	if (al->k.righ)
		al->play.dir -= LOOK_SENS * al->dtime / 1000000;
	while (al->play.dir > M_2PI)
		al->play.dir -= M_2PI;
	while (al->play.dir < 0)
		al->play.dir += M_2PI;
	// al->k.left || al->k.righ ?
	// printf("%.3f, dtime:%d\n", al->play.dir, al->dtime) : 0;
}

static void	walls(t_all *al, double x, double y)
{
	if (x >= 0)
		!al->map[(int)al->play.posy][(int)(al->play.posx + x + HITBOX_RADIUS)] ?
			al->play.posx += x : 0;
	else
		!al->map[(int)al->play.posy][(int)(al->play.posx + x - HITBOX_RADIUS)] ?
			al->play.posx += x : 0;
	if (y >= 0)
		!al->map[(int)(al->play.posy + y + HITBOX_RADIUS)][(int)al->play.posx] ?
			al->play.posy += y : 0;
	else
		!al->map[(int)(al->play.posy + y - HITBOX_RADIUS)][(int)al->play.posx] ?
			al->play.posy += y : 0;
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
		walls(al, cos(al->play.dir) * dist, -sin(al->play.dir) * dist);
	if (al->k.d)
		walls(al, -cos(al->play.dir) * dist, sin(al->play.dir) * dist);
	if (al->k.up)
		al->look_u_d = (al->look_u_d < 1000) ? al->look_u_d + 10 : al->look_u_d;
	if (al->k.down)
		al->look_u_d = (al->look_u_d > -300) ? al->look_u_d - 10 : al->look_u_d;
	// al->k.w || al->k.a || al->k.s || al->k.d ?
	// printf("x%.1f y%.1f, dtime:%d\n", al->play.posx, al->play.posy, al->dtime) : 0;
}

void		game(t_all *al)
{
	move(al);
	rotate(al);
}
