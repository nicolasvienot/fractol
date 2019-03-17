/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:57:06 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/17 22:44:00 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned int	ft_smooth(int i, int iter_max, double mult, int c)
{
	double nu;
	double red;
	double green;
	double blue;

	nu = (i + 1 - log2(log2(sqrt(mult)))) / iter_max;
	nu = nu - (int)nu;
	if (c == 1)
	{
		red = (int)(185 * nu + 70 * nu);
		green = (int)(55 * nu + 200 * nu);
		blue = (int)(25 * nu + 230 * nu);
	}
	else if (c == 2)
	{
		red = (int)(185 * nu + 70 * nu);
		green = (int)(55 * nu);
		blue = (int)(25 * nu);
	}
	else if (c == 3)
	{
		red = (int)(255 * nu - 221 * nu);
		green = (int)(255 * nu - 88 * nu);
		blue = (int)(255 * nu - 15 * nu);
	}
	else if (c == 4)
	{
		red = (int)(74 * nu);
		green = (int)(205 * nu);
		blue = (int)(196 * nu);
	}
	else
		return (0);
	return ((UI)red << 16 | (UI)green << 8 | (UI)blue);
}

static unsigned int	ft_normal(int i, int c)
{
	double red;
	double green;
	double blue;

	if (c == 1)
	{
		red = sin(0.3 * (double)i);
		green = sin(0.3 * (double)i + 3) * 127.0 + 128.0;
		blue = sin(0.3 * (double)i + 3) * 127.0 + 128.0;
	}
	else if (c == 2)
	{
		red = sin(0.3 * (double)i) * 127.0 + 128.0;
		green = sin(0.3 * (double)i) * 127.0 + 128.0;
		blue = sin(0.3 * (double)i) * 127.0 + 128.0;
	}
	else if (c == 3)
	{
		red = sin(0.3 * (double)i + 0.0) * 127.0 + 128.0;
		green = sin(0.3 * (double)i + 2.0) * 127.0 + 128.0;
		blue = sin(0.3 * (double)i + 4.0) * 127.0 + 128.0;
	}
	else if (c == 4)
	{
		red = sin(0.3 * (double)i + 1.0) * 127.0 + 128.0;
		green = sin(0.3 * (double)i + 2.0) * 127.0 + 128.0;
		blue = sin(0.3 * (double)i + 3.0) * 127.0 + 128.0;
	}
	else
		return (0);
	return ((UI)red << 16 | (UI)green << 8 | (UI)blue);
}

static unsigned int	ft_zebra(int i, int iter_max, double mult, int c)
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
		nu = (i + 1 - log2(log2(sqrt(mult)))) / iter_max;
		nu = nu - (int)nu;
		red = (int)(50 / nu);
		green = (int)(125 / nu);
		blue = (int)(125 / nu);
		return ((UI)red << 16 | (UI)green << 8 | (UI)blue);
	}
}

static unsigned int	ft_blackandwhite(double zi, int c)
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

int					ft_choose_color(t_render r, t_win *w)
{
	double mult;

	if (w->pal == 2 || w->pal == 3 || w->pal == 6)
		mult = r.rz * r.rz + r.iz * r.iz;
	if ((w->pal == 2 || w->pal == 4) && r.a == w->p.it_max)
		return (BLACK);
	else if ((w->pal == 3 || w->pal == 5) && r.a == w->p.it_max)
		return (WHITE);
	else if (w->pal == 1)
	{
		if (r.a == w->p.it_max)
			return (0);
		else
			return (w->psych * r.a / w->p.it_max);
	}
	else if (w->pal == 2 || w->pal == 3)
		return (ft_smooth(r.a, w->p.it_max, mult, w->color));
	else if (w->pal == 4 || w->pal == 5)
		return (ft_normal(r.a, w->color));
	else if (w->pal == 6)
		return (ft_zebra(r.a, w->p.it_max, mult, w->color));
	else if (w->pal == 7)
		return (ft_blackandwhite(r.iz, w->color));
	else
		return (0);
}
