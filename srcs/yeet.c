/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yeet.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:23:57 by pitriche          #+#    #+#             */
/*   Updated: 2019/07/01 07:59:25 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	yeet(t_all *al)
{
	al->map ? free_tab_int(al->map, al->y_mx_map) : 0;
	al->pix ? free(al->pix) : 0;
	al->ren ? SDL_DestroyRenderer(al->ren) : 0;
	al->tex ? SDL_DestroyTexture(al->tex) : 0;
	if (al->win)
	{
		SDL_DestroyWindow(al->win);
		SDL_Quit();
	}
	exit(0);
}
