/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:49:19 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/14 01:10:17 by nvienot          ###   ########.fr       */
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
	win->vig.img_ptr = mlx_new_image(win->mlx_ptr, VIG_HOR_SIZE, WIN_VER_SIZE);
	win->vig.data = mlx_get_data_addr(win->vig.img_ptr, \
		&win->vig.bpp, &win->vig.sizeline, &win->vig.endian);
	win->motion = 0;
	win->vig_it = 0;
	win->p.color = 999;
}
