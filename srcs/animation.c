/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 18:23:15 by becaraya          #+#    #+#             */
/*   Updated: 2019/07/28 18:56:06 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void		set_crouch(t_all *al, int st, double speed)
{
	al->play.a.sneak.stats = st;
	al->play.a.sneak.ti_ani = al->curr_time;
	al->play.speed = speed;
}

void			crouch(t_all *al)
{
	if (al->k.ctrl == 1 && al->play.a.sneak.stats == 0)
		set_crouch(al, 1, WALK_SPEED_SLOW);
	else if (al->k.ctrl == 0 && al->play.a.sneak.stats == 1)
		set_crouch(al, 0, WALK_SPEED);
	else if (al->play.a.sneak.ti_ani + 10000 < al->curr_time)
	{
		al->play.a.sneak.ti_ani = al->curr_time;
		if (al->k.ctrl == 1 && al->play.a.sneak.st_ani < 3)
		{
			al->play.a.sneak.st_ani++;
			al->play.look_up -= 50;
		}
		if (al->k.ctrl == 0 && al->play.a.sneak.st_ani > 0)
		{
			al->play.a.sneak.st_ani--;
			al->play.look_up += 50;
		}
	}
}
