/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:38:54 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/06 18:22:39 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	wall_ver(t_all *al, double ang)
{
	int x;
	double tmp;

	x = al->play.posx;
	if ((tmp = tan(ang)) == 0)
		return ;
	if (ang < M_PI)
		while (++x < al->x_mx_map)
		{
			al->vhitx = x;
			al->vhity = al->play.posy + (x - al->play.posx) / tmp;
			al->vhitdst = ((x - al->play.posx) / cos(ang));// * cos(al->play.dir - ang);
			al->vhity > 0 && al->vhity <= al->y_mx_map ? al->vhit =
			al->map[(int)al->vhity][(int)al->vhitx] : 0;
			if (al->vhit)
				return ;
		}
	else
		while (--x >= 0)
		{
			al->vhitx = x;
			al->vhity = al->play.posy + (x + 1 - al->play.posx) / tmp;
			al->vhitdst = ((x + 1 - al->play.posx) / cos(ang));// * cos(ang - al->play.dir);
			al->vhity > 0 && al->vhity <= al->y_mx_map ? al->vhit =
			al->map[(int)al->vhity][(int)al->vhitx] : 0;
			if (al->vhit)
				return ;
		}
	al->vhitdst = 69e+19;
}

/////////////////////////////////////////////////////////
static void	wall_hor(t_all *al, double ang)
{
	int y;
	double tmp;

	y = al->play.posy;
	tmp = tan(ang);
	if (ang < M_PI / 2 || ang > 3 * M_PI / 2)
		while (++y < al->y_mx_map)
		{
			al->hhity = y;
			al->hhitx = al->play.posx + (y - al->play.posy) * tmp;
			al->hhitdst = ((y - al->play.posy) / sin(ang));// * cos(al->play.dir - ang);
			al->hhitx > 0 && al->hhitx <= al->x_mx_map ? al->hhit =
			al->map[(int)al->hhity][(int)al->hhitx] : 0;
			if (al->hhit)
				return ;
		}
	else
		while (--y >= 0)
		{
			al->hhity = y;
			al->hhitx = al->play.posx + (y + 1 - al->play.posy) * tmp;
			al->hhitdst = ((y + 1 - al->play.posy) / sin(ang));
			al->hhitx > 0 && al->hhitx <= al->x_mx_map ? al->hhit =
			al->map[(int)al->hhity][(int)al->hhitx] : 0;
			if (al->hhit)
				return ;
		}
	al->hhitdst = 69e+19;
}

static void	cast_ray(t_all *al, int x)
{
	double	ang;

	al->hhit = 0;
	al->vhit = 0;
	ang = al->play.dir + al->play.fov * ((x / (double)WIN_SIZEX) - 0.5);
	while (ang > M_2PI)
		ang -= M_2PI;
	while (ang < 0)
		ang += M_2PI;
	wall_ver(al, ang);
	wall_hor(al, ang);
	if (al->hhit)
	{
		if (al->vhit)
			al->hit = al->hhitdst > al->vhitdst ? al->vhit : al->hhit;
		else
			al->hit = al->hhitdst;
	}
	else 
		al->hit = al->vhitdst;
	// printf("pl:%d,%d an%.2f %s[%.2f %.2f]\n", (int)al->play.posx, (int)al->play.posy, al->hit ? "HIT" : "no ", ang, al->hitx, al->hity);
	if (al->hhit || al->vhit)
		al->hhitdst < al->vhitdst ? column(al, x, al->hhitdst) : column(al, x, al->vhitdst);
	else
		column(al, x, 0);
	//printf("%.3f ", ang);
}

void		render(t_all *al)
{
	// ray casting shit
	for (int x = 0; x < WIN_SIZEX; x++)
		cast_ray(al, x);


	printf("\n\n\n\n\n    ");
	for (int x = 0; x < al->x_mx_map; x++)
		printf("x  ");
	printf("\n   ");
	for (int x = 0; x < al->x_mx_map; x++)
		printf("%2d ", x);
	printf("\n");
	for (int y = al->y_mx_map - 1; y > -1; --y)
	{
		printf("y%2d ", y);
		for (int x = 0; x < al->x_mx_map; x++)
			printf("%d  ", (int)al->play.posx == x && (int)al->play.posy == y ? 9 : al->map[y][x]);
		printf("\n");
	}
	
	SDL_UpdateTexture(al->tex, 0, al->pix, WIN_SIZEX * sizeof(int));
	SDL_RenderCopy(al->ren, al->tex, 0, 0);
	SDL_RenderPresent(al->ren);
}
