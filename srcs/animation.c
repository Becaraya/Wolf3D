/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 18:23:15 by becaraya          #+#    #+#             */
/*   Updated: 2019/07/28 19:39:24 by becaraya         ###   ########.fr       */
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
	else if (al->play.a.sneak.ti_ani + SNEAK_FRAME_COOLDOWN < al->curr_time)
	{
		al->play.a.sneak.ti_ani = al->curr_time;
		if (al->k.ctrl == 1 && al->play.a.sneak.st_ani < SNEAK_TOTAL_FRAME)
		{
			al->play.a.sneak.st_ani++;
			al->play.look_up -= SNEAK_HEIGT_PER_FRAME;
		}
		if (al->k.ctrl == 0 && al->play.a.sneak.st_ani > 0)
		{
			al->play.a.sneak.st_ani--;
			al->play.look_up += SNEAK_HEIGT_PER_FRAME;
		}
	}
}

void			jump(t_all *al)
{
	if (al->k.space == 1 && al->play.a.jump.stats == 0)
	{
		al->play.a.jump.ti_ani = al->curr_time;
		al->play.a.jump.stats = 1;
	}
	if (al->play.a.jump.stats == 1
		&& al->play.a.jump.ti_ani + JUMP_FRAME_COOLDOWN < al->curr_time)
	{
		al->play.a.jump.ti_ani = al->curr_time;
		if (al->play.a.jump.st_ani < JUMP_FRAME_UP)
		{
			al->play.a.jump.st_ani++;
			al->play.look_up += JUMP_HEIGT_PER_FRAME;
		}
		else if (al->play.a.jump.st_ani < JUMP_FRAME_DOWN)
		{
			al->play.a.jump.st_ani++;
			al->play.look_up -= JUMP_HEIGT_PER_FRAME;
		}
		else
		{
			al->play.a.jump.st_ani = 0;
			al->play.a.jump.stats = 0;
		}
	}
}
