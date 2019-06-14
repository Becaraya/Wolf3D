/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yeet.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:23:57 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/13 16:48:19 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	yeet(t_all *al)
{
	// put all free here, and use this function to quit on every cases
	al->map ? free_tab_int(al->map, al->y_mx_map) : 0;
	if(al->win)
	{
		SDL_DestroyWindow(al->win);
		SDL_Quit();
	}
	al->ren ? SDL_DestroyRenderer(al->ren): 0;
	al->tex ? SDL_DestroyTexture(al->tex) : 0;
	al->pix ? free(al->pix) : 0;
	exit(0);
}
