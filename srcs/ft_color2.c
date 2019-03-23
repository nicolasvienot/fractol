/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:57:06 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/23 13:19:29 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	ft_spiral(int i, int iter_max, double mult, int c)
{
	double a;
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
		a = (i + 3 - log2(log2(sqrt(mult)))) / iter_max;
		a = a - (int)a;
		if (a > 0)
		{
			red = (int)(20 / a);
			green = (int)(125 / a);
			blue = (int)(125 / a);
			return ((unsigned int)red << 16 | (unsigned int)green << 8 \
				| (unsigned int)blue);
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
