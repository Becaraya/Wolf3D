/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:59:05 by becaraya          #+#    #+#             */
/*   Updated: 2019/06/06 10:27:14 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	init_player(t_all *al)
{
	int i;
	int j;

	al->play.speed = 1;
	al->play.look_up = 0;
	al->play.fov = 2.309;
	j = -1;
	while (++j < al->y_mx_map)
	{
		i = -1;
		while (++i < al->x_mx_map)
			if (al->map[j][i] == 0)
			{
				al->play.posx = i + 0.5;
				al->play.posy = j + 0.5;
				return ;
			}
	}
	ft_putstr_fd("Can't spawn player, map is full\n", 2);
	yeet(al);
}
/*
** faut proteger tout les mallocs...
*/
static void init_2(t_all *al)
{
	if ((al->tex = SDL_CreateTexture(al->ren, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STATIC, WIN_SIZEX, WIN_SIZEY)) == NULL)
	{
		SDL_DestroyWindow(al->win);
		SDL_DestroyRenderer(al->ren);
		free_tab_int(al->map, al->y_mx_map);
		exit(0);
	}
	if ((al->pix = ft_memalloc(WIN_SIZEX * WIN_SIZEY * sizeof(int))) == NULL)
	{
		SDL_DestroyWindow(al->win);
		SDL_DestroyRenderer(al->ren);
		SDL_DestroyTexture(al->tex);
		free_tab_int(al->map, al->y_mx_map);
		exit(0);
	}
}

static void	init(t_all *al)
{
	al->fps = 60;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		free_tab_int(al->map, al->y_mx_map);
		exit(0);
	}
	if (!(al->win = SDL_CreateWindow(WIN_TITLE, WIN_POSX, WIN_POSY, WIN_SIZEX,
				WIN_SIZEY, SDL_WINDOW_SHOWN)))
	{
		free_tab_int(al->map, al->y_mx_map);
		exit(0);
	}
	if ((al->ren = SDL_CreateRenderer(al->win, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC)) == NULL)
	{
		SDL_DestroyWindow(al->win);
		free_tab_int(al->map, al->y_mx_map);
		exit(0);
	}
	init_2(al);
	init_player(al);
}

int			main(int argc, char **argv)
{
	t_all	al;

	ft_bzero(&al, sizeof(t_all));
	if (argc == 2)
	{
		if (read_n_pars(&al, argv[1]) == EXIT_FAILURE)
			return (0);
		free_coo(al.coo);
		print_map(&al);//
		init(&al);
		main_loop(&al);
		yeet(&al);
	}
	return (0);
}
