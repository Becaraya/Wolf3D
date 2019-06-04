/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:38:54 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/04 19:33:20 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h> // pk t'as viré ma libft c'est tellement casse couilles de
// debugger sans printf x)

static void	wall_ver(t_all *al, double ang)
{
	double x;
	double y;
	double tmp;

	x = al->play.posx;
	y = al->play.posy;
	if (ang < M_PI)
		while (y < al->y_mx_map)
		{
			if ((tmp = tan(ang)) == 0)
				return ;
			al->hitx = (int)x + 1;
			al->hity = y + al->hitx / tan(ang);
			printf("%.2f %.2f  ", al->hitx, al->hity);
			al->hity > 0 && al->hity <= al->y_mx_map ? al->hit =
			al->map[(int)al->hity][(int)al->hitx + 1] : 0;
			if (al->hit)
				return ;
			y++;
		}
	// else
	// 	while (y > 0)
	// 	{

	// 	}
}

static void	cast_ray(t_all *al, int x)
{
	double	ang;

	al->hit = 0;
	ang = al->play.dir + al->play.fov * ((x / (double)WIN_SIZEX) - 0.5);
	while (ang > M_2PI)
		ang -= M_2PI;
	while (ang < 0)
		ang += M_2PI;
	wall_ver(al, ang);
	//printf("[%.2f %.2f %.2f] ", ang, al->hitx, al->hity);
	al->hit ? column(al, x, al->hitdst, 0, 0) : column(al, x, 0, 0, 0);
	//printf("%.3f ", ang);
}

void		render(t_all *al)
{
	// ray casting shit
	for (int x = 0; x < WIN_SIZEX; x++)
		cast_ray(al, x);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	SDL_UpdateTexture(al->tex, 0, al->pix, WIN_SIZEX * sizeof(int));
	SDL_RenderCopy(al->ren, al->tex, 0, 0);
	SDL_RenderPresent(al->ren);
}
