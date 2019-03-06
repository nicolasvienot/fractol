/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractales_multi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:57:16 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/06 19:57:02 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_create_mandelbrot_multi(void *thrds)
{
	t_thread	*thrd;
	double		rc;
	double		ic;
	double		rz;
	double		iz;
	double		r;
	int			a;
	int 		x;
	int 		y;

	thrd = (t_thread *)thrds;
	x = (IMG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (x < ((IMG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		y = 0;
		while (y < IMG_VER_SIZE)
		{
			rc = x / thrd->win->zoom + thrd->win->x1 + thrd->win->moove_hor;
			ic = y / thrd->win->zoom + thrd->win->y1 + thrd->win->moove_ver;
			rz = 0;
			iz = 0;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < thrd->win->it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * r * iz + ic; 
				a++;
			}
			if (a == thrd->win->it_max)
				mlx_put_pixel_to_image(thrd->win, x, y, (0));
			else
				mlx_put_pixel_to_image(thrd->win, x, y, (a * 100000));
				// mlx_put_pixel_to_image(thrd->win, x, y, (a * 256 * 255 / thrd->win->it_max));
			y++;
		}
		x++;
	}
	return (NULL);
}
