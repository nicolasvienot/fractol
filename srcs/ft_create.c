/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:20:24 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/14 00:29:09 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_create_mandelbrot_multi(void *thrds)
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
			r.rc = r.x / thrd->w->p.zoom + thrd->w->p.x1 + thrd->w->p.moove_hor;
			r.ic = r.y / thrd->w->p.zoom + thrd->w->p.y1 + thrd->w->p.moove_ver;
			r.rz = 0;
			r.iz = 0;
			ft_calc(&r, thrd->w->fract, thrd->w->p.it_max);
			if (r.a == thrd->w->p.it_max)
				mlx_put_pixel_to_image(thrd->w->img, r.x, r.y, (0));
			else
				mlx_put_pixel_to_image(thrd->w->img, r.x, r.y, \
					(thrd->w->p.color * r.a / thrd->w->p.it_max));
			r.y++;
		}
		r.x++;
	}
	pthread_exit(NULL);
}

void	*ft_create_julia_multi(void *thrds)
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
			ft_calc(&r, thrd->w->fract, thrd->w->p.it_max);
			if (r.a == thrd->w->p.it_max)
				mlx_put_pixel_to_image(thrd->w->img, r.x, r.y, (0));
			else
				mlx_put_pixel_to_image(thrd->w->img, r.x, r.y, \
					(thrd->w->p.color * r.a / thrd->w->p.it_max));
			r.y++;
		}
		r.x++;
	}
	pthread_exit(NULL);
}
