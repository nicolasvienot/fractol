/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:49:19 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/08 17:43:54 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_julia(t_win *win)
{
	win->params.x = 0;
	win->params.y = 0;
	win->params.x1 = -2.6;
	win->params.y1 = -2.3;
	win->params.zoom = 150;
	win->params.it_max = 50;
	win->params.old_it_max = 0;
	win->params.rc = 0.285;
	win->params.ic = 0.01;
	win->params.rz = 0;
	win->params.iz = 0;
}

void	ft_init_mandelbrot(t_win *win)
{
	win->params.x = 0;
	win->params.y = 0;
	win->params.x1 = -2.6;
	win->params.y1 = -2.3;
	win->params.zoom = 150;
	win->params.it_max = 50;
	win->params.old_it_max = 0;
	win->params.rc = 0;
	win->params.ic = 0;
	win->params.rz = 0;
	win->params.iz = 0;
}

void	ft_init_start(t_win *win)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_HOR_SIZE, WIN_VER_SIZE, "FRACT'OL");
	win->img.img_ptr = mlx_new_image(win->mlx_ptr, IMG_HOR_SIZE, IMG_VER_SIZE);
	win->img.data = mlx_get_data_addr(win->img.img_ptr, &win->img.bpp, &win->img.sizeline, &win->img.endian);
	win->vig.img_ptr = mlx_new_image(win->mlx_ptr, VIG_HOR_SIZE, WIN_VER_SIZE);
	win->vig.data = mlx_get_data_addr(win->vig.img_ptr, &win->vig.bpp, &win->vig.sizeline, &win->vig.endian);
	win->params.moove_hor = 0;
	win->params.moove_ver = 0;
	win->params.color = 999;
}
