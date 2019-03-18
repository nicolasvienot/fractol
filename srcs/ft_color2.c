/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:57:06 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/18 19:02:59 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	ft_spiral(int i, int iter_max, double mult, int c)
{
	double nu;
	double red;
	double green;
	double blue;

	if (i == iter_max)
		if (c % 2 == 1)
			return (WHITE);
		else
			return (BLACK);
	else
	{
		nu = (i + 3 - log2(log2(sqrt(mult)))) / iter_max;
		nu = nu - (int)nu;
		if (nu > 0)
		{
			red = (int)(20 / nu);
			green = (int)(125 / nu);
			blue = (int)(125 / nu);
			return ((UI)red << 16 | (UI)green << 8 | (UI)blue);
		}
		else
			return (0);
	}
}

unsigned int	ft_blackandwhite(double zi, int c)
{
	if (c % 2 == 1)
	{
		if (zi > 0)
			return (BLACK);
		return (WHITE);
	}
	if (c % 2 == 0)
	{
		if (zi > 0)
			return (WHITE);
		return (BLACK);
	}
	return (0);
}
