/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:07:55 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/15 23:09:27 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_calc_2(t_render *r, int fract, int it_max)
{
	if (fract == 3 || fract == 9)
	{
		while ((r->rz * r->rz + r->iz * r->iz) < 4 && r->a < it_max)
		{
			r->r = r->rz;
			r->rz = r->rz * r->rz - r->iz * r->iz + r->rc;
			r->iz = -2 * r->r * r->iz + r->ic;
			r->a++;
		}
	}
	else if (fract == 4 || fract == 10)
	{
		while ((r->rz * r->rz + r->iz * r->iz) < 4 && r->a < it_max)
		{
			r->r = r->rz;
			r->rz = r->rz * r->rz - r->iz * r->iz + r->rc;
			r->iz = 2 * fabs(r->r) * fabs(r->iz) + r->ic;
			r->a++;
		}
	}
}

static void		ft_calc_1(t_render *r, int fract, int it_max)
{
	double x;
	double y;

	if (fract == 1 || fract == 7)
	{
		while (((x = r->rz * r->rz) + (y = r->iz * r->iz)) < 4 && r->a < it_max)
		{
			r->r = r->rz;
			r->rz = x - y + r->rc;
			r->iz = 2 * r->r * r->iz + r->ic;
			r->a++;
		}
	}
	else if (fract == 2 || fract == 8)
	{
		while ((r->rz * r->rz + r->iz * r->iz) < 4 && r->a < it_max)
		{
			r->r = r->rz;
			r->rz = r->rz * r->rz * r->rz - 3 * r->rz * r->iz * r->iz + r->rc;
			r->iz = 3 * r->r * r->r * r->iz - r->iz * r->iz * r->iz + r->ic;
			r->a++;
		}
	}
}

void			ft_calc(t_render *r, int fract, int it_max, double p)
{
	double x;
	double y;
	double z;

	x = 0;
	y = 0;
	r->a = 0;
	if (fract == 1 || fract == 2 || fract == 7 || fract == 8)
		ft_calc_1(r, fract, it_max);
	else if (fract == 3 || fract == 4 || fract == 9 || fract == 10)
		ft_calc_2(r, fract, it_max);
	else if (fract == 5 || fract == 11)
	{
		while (((x = r->rz * r->rz) + (y = r->iz * r->iz)) < 4 && r->a < it_max)
		{
			r->r = r->rz;
			r->rz = x - y + r->rc;
			r->iz = 2 * r->r * r->iz + r->ic;
			r->a++;
		}
	}
	else if (fract == 6 || fract == 12)
	{
		x = r->rz * r->rz;
		y = r->iz * r->iz;
		while (x + y < 4 && r->a < it_max)
		{
			z = p * atan2(r->iz, r->rz);
			r->rz = (pow(x + y, p / 2)) * cos(z) + r->rc;
			r->iz = (pow(x + y, p / 2)) * sin(z) + r->ic;
			x = r->rz * r->rz;
			y = r->iz * r->iz;
			r->a++;
		}
	}
}
