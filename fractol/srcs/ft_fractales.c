/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractales.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:57:16 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/05 01:35:07 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_create_mandelbrot(t_win **win)
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
			rc = (x / (*win)->zoom + (*win)->x1) + (*win)->moove_hor;
			ic = (y / (*win)->zoom + (*win)->y1) + (*win)->moove_ver;
			rz = 0;
			iz = 0;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < (*win)->it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * r * iz + ic; 
				a++;
			}
			if (a == (*win)->it_max)
				mlx_put_pixel_to_image(win, x, y, (0));
			else
				mlx_put_pixel_to_image(win, x, y, (a * 100000));
			y++;
		}
		x++;
	}
}

void	ft_create_julia(t_win **win)
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
			rc = 0.285;
			ic = 0.01;
			rz = x / (*win)->zoom + (*win)->x1 + (*win)->moove_hor;
			iz = y / (*win)->zoom + (*win)->y1 + (*win)->moove_ver;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < (*win)->it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * r * iz + ic; 
				a++;
			}
			if (a == (*win)->it_max)
				mlx_put_pixel_to_image(win, x, y, (0));
			else
				mlx_put_pixel_to_image(win, x, y, (a * 100000));
			y++;
		}
		x++;
	}
}

void	ft_create_testlol(t_win **win)
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
			rc = (x / (*win)->zoom + -0.75) + (*win)->moove_hor;
			ic = (y / (*win)->zoom + 0.24314) + (*win)->moove_ver;
			rz = 0;
			iz = 0;
			a = 0;
			while ((rz * rz + iz * iz) < 4 && a < (*win)->it_max)
			{
				r = rz;
				rz = rz * rz - iz * iz + rc;
				iz = 2 * r * iz + ic; 
				a++;
			}
			if (a == (*win)->it_max)
				mlx_put_pixel_to_image(win, x, y, (0));
			else
				mlx_put_pixel_to_image(win, x, y, (a * 100000));
			y++;
		}
		x++;
	}
}