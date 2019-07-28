/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:59:52 by becaraya          #+#    #+#             */
/*   Updated: 2019/07/28 19:38:28 by becaraya         ###   ########.fr       */
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
# define WIN_POSY 10

# define TEXT_SIZE 512

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
# define WALK_SPEED_SLOW 1.25
# define LOOK_SENS 2.5
# define MOUSE_SENS_X 0.007
# define MOUSE_SENS_Y 2

# define SNEAK_HEIGT_PER_FRAME 50 
# define SNEAK_FRAME_COOLDOWN 10000
# define SNEAK_TOTAL_FRAME 3
# define JUMP_HEIGT_PER_FRAME 50
# define JUMP_FRAME_COOLDOWN 10000
# define JUMP_FRAME_UP 3
# define JUMP_FRAME_DOWN 6


/*
** yep, this IS flex
*/
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

typedef struct		s_dot
{
	int x;
	int	y;
}					t_dot;

typedef struct		s_crounch
{
	int		stats;
	int		st_ani;
	double	ti_ani;
}					t_crounch;

typedef struct		s_jump
{
	int		stats;
	int		st_ani;
	double	ti_ani;

}					t_jump;

typedef struct 		s_animation
{
	t_crounch		sneak;
	t_jump			jump;
}					t_animation;

/*
** The structs above are for bresenham
*/

typedef struct		s_player
{
	double			posx;
	double			posy;
	double			dir;
	double			fov;
	double			speed;
	double			look_up;
	double			sprint;
	double			brightness;
	t_animation		a;
	
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
	unsigned	ctrl:1;
}					t_keys;

typedef struct		s_mouse
{
	unsigned	left:1;
	unsigned	righ:1;
	unsigned	up:1;
	unsigned	down:1;
	unsigned	mouve:1;
	unsigned	click:1;
}					t_mouse;

typedef struct		s_all
{
	int				status;

	int				x_mx_map;
	int				y_mx_map;
	int				**map;
	t_coo			*coo;

	SDL_Window		*win;
	SDL_Texture		*tex;
	SDL_Renderer	*ren;
	unsigned int	*pix;

	unsigned int	*text1;
	unsigned int	*text2;
	unsigned int	*text30;
	unsigned int	*text31;
	unsigned int	*text32;

	unsigned int	*text4[10];

	int				hhit;
	int				hhit_ns;
	double			hhperc;
	double			hhitx;
	double			hhity;
	double			hhitdst;
	int				hit;
	int				hit_nesw;
	double			hperc;
	double			hitx;
	double			hity;
	double			hitdst;

	int				mnmp_sc;

	t_keys			k;
	SDL_Event		ev;

	t_mouse			m;

	t_player		play;
	char			fps;
	long			last_time;
	long			curr_time;
	long			tgt_time;
	int				dtime;

	SDL_Surface		*pct_menu;
	char			v0id[32];
}					t_all;

int					yeet(t_all *al);
void				main_loop(t_all *al);

unsigned int		*parse_tex(t_all *al, char *name);
void				column(t_all *al, int x, double dist);
void				draw_line(t_all *al);
void				minimap(t_all *al);
void				cast_ray(t_all *al, int x);

void				crouch(t_all *al);
void				jump(t_all *al);

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

void				game(t_all *al);
void				render(t_all *al);
void				menu(t_all *al);

#endif
