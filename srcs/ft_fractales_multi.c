/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractales_multi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:57:16 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/13 20:20:37 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_create_duobrot_multi(void *thrds)
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
			rc = x / thrd->w->p.zoom + thrd->w->p.x1 + thrd->w->p.moove_hor;
			ic = y / thrd->w->p.zoom + thrd->w->p.y1 + thrd->w->p.moove_ver;
			rz = 0;
			iz = 0;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < thrd->w->p.it_max)
			{
				r = rz;
				rz = rz * rz * rz - 3 * rz * iz * iz + rc;
				iz = 3 * r * r * iz - iz * iz * iz + ic; 
				a++;
			}
			if (a == thrd->w->p.it_max)
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (0));
			else
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (thrd->w->p.color * a / thrd->w->p.it_max));
				// mlx_put_pixel_to_image(&thrd->w->img, x, y, (a * 100000));
				// mlx_put_pixel_to_image(thrd->w->img, x, y, (a * 256 * 255 / thrd->w->p.it_max));
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
			rc = 0.285 + thrd->w->p.rc;
			ic = 0.01 + thrd->w->p.ic;
			rz = x / thrd->w->p.zoom + thrd->w->p.x1 + thrd->w->p.moove_hor;
			iz = y / thrd->w->p.zoom + thrd->w->p.y1 + thrd->w->p.moove_ver;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < thrd->w->p.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * r * iz + ic; 
				a++;
			}
			if (a == thrd->w->p.it_max)
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (0));
			else
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (thrd->w->p.color * a / thrd->w->p.it_max));
				// mlx_put_pixel_to_image(&thrd->w->img, x, y, (a * 256 * 255 / thrd->w->p.it_max));
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
			rc = x / thrd->w->p.zoom + thrd->w->p.x1 + thrd->w->p.moove_hor;
			ic = y / thrd->w->p.zoom + thrd->w->p.y1 + thrd->w->p.moove_ver;
			rz = 0;
			iz = 0;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < thrd->w->p.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = -2 * r * iz + ic; 
				a++;
			}
			if (a == thrd->w->p.it_max)
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (0));
			else
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (thrd->w->p.color * a / thrd->w->p.it_max));
				// mlx_put_pixel_to_image(&thrd->w->img, x, y, (a * 100000));
				// mlx_put_pixel_to_image(&thrd->w->img, x, y, (a * 256 * 255 / thrd->w->p.it_max));
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
			rc = x / thrd->w->p.zoom + thrd->w->p.x1 + thrd->w->p.moove_hor;
			ic = y / thrd->w->p.zoom + thrd->w->p.y1 + thrd->w->p.moove_ver;
			rz = 0;
			iz = 0;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < thrd->w->p.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * fabs(r) * fabs(iz) + ic;  
				a++;
			}
			if (a == thrd->w->p.it_max)
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (0));
			else
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (thrd->w->p.color * a / thrd->w->p.it_max));
				// mlx_put_pixel_to_image(&thrd->w->img, x, y, (a * 100000));
				// mlx_put_pixel_to_image(thrd->w->img, x, y, (a * 256 * 255 / thrd->w->p.it_max));
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
			rc = 0.285 + thrd->w->p.rc;;
			ic = 0.01 + thrd->w->p.ic;;
			rz = x / thrd->w->p.zoom + thrd->w->p.x1 + thrd->w->p.moove_hor;
			iz = y / thrd->w->p.zoom + thrd->w->p.y1 + thrd->w->p.moove_ver;
			a = 0;
			while ((rz * rz - iz * iz) < 4 && a < thrd->w->p.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * r * iz + ic; 
				a++;
			}
			if (a == thrd->w->p.it_max)
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (0));
			else
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (thrd->w->p.color * a / thrd->w->p.it_max));
				// mlx_put_pixel_to_image(thrd->w->img, x, y, (a * 256 * 255 / thrd->w->p.it_max));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*ft_create_flower3_multi(void *thrds)
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
			rc = 0.285 + thrd->w->p.rc;
			ic = 0.01 + thrd->w->p.ic;;
			rz = x / thrd->w->p.zoom + thrd->w->p.x1 + thrd->w->p.moove_hor;
			iz = y / thrd->w->p.zoom + thrd->w->p.y1 + thrd->w->p.moove_ver;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < thrd->w->p.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * fabs(r) * fabs(iz) + ic; 
				a++;
			}
			if (a == thrd->w->p.it_max)
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (0));
			else
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (thrd->w->p.color * a / thrd->w->p.it_max));
				// mlx_put_pixel_to_image(thrd->w->img, x, y, (a * 256 * 255 / thrd->w->p.it_max));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*ft_create_flower2_multi(void *thrds)
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
			rc = 0.285 + thrd->w->p.rc;;
			ic = 0.01 + thrd->w->p.ic;
			rz = x / thrd->w->p.zoom + thrd->w->p.x1 + thrd->w->p.moove_hor;
			iz = y / thrd->w->p.zoom + thrd->w->p.y1 + thrd->w->p.moove_ver;
			a = 0;
			while ((rz * rz - iz * iz) < 4 && a < thrd->w->p.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = -2 * r * iz + ic; 
				a++;
			}
			if (a == thrd->w->p.it_max)
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (0));
			else
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (thrd->w->p.color * a / thrd->w->p.it_max));
				// mlx_put_pixel_to_image(thrd->w->img, x, y, (a * 256 * 255 / thrd->w->p.it_max));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*ft_create_juliacarre_multi(void *thrds)
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
			rc = 0.285 + thrd->w->p.rc;
			ic = 0.01 + thrd->w->p.ic;
			rz = x / thrd->w->p.zoom + thrd->w->p.x1 + thrd->w->p.moove_hor;
			iz = y / thrd->w->p.zoom + thrd->w->p.y1 + thrd->w->p.moove_ver;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < thrd->w->p.it_max)
			{
				r = rz;
				rz = rz * rz * rz - 3 * rz * iz * iz + rc;
				iz = 3 * r * r * iz - iz * iz * iz + ic; 
				a++;
			}
			if (a == thrd->w->p.it_max)
				mlx_put_pixel_to_image(&thrd->w->img, x, y, 0);
			else
				mlx_put_pixel_to_image(&thrd->w->img, x, y, (thrd->w->p.color * a / thrd->w->p.it_max));
				// mlx_put_pixel_to_image(&thrd->w->img, x, y, (a * 256 * 255 / thrd->w->p.it_max));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}
