/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:41:57 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/07 23:23:35 by nvienot          ###   ########.fr       */
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

# define BUFF_SIZE 9999
# define BUF_SIZE 1000

# define PI 3.14
# define COEF_ZOOM 1.2
# define COEF_ROTA 1
# define SIZE_MOV 0.1
# define COEF_ALT 1.2
# define COEF_Z 0.2
# define MIN_ZOOM 0.01
# define MAX_ZOOM 150
# define MAX_ALT 15
# define MIN_ALT -15

# define NB_THREADS 20
# define MAX_ALT 15
# define MIN_ALT -15

# define BLACK 0
# define BLUE 255
# define GREEN 65280
# define RED 16711680
# define PURPLE 16711935
# define WHITE 16777215
# define GREY 6908265

# define WIN_NAME "nvienot's Fract'ol"
# define WIN_HOR_SIZE 1000
# define WIN_VER_SIZE 700
# define IMG_HOR_SIZE 1000
# define IMG_VER_SIZE 700
# define VIG_HOR_SIZE 200
# define VIG_VER_SIZE 140

# define TOUCH_ESC 53
# define ARROW_LEFT 123
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define TOUCH_PLUS 69
# define TOUCH_LESS 78
# define TOUCH_O 31
# define TOUCH_P 35
# define TOUCH_I 34
# define TOUCH_R 15
# define TOUCH_T 17
# define TOUCH_M 46
# define TOUCH_C 8
# define TOUCH_STAR 67
# define PAGE_DOWN 121
# define PAGE_UP 116

typedef	struct s_win			t_win;
typedef struct s_img			t_img;
typedef struct s_params			t_params;
typedef struct s_mthrds			t_mthrds;
typedef struct s_thrd			t_thrd;

struct							s_thrd
{
	int							id;
	t_win						*win;
};

struct							s_mthrds
{
	pthread_t					threads[NB_THREADS];
	t_thrd						thrd[NB_THREADS];
};

struct							s_params
{
	double						moove_hor;
	double						moove_ver;
	double						zoom;
	int							it_max;
	int							old_it_max;
	int							x;
	int							y;
	double						x1;
	double						y1;
	double						rc;
	double						ic;
	double						rz;
	double						iz;
	int							color;
};

struct							s_img
{
	void						*img_ptr;
	void						*img_vig;
	char						*data;
	char						*data2;
	int							sizeline;
	int							sizeline2;
	int							bpp;
	int							bpp2;
	int							endian;
	int							endian2;
};

struct							s_win
{
	void						*mlx_ptr;
	void						*win_ptr;
	int							fract;
	// int							img;
	t_params					params;
	t_mthrds					mthrds;
	t_img						img;
};

/*
** draw_fractals.c
*/

/*
** draw_fractals.c
*/

/*
** draw_fractals.c
*/

/*
** draw_fractals.c
*/

/*
** draw_fractals.c
*/

/*
** draw_fractals.c
*/

void		ft_init_start(t_win *win);
void		ft_init_mandelbrot(t_win *win);
void		ft_init_julia(t_win *win);
void		ft_usage(void);
int			ft_exit(t_win *win);
int			ft_print_menu(t_win *win);
int			ft_print_menu1(t_win *win);
int			ft_print_menu2(t_win *win);
int			ft_print_menu3(t_win *win);

void		mlx_put_pixel_to_image(t_img *img, int x, int y, int a);
void		mlx_put_pixel_to_image_2(t_img *img, int x, int y, int a);

void		ft_put_vig(t_win *win);
void		ft_select_fractale(t_win *win, char *str);
void		ft_reset_fractale(t_win *win);

void		ft_multithreading(t_win *win);
void		ft_multithreading_vig(t_win *win);

void		*ft_create_mandelbrot_multi(void *thrds);
void		*ft_create_julia_multi(void *thrds);
void		*ft_create_tricorn_multi(void *thrds);
void		*ft_create_bship_multi(void *thrds);
void		*ft_create_flower_multi(void *thrds);

void		*ft_create_mandelbrot_vig(void *thrds);
void		*ft_create_julia_vig(void *thrds);
void		*ft_create_tricorn_vig(void *thrds);
void		*ft_create_bship_vig(void *thrds);
void		*ft_create_flower_vig(void *thrds);

#endif
