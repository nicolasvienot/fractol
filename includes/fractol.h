/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:41:57 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/05 23:52:06 by nvienot          ###   ########.fr       */
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

# define BLACK 0
# define BLUE 255
# define GREEN 65280
# define RED 16711680
# define PURPLE 16711935
# define WHITE 16777215
# define GREY 6908265

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

typedef struct		s_win
{
	int				fract;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data;
	int				img;
	int				sizeline;
	int				bpp;
	int				endian;
	int				sizeline2;
	int				bpp2;
	int				endian2;
	char			*data2;
	void			*img_vig;
	double			moove_hor;
	double			moove_ver;
	double			zoom;
	int				it_max;
	int				old_it_max;
	double			x1;
	double			y1;
}					t_win;

typedef struct		s_complex
{
	double reel;
	double imaginaire;
}					t_complex;

void		ft_init_start(t_win **win);
void		ft_init_mandelbrot(t_win **win);
void		ft_init_julia(t_win **win);
void		ft_usage(void);
int			ft_exit(t_win **win);
void		ft_create_julia(t_win **win);
void		ft_create_mandelbrot(t_win **win);
void		ft_create_mandelbrot2(t_win **win);
void		ft_create_tricorn(t_win **win);
int			ft_print_menu(t_win **win);
int			ft_print_menu1(t_win **win);
int			ft_print_menu2(t_win **win);
int			ft_print_menu3(t_win **win);
void		mlx_put_pixel_to_image(t_win **win, int x, int y, int a);
void		mlx_put_pixel_to_image_2(t_win **win, int x, int y, int a);
void		ft_put_vig(t_win **win);
t_win		*ft_select_fractale(char *str);
void		ft_draw_fractale(t_win **win);
void		ft_reset_fractale(t_win **win);
void		ft_create_bship(t_win **win);
void		ft_create_julia2(t_win **win);

#endif
 