/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractales_multi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:57:16 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/08 00:28:29 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_create_mandelbrot_multi(void *thrds)
{
	t_thrd		*thrd;
	double		rc;
	double		ic;
	double		rz;
	double		iz;
	double		r;
	int			a;
	int 		x;
	int 		y;

	thrd = (t_thrd *)thrds;
	x = (IMG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (x < ((IMG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		y = 0;
		while (y < IMG_VER_SIZE)
		{
			rc = x / thrd->win->params.zoom + thrd->win->params.x1 + thrd->win->params.moove_hor;
			ic = y / thrd->win->params.zoom + thrd->win->params.y1 + thrd->win->params.moove_ver;
			rz = 0;
			iz = 0;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < thrd->win->params.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * r * iz + ic; 
				a++;
			}
			if (a == thrd->win->params.it_max)
				mlx_put_pixel_to_image(&thrd->win->img, x, y, (0));
			else
				mlx_put_pixel_to_image(&thrd->win->img, x, y, (a * 100000));
				// mlx_put_pixel_to_image(thrd->win->img, x, y, (a * 256 * 255 / thrd->win->params.it_max));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*ft_create_julia_multi(void *thrds)
{
	t_thrd		*thrd;
	double		rc;
	double		ic;
	double		rz;
	double		iz;
	double		r;
	int			a;
	int 		x;
	int 		y;

	thrd = (t_thrd *)thrds;
	x = (IMG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (x < ((IMG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		y = 0;
		while (y < IMG_VER_SIZE)
		{
			rc = 0.285;
			ic = 0.01;
			rz = x / thrd->win->params.zoom + thrd->win->params.x1 + thrd->win->params.moove_hor;
			iz = y / thrd->win->params.zoom + thrd->win->params.y1 + thrd->win->params.moove_ver;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < thrd->win->params.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * r * iz + ic; 
				a++;
			}
			if (a == thrd->win->params.it_max)
				mlx_put_pixel_to_image(&thrd->win->img, x, y, (0));
			else
				mlx_put_pixel_to_image(&thrd->win->img, x, y, (a * 100000));
				// mlx_put_pixel_to_image(thrd->win->img, x, y, (a * 256 * 255 / thrd->win->params.it_max));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*ft_create_tricorn_multi(void *thrds)
{
	t_thrd		*thrd;
	double		rc;
	double		ic;
	double		rz;
	double		iz;
	double		r;
	int			a;
	int 		x;
	int 		y;

	thrd = (t_thrd *)thrds;
	x = (IMG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (x < ((IMG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		y = 0;
		while (y < IMG_VER_SIZE)
		{
			rc = x / thrd->win->params.zoom + thrd->win->params.x1 + thrd->win->params.moove_hor;
			ic = y / thrd->win->params.zoom + thrd->win->params.y1 + thrd->win->params.moove_ver;
			rz = 0;
			iz = 0;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < thrd->win->params.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = -2 * r * iz + ic; 
				a++;
			}
			if (a == thrd->win->params.it_max)
				mlx_put_pixel_to_image(&thrd->win->img, x, y, (0));
			else
				// mlx_put_pixel_to_image(&thrd->win->img, x, y, (a * 100000));
				mlx_put_pixel_to_image(&thrd->win->img, x, y, (a * 256 * 255 / thrd->win->params.it_max));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*ft_create_bship_multi(void *thrds)
{
	t_thrd		*thrd;
	double		rc;
	double		ic;
	double		rz;
	double		iz;
	double		r;
	int			a;
	int 		x;
	int 		y;

	thrd = (t_thrd *)thrds;
	x = (IMG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (x < ((IMG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		y = 0;
		while (y < IMG_VER_SIZE)
		{
			rc = x / thrd->win->params.zoom + thrd->win->params.x1 + thrd->win->params.moove_hor;
			ic = y / thrd->win->params.zoom + thrd->win->params.y1 + thrd->win->params.moove_ver;
			rz = 0;
			iz = 0;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < thrd->win->params.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * fabs(r) * fabs(iz) + ic;  
				a++;
			}
			if (a == thrd->win->params.it_max)
				mlx_put_pixel_to_image(&thrd->win->img, x, y, (0));
			else
				mlx_put_pixel_to_image(&thrd->win->img, x, y, (a * 100000));
				// mlx_put_pixel_to_image(thrd->win->img, x, y, (a * 256 * 255 / thrd->win->params.it_max));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*ft_create_flower_multi(void *thrds)
{
	t_thrd		*thrd;
	double		rc;
	double		ic;
	double		rz;
	double		iz;
	double		r;
	int			a;
	int 		x;
	int 		y;

	thrd = (t_thrd *)thrds;
	x = (IMG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (x < ((IMG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		y = 0;
		while (y < IMG_VER_SIZE)
		{
			rc = 0.285;
			ic = 0.01;
			rz = x / thrd->win->params.zoom + thrd->win->params.x1 + thrd->win->params.moove_hor;
			iz = y / thrd->win->params.zoom + thrd->win->params.y1 + thrd->win->params.moove_ver;
			a = 0;
			while ((rz * rz - iz * iz) < 4 && a < thrd->win->params.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * r * iz + ic; 
				a++;
			}
			if (a == thrd->win->params.it_max)
				mlx_put_pixel_to_image(&thrd->win->img, x, y, (0));
			else
				mlx_put_pixel_to_image(&thrd->win->img, x, y, (thrd->win->params.color * a / thrd->win->params.it_max));
				// mlx_put_pixel_to_image(thrd->win->img, x, y, (a * 256 * 255 / thrd->win->params.it_max));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}
