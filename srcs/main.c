/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:59:05 by becaraya          #+#    #+#             */
/*   Updated: 2019/06/19 11:59:26 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

// __attribute__((destructor)) void the_end(void);

static int	load_image(t_all *al)
{
	al->pct_menu = SDL_LoadBMP("../ressource/menu.bmp");
	return (0);
}

static void	init_player(t_all *al)
{
	int i;
	int j;

	al->play.brightness = 3;
	al->play.speed = WALK_SPEED;
	al->play.look_up = 0;
	al->play.fov = 1;
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

static void	init(t_all *al)
{
	al->play.look_up = 0;

	al->status = ST_GAME;
	al->fps = 60;
	al->mnmp_sc = MINIMAP_SC / (al->x_mx_map > al->y_mx_map ? al->x_mx_map :
		al->y_mx_map);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		yeet(al);
	if (!(al->win = SDL_CreateWindow(WIN_TITLE, WIN_POSX, WIN_POSY, WIN_SIZEX,
				WIN_SIZEY, SDL_WINDOW_SHOWN)))
		yeet(al);
	if ((al->ren = SDL_CreateRenderer(al->win, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC)) == NULL)
		yeet(al);
	if ((al->tex = SDL_CreateTexture(al->ren, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STATIC, WIN_SIZEX, WIN_SIZEY)) == NULL)
		yeet(al);
	if ((al->pix = ft_memalloc(WIN_SIZEX * WIN_SIZEY * sizeof(int))) == NULL)
		yeet(al);
	load_image(al);
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
		print_map(&al);
		init(&al);
		main_loop(&al);
		yeet(&al);
	}
	return (0);
}

// void    the_end(void)
// {
// 	while(420);
// }
