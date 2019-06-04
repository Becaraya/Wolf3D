/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:59:05 by becaraya          #+#    #+#             */
/*   Updated: 2019/06/04 11:10:10 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	init(t_all *al)
{
	al->fps = 60;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		exit(0);
	if (!(al->win = SDL_CreateWindow(WIN_TITLE, WIN_POSX, WIN_POSY, WIN_SIZEX,
				WIN_SIZEY, SDL_WINDOW_SHOWN)))
		exit(0);
	al->ren = SDL_CreateRenderer(al->win, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC);
	al->tex = SDL_CreateTexture(al->ren, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STATIC, WIN_SIZEX, WIN_SIZEY);
	al->pix = ft_memalloc(WIN_SIZEX * WIN_SIZEY * sizeof(int));
	//ft_memset(al->pix, 0xff, WIN_SIZEX * WIN_SIZEY * sizeof(int));
}

int			main(int argc, char **argv)
{
	t_all	al;

	ft_bzero(&al, sizeof(t_all));
	if (argc == 2)
	{
		init(&al);
		if (read_n_pars(&al, argv[1]) == EXIT_FAILURE)
			return (0);
		free_coo(al.coo);
		print_map(&al);
		main_loop(&al);
		yeet(&al);
	}
	return (0);
}
