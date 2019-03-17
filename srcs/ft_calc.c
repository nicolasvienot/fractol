/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:07:55 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/17 20:01:18 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_modif_julia(t_render *r, int fract)
{
	if (fract == 8 || fract == 12)
	{
		if (fract == 8)
			r->rc = r->rc + 0.155;
		if (fract == 12)
			r->rc = r->rc + 0.253;
		r->ic = r->ic + 0.013;
	}
}

static void		ft_calc_3(t_render *r, int fract, int it_max, double y)
{
	double x;

	if (fract == 5 || fract == 11)
	{
		while (((x = r->rz * r->rz) - y) < 4 && r->a < it_max)
		{
			r->r = r->rz;
			r->rz = x - y + r->rc;
			r->iz = 2 * r->r * r->iz + r->ic;
			y = r->iz * r->iz;
			r->a++;
		}
	}
}

static void		ft_calc_2(t_render *r, int fract, int it_max, double y)
{
	double x;

	if (fract == 3 || fract == 9)
	{
		while ((x = r->rz * r->rz) + y < 4 && r->a < it_max)
		{
			r->r = r->rz;
			r->rz = x - y + r->rc;
			r->iz = -2 * r->r * r->iz + r->ic;
			y = r->iz * r->iz;
			r->a++;
		}
	}
	else if (fract == 4 || fract == 10)
	{
		while ((x = r->rz * r->rz) + y < 4 && r->a < it_max)
		{
			r->r = r->rz;
			r->rz = x - y + r->rc;
			r->iz = 2 * fabs(r->r) * fabs(r->iz) + r->ic;
			y = r->iz * r->iz;
			r->a++;
		}
	}
}

static void		ft_calc_1(t_render *r, int fract, int it_max, double y)
{
	double x;

	if (fract == 1 || fract == 7)
	{
		while ((x = r->rz * r->rz) + y < 4 && r->a < it_max)
		{
			r->r = r->rz;
			r->rz = x - y + r->rc;
			r->iz = 2 * r->r * r->iz + r->ic;
			y = r->iz * r->iz;
			r->a++;
		}
	}
	else if (fract == 2 || fract == 8)
	{
		while ((x = r->rz * r->rz) + y < 4 && r->a < it_max)
		{
			r->r = r->rz;
			r->rz = x * r->rz - 3 * r->rz * y + r->rc;
			r->iz = 3 * r->r * r->r * r->iz - y * r->iz + r->ic;
			y = r->iz * r->iz;
			r->a++;
		}
	}
}

void			ft_calc(t_render *r, int fract, int it_max, double p)
{
	double x;
	double y;
	double z;

	y = 0;
	r->a = 0;
	y = r->iz * r->iz;
	ft_modif_julia(r, fract);
	if (fract == 1 || fract == 2 || fract == 7 || fract == 8)
		ft_calc_1(r, fract, it_max, y);
	else if (fract == 3 || fract == 4 || fract == 9 || fract == 10)
		ft_calc_2(r, fract, it_max, y);
	else if (fract == 5 || fract == 11)
		ft_calc_3(r, fract, it_max, y);
	else if (fract == 6 || fract == 12)
	{
		while ((x = r->rz * r->rz) + y < 4 && r->a < it_max)
		{
			z = p * atan2(r->iz, r->rz);
			r->rz = (pow(x + y, p / 2)) * cos(z) + r->rc;
			r->iz = (pow(x + y, p / 2)) * sin(z) + r->ic;
			y = r->iz * r->iz;
			r->a++;
		}
	}
}
