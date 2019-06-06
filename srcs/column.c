/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:46:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/06 09:45:26 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	column(t_all *al, int x, double dist, int texture, double xtext)
{
	int wall_height;

	for (int y = 0; y < WIN_SIZEY / 2; y++)
		al->pix[WIN_SIZEX * y + x] = 0xf17d3c;
	for (int y = WIN_SIZEY / 2; y < WIN_SIZEY; y++)
		al->pix[WIN_SIZEX * y + x] = 0x98dbe0;
	if (dist == 0)
		return ;
	wall_height = (1 / dist) * 0.7 * WIN_SIZEX;
	for (int y = WIN_SIZEY / 2 - wall_height / 2; y < WIN_SIZEY / 2
		+ wall_height / 2; y++)
		al->pix[WIN_SIZEX * y + x] = 0xaba09d;
}
