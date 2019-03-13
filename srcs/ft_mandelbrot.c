/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:20:24 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/13 20:30:20 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calc(t_render *r, int it_max)
{
	while ((r->rz * r->rz + r->iz * r->iz) < 4 && r->a < it_max)
	{
		r->r = r->rz;
		r->rz = r->rz * r->rz - r->iz * r->iz + r->rc;
		r->iz = 2 * r->r * r->iz + r->ic;
		r->a++;
	}
}

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
			r.a = 0;
			ft_calc(&r, thrd->w->p.it_max);
			if (r.a == thrd->w->p.it_max)
				mlx_put_pixel_to_image(&thrd->w->img, r.x, r.y, (0));
			else
				mlx_put_pixel_to_image(&thrd->w->img, r.x, r.y, (thrd->w->p.color * r.a / thrd->w->p.it_max));
			r.y++;
		}
		r.x++;
	}
	return (NULL);
	pthread_exit(NULL);
}
