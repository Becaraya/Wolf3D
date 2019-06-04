/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:39:58 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/04 15:58:24 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h> // pk t'as viré ma libft c'est tellement casse couilles de
// debugger sans printf x)

static void	rotate(t_all *al, int lr)
{
	if (lr == 0)
		al->play.dir -= LOOK_SENS * al->dtime / 1000000;
	if (lr == 1)
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

static void	move(t_all *al, int fblr)
{
	double dist;

	dist =  al->play.speed * al->dtime / 1000000;
	al->k.lshift ? dist *= 1.8 : 0;
	if (fblr == 0)
		walls(al, cos(al->play.dir) * dist, sin(al->play.dir) * dist);
	if (fblr == 1)
		walls(al, -cos(al->play.dir) * dist, -sin(al->play.dir) * dist);
	if (fblr == 2)
		walls(al, sin(al->play.dir) * dist, -cos(al->play.dir) * dist);
	if (fblr == 3)
		walls(al, -sin(al->play.dir) * dist, cos(al->play.dir) * dist);
	printf("x%.1f y%.1f, dtime:%d\n", al->play.posx, al->play.posy, al->dtime);
}

void		game(t_all *al)
{
	al->k.w ? move(al, 0) : 0;
	al->k.s ? move(al, 1) : 0;
	al->k.a ? move(al, 2) : 0;
	al->k.d ? move(al, 3) : 0;
	al->k.left ? rotate(al, 0) : 0;
	al->k.righ ? rotate(al, 1) : 0;
}
