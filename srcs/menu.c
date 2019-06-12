/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:18:37 by becaraya          #+#    #+#             */
/*   Updated: 2019/06/12 16:37:04 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "wolf.h"

void	print_surface(t_all *al, SDL_Surface *surface)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < WIN_SIZEX * WIN_SIZEY)
	{
		al->pix[i] = (unsigned int *)(surface->pixels)[i];
		i++;
	}
}

void	menu(t_all *al)
{
	print_surface(al, al->pct_menu);
	SDL_UpdateTexture(al->tex, 0, al->pix, WIN_SIZEX * sizeof(int));
	SDL_RenderCopy(al->ren, al->tex, 0, 0);
	SDL_RenderPresent(al->ren);
}
