/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractales.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:57:16 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/07 20:43:39 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_create_tricorn(t_win *win)
{
	double		rc;
	double		ic;
	double		rz;
	double		iz;
	double		r;
	int			a;
	int 		x;
	int 		y;

	x = 0;
	while (x < IMG_HOR_SIZE)
	{
		y = 0;
		while (y < IMG_VER_SIZE)
		{
			rc = x / win->params.zoom + win->params.x1 + win->params.moove_hor;
			ic = y / win->params.zoom + win->params.y1 + win->params.moove_ver;
			rz = 0;
			iz = 0;
			a = 0;
			while (rz * rz + iz * iz < 4 && a < win->params.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = -2 * r * iz + ic; 
				a++;
			}
			if (a == win->params.it_max)
				mlx_put_pixel_to_image(&win->img, x, y, (0));
			else
				mlx_put_pixel_to_image(&win->img, x, y, (a * 100000));
			y++;
		}
		x++;
	}
}

void	ft_create_bship(t_win *win)
{
	double		rc;
	double		ic;
	double		rz;
	double		iz;
	double		r;
	int			a;
	int 		x;
	int 		y;

	x = 0;
	while (x < IMG_HOR_SIZE)
	{
		y = 0;
		while (y < IMG_VER_SIZE)
		{
			rc = x / win->params.zoom + win->params.x1 + win->params.moove_hor;
			ic = y / win->params.zoom + win->params.y1 + win->params.moove_ver;
			rz = 0;
			iz = 0;
			a = 0;
			while (rz * rz + iz * iz < 4 && a < win->params.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * fabs(r) * fabs(iz) + ic; 
				a++;
			}
			if (a == win->params.it_max)
				mlx_put_pixel_to_image(&win->img, x, y, (0));
			else
				mlx_put_pixel_to_image(&win->img, x, y, (a * 100000));
			y++;
		}
		x++;
	}
}

void	ft_create_mandelbrot2(t_win *win)
{
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

	x = 0;
	while (x < VIG_HOR_SIZE)
	{
		y = 0;
		while (y < VIG_VER_SIZE)
		{
			rc = x / zoom_x + x1;
			ic = y / zoom_y + y1;
			rz = 0;
			iz = 0;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < win->params.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * r * iz + ic; 
				a++;
			}
			if (a == win->params.it_max && win->params.it_max > 0)
				mlx_put_pixel_to_image_2(&win->img, x, y, (0));
			y++;
		}
		x++;
	}
}

void	ft_create_julia2(t_win *win)
{
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

	x = 0;
	while (x < VIG_HOR_SIZE)
	{
		y = 0;
		while (y < VIG_VER_SIZE)
		{
			rc = 0.285;
			ic = 0.01;
			rz = x / zoom_x + x1;
			iz = y / zoom_y + y1;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < win->params.it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * r * iz + ic; 
				a++;
			}
			if (a == win->params.it_max && win->params.it_max > 0)
				mlx_put_pixel_to_image_2(&win->img, x, (y + VIG_VER_SIZE), 0);
			y++;
		}
		x++;
	}
}