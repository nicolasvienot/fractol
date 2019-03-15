/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:41:57 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/15 16:47:05 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

# define COEF_ZOOM 1.2
# define SIZE_MOV 20

# define NB_THREADS 8

# define BLACK 0
# define BLUE 255
# define GREEN 65280
# define RED 16711680
# define PURPLE 16711935
# define WHITE 16777215
# define GREY 6908265
# define FONT_VIG 3026478180
# define BORDER_VIG 6579300

# define WIN_HOR_SIZE 1000
# define WIN_VER_SIZE 700
# define IMG_HOR_SIZE 1000
# define IMG_VER_SIZE 700
# define VIG_HOR_SIZE 190
# define VIG_VER_SIZE 132
# define IMG_VIG_HOR_SIZE 190
# define IMG_VIG_VER_SIZE 660
# define MRG 20

# define X1_M -2.1
# define X2_M 0.6
# define Y1_M -1.2
# define Y2_M 1.2
# define X1_J -1
# define X2_J 1
# define Y1_J -1.2
# define Y2_J 1.2

# define WIN_NAME "nvienot's Fract'ol"
# define F1 "Mandelbrot"
# define F2 "Duobrot"
# define F3 "Tricorn"
# define F4 "BurningShip"
# define F5 "Palmtree"
# define F6 "Julia"
# define F7 "Andy"
# define F8 "Microcells"
# define F9 "Brain"
# define F10 "Flower"

# define TOUCH_ESC 53
# define ARROW_LEFT 123
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define TOUCH_PLUS 69
# define TOUCH_LESS 78
# define TOUCH_R 15
# define TOUCH_Z 6
# define TOUCH_X 7
# define TOUCH_C 8
# define TOUCH_V 9
# define TOUCH_M 46
# define PAGE_DOWN 121
# define PAGE_UP 116

typedef	struct s_win	t_win;
typedef struct s_img	t_img;
typedef struct s_params	t_params;
typedef struct s_mthrds	t_mthrds;
typedef struct s_thrd	t_thrd;
typedef struct s_render	t_render;

struct					s_render
{
	double				rc;
	double				ic;
	double				rz;
	double				iz;
	double				r;
	double				zoom_x;
	double				zoom_y;
	int					a;
	int					x;
	int					y;
};

struct					s_thrd
{
	int					id;
	t_win				*w;
};

struct					s_mthrds
{
	pthread_t			threads[NB_THREADS];
	t_thrd				thrd[NB_THREADS];
};

struct					s_params
{
	double				moove_hor;
	double				moove_ver;
	double				zoom;
	int					it_max;
	int					old_it_max;
	double				x1;
	double				y1;
	double				rc;
	double				ic;
	int					color;
};

struct					s_img
{
	void				*img_ptr;
	char				*data;
	int					sizeline;
	int					bpp;
	int					endian;
};

struct					s_win
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					fract;
	int					menu;
	int					motion;
	int					vig_it;
	int					immersive;
	t_params			p;
	t_mthrds			mthrds;
	t_img				img;
	t_img				vig;
};

/*
** ft_error.c
*/

void					ft_usage(void);
int						ft_exit(t_win *win);

/*
** ft_deal_mouse.c
*/

int						deal_motion(int x, int y, t_win *win);
int						deal_mouse(int mouse, int x, int y, t_win *win);

/*
** ft_deal_key.c
*/

int						deal_key(int key, t_win *win);

/*
** ft_print.c
*/

void					ft_print_menu(t_win *w);
void					mlx_put_pixel_to_image(t_img img, int x, int y, int a);
void					ft_viseur(t_win *win);

/*
** ft_init_struct.c
*/

void					ft_init_start(t_win *win);
void					ft_init_mandelbrot(t_win *win);
void					ft_init_julia(t_win *win);

/*
** ft_select_fractales.c
*/

void					ft_select_fractale(t_win *win, char *str);
void					ft_reset_fractale(t_win *win);
void					ft_multithreading(t_win *win);
void					ft_multithreading_vig(t_win *win);

/*
** ft_vignettes.c
*/

void					ft_create_vig(t_win *win, int test);

/*
** ft_create.c
*/

void					ft_create_all(t_win *win);
void					*ft_create_mandelbrot(void *thrds);
void					*ft_create_julia(void *thrds);

/*
** ft_fractales_vig.c
*/

void					*ft_vig(void *thrds);
void					ft_create_mandelbrot_vig(t_thrd *thrd);
void					ft_create_duobrot_vig(t_thrd *thrd);
void					ft_create_tricorn_vig(t_thrd *thrd);
void					ft_create_julia_vig(t_thrd *thrd);
void					ft_create_andy_vig(t_thrd *thrd);

/*
** ft_calc.c
*/

void					ft_calc(t_render *r, int fract, int it_max);

#endif
