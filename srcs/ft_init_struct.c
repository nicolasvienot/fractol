/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:49:19 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/06 19:54:06 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_julia(t_win *win)
{
	win->x1 = -2.6;
	win->y1 = -2.3;
	win->zoom = 150;
	win->it_max = 50;
	win->old_it_max = 0;
}

void	ft_init_mandelbrot(t_win *win)
{
	win->x1 = -2.6;
	win->y1 = -2.3;
	win->zoom = 150;
	win->it_max = 50;
	win->old_it_max = 0;
}

void	ft_init_start(t_win *win)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_HOR_SIZE, WIN_VER_SIZE, "FRACT'OL");
	win->img_ptr = mlx_new_image(win->mlx_ptr, IMG_HOR_SIZE, IMG_VER_SIZE);
	win->data = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->sizeline, &win->endian);
	win->img_vig = mlx_new_image(win->mlx_ptr, VIG_HOR_SIZE, WIN_VER_SIZE);
	win->data2 = mlx_get_data_addr(win->img_vig, &win->bpp2, &win->sizeline2, &win->endian2);
	win->moove_hor = 0;
	win->moove_ver = 0;
}
