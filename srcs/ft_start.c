/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:49:19 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/17 19:20:03 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_julia(t_win *win)
{
	win->p.x1 = -2.5;
	win->p.y1 = -1.75;
	win->p.zoom = 200;
}

void	ft_init_mandelbrot(t_win *win)
{
	win->p.x1 = -2.1;
	win->p.y1 = -1.4;
	win->p.zoom = 250;
}

void	ft_init_start(t_win *win)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, \
		WIN_HOR_SIZE, WIN_VER_SIZE, WIN_NAME);
	win->img.img_ptr = mlx_new_image(win->mlx_ptr, \
		IMG_HOR_SIZE, IMG_VER_SIZE);
	win->img.data = mlx_get_data_addr(win->img.img_ptr, \
		&win->img.bpp, &win->img.sizeline, &win->img.endian);
	win->vig.img_ptr = mlx_new_image(win->mlx_ptr, \
		IMG_VIG_HOR_SIZE, IMG_VIG_VER_SIZE);
	win->vig.data = mlx_get_data_addr(win->vig.img_ptr, \
		&win->vig.bpp, &win->vig.sizeline, &win->vig.endian);
	win->menu = 0;
	win->motion = 0;
	win->vig_it = 0;
	win->immersive = 0;
	win->p.color = 500;
	win->pal = 1;
}

void	ft_reset_fractal(t_win *win)
{
	if (win->fract <= 6)
		ft_init_mandelbrot(win);
	else if (win->fract > 6)
		ft_init_julia(win);
	win->p.moove_hor = 0;
	win->p.moove_ver = 0;
	win->p.it_max = 50;
	win->p.old_it_max = 0;
	win->p.rc = 0;
	win->p.ic = 0;
	win->p.power = 4.0;
	win->p.color = 500;
	ft_create_vig(win, 1);
}

void	ft_select_fractal(t_win *win, char *str)
{
	if (!ft_strcmp(str, F1))
		win->fract = 1;
	else if (!ft_strcmp(str, F2))
		win->fract = 2;
	else if (!ft_strcmp(str, F3))
		win->fract = 3;
	else if (!ft_strcmp(str, F4))
		win->fract = 4;
	else if (!ft_strcmp(str, F5))
		win->fract = 5;
	else if (!ft_strcmp(str, F6))
		win->fract = 6;
	else if (!ft_strcmp(str, F7))
		win->fract = 7;
	else if (!ft_strcmp(str, F8))
		win->fract = 8;
	else if (!ft_strcmp(str, F9))
		win->fract = 9;
	else if (!ft_strcmp(str, F10))
		win->fract = 10;
	else if (!ft_strcmp(str, F11))
		win->fract = 11;
	else if (!ft_strcmp(str, F12))
		win->fract = 12;
	ft_reset_fractal(win);
}
