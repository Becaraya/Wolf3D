/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:59:52 by becaraya          #+#    #+#             */
/*   Updated: 2019/06/06 10:10:35 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <fcntl.h>
# include "libft.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <sys/time.h>
# include "SDL.h"

# define WIN_TITLE "s     p     o     o     k     y"
# define WIN_SIZEX 1280
# define WIN_SIZEY 720
# define WIN_POSX 100
# define WIN_POSY 100

# define LOOK_SENS 1.5

# define M_2PI 6.283185307179586476925286766559005768394338798750211641949

typedef struct		s_player
{
	double	posx;
	double	posy;
	double	dir;
	double	fov;
	double	speed;
	double	look_up;
}					t_player;

typedef struct		s_coo
{
	int				x;
	int				y;
	int				z;
	struct s_coo	*next;
}					t_coo;

typedef struct		s_keys
{
	unsigned	w:1;
	unsigned	a:1;
	unsigned	s:1;
	unsigned	d:1;
	unsigned	left:1;
	unsigned	righ:1;
	unsigned	lshift:1;
}					t_keys;

typedef struct		s_all
{
	int				x_mx_map;
	int				y_mx_map;
	int				**map; // ça merderas pas tkt <3 // Que Du Love
	t_coo			*coo;

	SDL_Window		*win;
	SDL_Texture		*tex;
	SDL_Renderer	*ren;
	unsigned int	*pix; // tableau de pixel a editer pour afficher, ARGB

	int				hit;
	double			hitx;
	double			hity;
	double			hitdst;

	t_keys			k;
	SDL_Event		ev;

	t_player		play;
	char			fps;
	long			last_time;
	long			curr_time;
	long			tgt_time;
	int				dtime;

	char			v0id[32];
}					t_all;

int					yeet(t_all *al);
void				main_loop(t_all *al);
void				game(t_all *al);
void				render(t_all *al);
void				column(t_all *al, int x, double dist, int texture, double xtext);

void				key_func(t_all *al);
void				mouse_func(t_all *al);

int					pars(t_all *al, char *str, int fd);
int					len_ti(char **tmp);
int					*intsub(t_all *al, int i, int j);
int					ft_is_valid_str(char *str);
int					ft_is_valid_tab(char **str, t_all *al);
void				print_map(t_all *al);
int					ft_add_coo(t_all *al, int x, int y, int z);
int					list_to_tab(t_all *al);
void				free_coo(t_coo *coo);
void				free_tab_int(int **tab, int y);
void				free_tab_str(char **str);
int					read_n_pars(t_all *al, char *argv);

#endif
