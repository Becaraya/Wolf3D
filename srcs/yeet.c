/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yeet.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:23:57 by pitriche          #+#    #+#             */
/*   Updated: 2019/06/04 10:50:25 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	yeet(t_all *al)
{
	// put all free here, and use this function to quit on every cases
	free_tab_int(al->map, al->y_mx_map);
	free(al->pix);
	SDL_DestroyWindow(al->win);
	SDL_DestroyRenderer(al->ren);
	SDL_DestroyTexture(al->tex);
	SDL_Quit();
	exit(0);
}
