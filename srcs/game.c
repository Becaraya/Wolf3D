/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:39:58 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/04 12:52:42 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h> // pk t'as viré ma libft c'est tellement casse couilles de
// debugger sans printf x)

static void	rotate(t_all *al, int lr)
{
	if (lr == 0)
		al->play.look -= LOOK_SENS * al->dtime / 1000000;
	if (lr == 1)
		al->play.look += LOOK_SENS * al->dtime / 1000000;
	while (al->play.look > M_PI * 2)
		al->play.look -= M_PI * 2;
	while (al->play.look < 0)
		al->play.look += M_PI * 2;
	//printf("%.3f, dtime:%d\n", al->play.look, al->dtime);
}

static void	move(t_all *al, int fblr)
{
	double dist;

	dist =  al->play.speed * al->dtime / 1000000;
	al->k.lshift ? dist *= 1.8 : 0;
	if (fblr == 0)
	{
		al->play.posx += cos(al->play.look) * dist;
		al->play.posy += sin(al->play.look) * dist;
	}
	if (fblr == 1)
	{
		al->play.posx -= cos(al->play.look) * dist;
		al->play.posy -= sin(al->play.look) * dist;
	}
	if (fblr == 2)
	{
		al->play.posx += sin(al->play.look) * dist;
		al->play.posy -= cos(al->play.look) * dist;
	}
	if (fblr == 3)
	{
		al->play.posx -= sin(al->play.look) * dist;
		al->play.posy += cos(al->play.look) * dist;
	}
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
