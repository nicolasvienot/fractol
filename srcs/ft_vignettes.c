/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vignettes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:57:16 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/15 12:48:22 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_create_mandelbrot_vig(t_thrd *thrd)
{
	t_render	r;

	r.zoom_x = VIG_HOR_SIZE / (X2_M - X1_M);
	r.zoom_y = VIG_VER_SIZE / (Y2_M - Y1_M);
	r.x = (VIG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (r.x < ((VIG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		r.y = 0;
		while (r.y < IMG_VER_SIZE)
		{
			r.rc = r.x / r.zoom_x + X1_M;
			r.ic = r.y / r.zoom_y + Y1_M;
			r.rz = 0;
			r.iz = 0;
			ft_calc(&r, 1, thrd->w->p.it_max);
			if (r.a == thrd->w->p.it_max && thrd->w->p.it_max > 0)
				mlx_put_pixel_to_image(thrd->w->vig, r.x, r.y, (0));
			r.y++;
		}
		r.x++;
	}
}

void	ft_create_duobrot_vig(t_thrd *thrd)
{
	t_render	r;

	r.zoom_x = VIG_HOR_SIZE / (X2_M - X1_M);
	r.zoom_y = VIG_VER_SIZE / (Y2_M - Y1_M);
	r.x = (VIG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (r.x < ((VIG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		r.y = 0;
		while (r.y < IMG_VER_SIZE)
		{
			r.rc = r.x / r.zoom_x + X1_M;
			r.ic = r.y / r.zoom_y + Y1_M;
			r.rz = 0;
			r.iz = 0;
			ft_calc(&r, 2, thrd->w->p.it_max);
			if (r.a == thrd->w->p.it_max && thrd->w->p.it_max > 0)
				mlx_put_pixel_to_image(thrd->w->vig, r.x, \
					r.y + VIG_VER_SIZE, (0));
			r.y++;
		}
		r.x++;
	}
}

void	ft_create_tricorn_vig(t_thrd *thrd)
{
	t_render	r;

	r.zoom_x = VIG_HOR_SIZE / (X2_M - X1_M);
	r.zoom_y = VIG_VER_SIZE / (Y2_M - Y1_M);
	r.x = (VIG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (r.x < ((VIG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		r.y = 0;
		while (r.y < IMG_VER_SIZE)
		{
			r.rc = r.x / r.zoom_x + X1_M;
			r.ic = r.y / r.zoom_y + Y1_M;
			r.rz = 0;
			r.iz = 0;
			ft_calc(&r, 3, thrd->w->p.it_max);
			if (r.a == thrd->w->p.it_max && thrd->w->p.it_max > 0)
				mlx_put_pixel_to_image(thrd->w->vig, r.x, \
					r.y + VIG_VER_SIZE * 2, (0));
			r.y++;
		}
		r.x++;
	}
}

void	ft_create_julia_vig(t_thrd *thrd)
{
	t_render	r;

	r.zoom_x = VIG_HOR_SIZE / (X2_J - X1_J);
	r.zoom_y = VIG_VER_SIZE / (Y2_J - Y1_J);
	r.x = (VIG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (r.x < ((VIG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		r.y = 0;
		while (r.y < IMG_VER_SIZE)
		{
			r.rc = 0.285 + thrd->w->p.rc;
			r.ic = 0.01 + thrd->w->p.ic;
			r.rz = r.x / r.zoom_x + X1_J;
			r.iz = r.y / r.zoom_y + Y1_J;
			ft_calc(&r, 6, thrd->w->p.it_max);
			if (r.a == thrd->w->p.it_max && thrd->w->p.it_max > 0)
				mlx_put_pixel_to_image(thrd->w->vig, r.x, \
					r.y + VIG_VER_SIZE * 3, (0));
			r.y++;
		}
		r.x++;
	}
}

void	ft_create_andy_vig(t_thrd *thrd)
{
	t_render	r;

	r.zoom_x = VIG_HOR_SIZE / (X2_J - X1_J);
	r.zoom_y = VIG_VER_SIZE / (Y2_J - Y1_J);
	r.x = (VIG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (r.x < ((VIG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		r.y = 0;
		while (r.y < IMG_VER_SIZE)
		{
			r.rc = 0.285 + thrd->w->p.rc;
			r.ic = 0.01 + thrd->w->p.ic;
			r.rz = r.x / r.zoom_x + X1_J;
			r.iz = r.y / r.zoom_y + Y1_J;
			ft_calc(&r, 7, thrd->w->p.it_max);
			if (r.a == thrd->w->p.it_max && thrd->w->p.it_max > 0)
				mlx_put_pixel_to_image(thrd->w->vig, r.x, \
					r.y + VIG_VER_SIZE * 4, (0));
			r.y++;
		}
		r.x++;
	}
}
