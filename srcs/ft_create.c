/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:20:24 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/17 20:06:58 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_create_mandelbrot(void *thrds)
{
	t_thrd		*thrd;
	t_render	r;

	thrd = (t_thrd *)thrds;
	r.x = (IMG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (r.x < ((IMG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		r.y = 0;
		r.rc = r.x / thrd->w->p.zoom + thrd->w->p.x1 + thrd->w->p.moove_hor;
		while (r.y < IMG_VER_SIZE)
		{
			r.ic = r.y / thrd->w->p.zoom + thrd->w->p.y1 + thrd->w->p.moove_ver;
			r.rz = 0;
			r.iz = 0;
			ft_calc(&r, thrd->w->fract, thrd->w->p.it_max, thrd->w->p.power);
			mlx_put_pixel_to_image(thrd->w->img, r.x, r.y, ft_choose_color(r, \
				thrd->w->pal, thrd->w->p.it_max, thrd->w->p.color));
			r.y++;
		}
		r.x++;
	}
	pthread_exit(NULL);
}

void	*ft_create_julia(void *thrds)
{
	t_thrd		*thrd;
	t_render	r;

	thrd = (t_thrd *)thrds;
	r.x = (IMG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (r.x < ((IMG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		r.y = 0;
		while (r.y < IMG_VER_SIZE)
		{
			r.rc = 0.285 + thrd->w->p.rc;
			r.ic = 0.01 + thrd->w->p.ic;
			r.rz = r.x / thrd->w->p.zoom + thrd->w->p.x1 + thrd->w->p.moove_hor;
			r.iz = r.y / thrd->w->p.zoom + thrd->w->p.y1 + thrd->w->p.moove_ver;
			ft_calc(&r, thrd->w->fract, thrd->w->p.it_max, thrd->w->p.power);
			mlx_put_pixel_to_image(thrd->w->img, r.x, r.y, ft_choose_color(r, \
				thrd->w->pal, thrd->w->p.it_max, thrd->w->p.color));
			r.y++;
		}
		r.x++;
	}
	pthread_exit(NULL);
}

void	ft_create_vig(t_win *win, int test)
{
	int		x;
	int		y;

	if ((win->p.it_max != win->p.old_it_max && win->p.it_max < 70 \
		&& win->p.it_max > 3) || test == 1 || win->motion == 1)
	{
		x = -1;
		while (++x < VIG_HOR_SIZE)
		{
			y = -1;
			while (++y < IMG_VIG_VER_SIZE)
			{
				if (y == 0 || y == 131 || y == 263 || y == 395 \
					|| y == 527 || y == 659 || x == 0 || x == 189)
					mlx_put_pixel_to_image(win->vig, x, y, BORDER_VIG);
				else
					mlx_put_pixel_to_image(win->vig, x, y, (int)FONT_VIG);
			}
		}
		ft_multithreading_vig(win);
		win->p.old_it_max = win->p.it_max;
	}
}

void	ft_create_all(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
	win->img.img_ptr = mlx_new_image(win->mlx_ptr, \
		IMG_HOR_SIZE, IMG_VER_SIZE);
	win->img.data = mlx_get_data_addr(win->img.img_ptr, \
		&win->img.bpp, &win->img.sizeline, &win->img.endian);
	ft_multithreading(win);
	if (win->motion == 1)
		ft_viseur(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->img.img_ptr, 0, 0);
	if (win->vig_it == 1)
		ft_create_vig(win, 0);
	ft_print_menu(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->vig.img_ptr, 790, 20);
}
