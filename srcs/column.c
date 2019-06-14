/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:46:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/14 15:42:49 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int shade(int col, double shade)
{
	int r;
	int g;
	int b;

	r = 0;
	g = 0;
	b = 0;
	shade = shade > 1 ? 1 : shade;
	r = col >> 16 & 0xff;
	g = col >> 8 & 0xff;
	b = col & 0xff;
	return (((int)(r) << 16)
			+ ((int)(g) << 8) + ((int)(b)));
}

void	column(t_all *al, int x, double dist)
{
	int wall_height;

	// sky and ground
	for (int y = 0; y < (WIN_SIZEY / 2) + al->look_u_d; y++)
		al->pix[WIN_SIZEX * (y) + x] = 0x050505;
		// al->pix[WIN_SIZEX * y + x] = 0xf17d3c;//0x050505;
	for (int y = (WIN_SIZEY / 2)  + al->look_u_d; y < WIN_SIZEY; y++)
		al->pix[WIN_SIZEX * (y) + x] = 0x98dbe0;//0x050505;


	//avoid /0
	if (dist == 0)
		return ;

	//calculate wall height
	wall_height = ((1 / dist) * 0.9 * WIN_SIZEX); //  equation hauteur mur
	wall_height = wall_height > WIN_SIZEY ? WIN_SIZEY : wall_height;
	
	//filling the collumn
	for (int y = (WIN_SIZEY / 2 - wall_height / 2) + al->look_u_d; y < (WIN_SIZEY / 2
		+ wall_height / 2) + al->look_u_d; y++)
		al->pix[WIN_SIZEX * y + x] = al->hit == 1 ? shade(0xaba09d, 5/dist) : shade(0xadc3c5, 5/dist);
}
