/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:59:52 by becaraya          #+#    #+#             */
/*   Updated: 2019/06/17 17:56:39 by becaraya         ###   ########.fr       */
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

# define ST_MENU 0
# define ST_GAME 1
# define ST_PAUSE 2
# define ST_SETTING 3
# define ST_CAGE 4

# define MINIMAP_SC 300
# define MINIMAP_PX 980
# define MINIMAP_PY 0
# define MINIMAP_BGCOL 0x45454b
# define MINIMAP_FGCOL 0xe6e6fa
# define MINIMAP_RAYCOL 0x00a9b7

# define HITBOX_RADIUS 0.25
# define WALK_SPEED 3.5
//		set that to 1.8 or something
# define LOOK_SENS 2.5
//		set that to 1.5
# define M_2PI 6.283185307179586476925286766559005768394338798750211641949

typedef struct		s_bren
{
	int dx;
	int dy;
	int d;
	int x;
	int y;
	int xi;
	int yi;
	int color;
}					t_bren;

typedef struct			s_dot
{
	int x;
	int	y;
}						t_dot;

/*
** The structs above are for bresenham
*/

typedef struct		s_player
{
	double	posx;
	double	posy;
	double	dir;
	double	fov;
	double	speed;
	double	look_up;
	double	sprint;
	double	brightness;
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
	unsigned	up:1;
	unsigned	down:1;
	unsigned	lshift:1;
	unsigned	space:1;
}					t_keys;

typedef struct		s_all
{
	int				status;

	int				x_mx_map;
	int				y_mx_map;
	int				**map; // ça merderas pas tkt <3 // Que Du Love
	t_coo			*coo;

	SDL_Window		*win;
	SDL_Texture		*tex;
	SDL_Renderer	*ren;
	unsigned int	*pix; // tableau de pixel a editer pour afficher, ARGB

	int				hhit;
	double			hhitx;
	double			hhity;
	double			hhitdst;
	int				hit;
	double			hitx;
	double			hity;
	double			hitdst;
	int				mnmp_sc;

	t_keys			k;
	SDL_Event		ev;

	t_player		play;
	char			fps;
	long			last_time;
	long			curr_time;
	long			tgt_time;
	int				dtime;

	char			v0id[32];
	int				look_u_d;
	
	SDL_Surface		*pct_menu;
}					t_all;

int					yeet(t_all *al);
void				main_loop(t_all *al);
void				game(t_all *al);
void				render(t_all *al);
void				column(t_all *al, int x, double dist);
void				draw_line(t_all *al);
void				minimap(t_all *al);
void				cast_ray(t_all *al, int x);

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
int					verif_n_free(t_all *al);
void				menu(t_all *al);

#endif
