/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:07:55 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/15 18:54:57 by nvienot          ###   ########.fr       */
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
	if (fract == 1 || fract == 7)
	{
		while ((r->rz * r->rz + r->iz * r->iz) < 4 && r->a < it_max)
		{
			r->r = r->rz;
			r->rz = r->rz * r->rz - r->iz * r->iz + r->rc;
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

void			ft_calc(t_render *r, int fract, int it_max, int p)
{
	r->a = 0;
	if (fract == 1 || fract == 2 || fract == 7 || fract == 8)
		ft_calc_1(r, fract, it_max);
	else if (fract == 3 || fract == 4 || fract == 9 || fract == 10)
		ft_calc_2(r, fract, it_max);
	else if (fract == 5 || fract == 11)
	{
		while ((r->rz * r->rz - r->iz * r->iz) < 4 && r->a < it_max)
		{
			r->r = r->rz;
			r->rz = r->rz * r->rz - r->iz * r->iz + r->rc;
			r->iz = 2 * r->r * r->iz + r->ic;
			r->a++;
		}
	}
	else if (fract == 6 || fract == 12)
	{
		while ((r->rz * r->rz + r->iz * r->iz) < 4 && r->a < it_max)
		{
			r->xtmp = pow(r->rz * r->rz + r->iz * r->iz, p / 2) * cos(p * atan2(r->iz, r->rz)) + r->rc;
			r->ytmp = pow(r->rz * r->rz + r->iz * r->iz, p / 2) * sin(p * atan2(r->iz, r->rz)) + r->ic;
			r->rz = r->xtmp;
			r->iz = r->ytmp;
			r->a++;
		}
	}
}
