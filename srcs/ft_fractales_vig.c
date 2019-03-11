/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractales_vig.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:57:16 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/11 23:41:45 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_create_mandelbrot_vig(void *thrds)
{
	t_thrd		*thrd;
	double		rc;
	double		ic;
	double		rz;
	double		iz;
	double		r;
	int			a;
	int			x;
	int			y;
	double		x1 = -2.1;
	double		x2 = 0.6;
	double		y1 = -1.2;
	double		y2 = 1.2;
	double		zoom_x = VIG_HOR_SIZE / (x2 - x1);
	double		zoom_y = VIG_VER_SIZE / (y2 - y1);

	thrd = (t_thrd *)thrds;
	x = (VIG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (x < ((VIG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		y = 0;
		while (y < VIG_VER_SIZE)
		{
			rc = x / zoom_x + x1;
			ic = y / zoom_y + y1;
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
			if (a == thrd->win->params.it_max && thrd->win->params.it_max > 0)
				mlx_put_pixel_to_image(&thrd->win->vig, x, y, (0));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*ft_create_julia_vig(void *thrds)
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
	double		x1 = -1;
	double		x2 = 1;
	double		y1 = -1.2;
	double		y2 = 1.2;
	double		zoom_x = VIG_HOR_SIZE/(x2 - x1);
	double		zoom_y = VIG_VER_SIZE/(y2 - y1);

	thrd = (t_thrd *)thrds;
	x = (VIG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (x < ((VIG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		y = 0;
		while (y < VIG_VER_SIZE)
		{
			rc = 0.285;
			ic = 0.01;
			rz = x / zoom_x + x1;
			iz = y / zoom_y + y1;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < thrd->win->params.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * r * iz + ic; 
				a++;
			}
			if (a == thrd->win->params.it_max && thrd->win->params.it_max > 0)
				mlx_put_pixel_to_image(&thrd->win->vig, x, y + VIG_VER_SIZE, (0));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*ft_create_tricorn_vig(void *thrds)
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
	double		x1 = -2.1;
	double		x2 = 0.6;
	double		y1 = -1.2;
	double		y2 = 1.2;
	double		zoom_x = VIG_HOR_SIZE/(x2 - x1);
	double		zoom_y = VIG_VER_SIZE/(y2 - y1);

	thrd = (t_thrd *)thrds;
	x = (VIG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (x < ((VIG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		y = 0;
		while (y < VIG_VER_SIZE)
		{
			rc = x / zoom_x + x1;
			ic = y / zoom_y + y1;
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
			if (a == thrd->win->params.it_max && thrd->win->params.it_max > 0)
				mlx_put_pixel_to_image(&thrd->win->vig, x, (y + VIG_VER_SIZE * 2), (0));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*ft_create_bship_vig(void *thrds)
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
	double		x1 = -2.1;
	double		x2 = 0.6;
	double		y1 = -1.2;
	double		y2 = 1.2;
	double		zoom_x = VIG_HOR_SIZE/(x2 - x1);
	double		zoom_y = VIG_VER_SIZE/(y2 - y1);

	thrd = (t_thrd *)thrds;
	x = (VIG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (x < ((VIG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		y = 0;
		while (y < VIG_VER_SIZE)
		{
			rc = x / zoom_x + x1;
			ic = y / zoom_y + y1;
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
			if (a == thrd->win->params.it_max && thrd->win->params.it_max > 0)
				mlx_put_pixel_to_image(&thrd->win->vig, x, (y + VIG_VER_SIZE * 3), (0));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void	*ft_create_flower_vig(void *thrds)
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
	double		x1 = -1;
	double		x2 = 1;
	double		y1 = -1.2;
	double		y2 = 1.2;
	double		zoom_x = VIG_HOR_SIZE/(x2 - x1);
	double		zoom_y = VIG_VER_SIZE/(y2 - y1);

	thrd = (t_thrd *)thrds;
	x = (VIG_HOR_SIZE * thrd->id) / NB_THREADS;
	while (x < ((VIG_HOR_SIZE * (thrd->id + 1) / NB_THREADS)))
	{
		y = 0;
		while (y < VIG_VER_SIZE)
		{
			rc = 0.285;
			ic = 0.01;
			rz = x / zoom_x + x1;
			iz = y / zoom_y + y1;
			a = 0;
			while ((rz * rz - iz * iz) < 4 && a < thrd->win->params.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = -2 * r * iz + ic; 
				a++;
			}
			if (a == thrd->win->params.it_max && thrd->win->params.it_max > 0)
				mlx_put_pixel_to_image(&thrd->win->vig, x, (y + VIG_VER_SIZE * 4), (0));
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}
