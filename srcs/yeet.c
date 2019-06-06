/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yeet.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:23:57 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/06 11:42:43 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	yeet(t_all *al)
{
	// put all free here, and use this function to quit on every cases
	free_tab_int(al->map, al->y_mx_map);
	free(al->pix);
	(al->win) ? SDL_DestroyWindow(al->win) : 0;
	(al->ren) ? SDL_DestroyRenderer(al->ren): 0;
	if (al->tex) //je suis pas sur
	{
		SDL_DestroyTexture(al->tex);
		SDL_Quit();
	}
	exit(0);
}
