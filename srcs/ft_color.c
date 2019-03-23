/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:57:06 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/23 13:19:13 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned int	ft_smooth_2(int i, int iter_max, double mult, int c)
{
	double a;
	double red;
	double green;
	double blue;

	a = (i + 1 - log2(log2(sqrt(mult)))) / iter_max;
	a = a - (int)a;
	if (c == 3)
	{
		red = (int)(255 * a - 221 * a);
		green = (int)(255 * a - 88 * a);
		blue = (int)(255 * a - 15 * a);
	}
	else if (c == 4)
	{
		red = (int)(74 * a);
		green = (int)(205 * a);
		blue = (int)(196 * a);
	}
	else
		return (0);
	if ((red * 256 * 256 + green * 256 + blue) < 0)
		return (0);
	return ((unsigned int)red << 16 | (unsigned int)green << 8 \
		| (unsigned int)blue);
}

static unsigned int	ft_smooth_1(int i, int iter_max, double mult, int c)
{
	double a;
	double red;
	double green;
	double blue;

	a = (i + 1 - log2(log2(sqrt(mult)))) / iter_max;
	a = a - (int)a;
	if (c == 1)
	{
		red = (int)(185 * a + 70 * a);
		green = (int)(55 * a + 200 * a);
		blue = (int)(25 * a + 230 * a);
	}
	else if (c == 2)
	{
		red = (int)(185 * a + 70 * a);
		green = (int)(55 * a);
		blue = (int)(25 * a);
	}
	else
		return (ft_smooth_2(i, iter_max, mult, c));
	if ((red * 256 * 256 + green * 256 + blue) < 0)
		return (0);
	return ((unsigned int)red << 16 | (unsigned int)green << 8 \
		| (unsigned int)blue);
}

static unsigned int	ft_normal_2(int i, int c)
{
	double red;
	double green;
	double blue;

	if (c == 3)
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
	return ((unsigned int)red << 16 | (unsigned int)green << 8 \
		| (unsigned int)blue);
}

static unsigned int	ft_normal_1(int i, int c)
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
	else
		return (ft_normal_2(i, c));
	return ((unsigned int)red << 16 | (unsigned int)green << 8 \
		| (unsigned int)blue);
}

int					ft_choose_color(t_render r, t_win *w)
{
	double mult;

	if (w->pal == 2 || w->pal == 3 || w->pal == 6)
		mult = r.rz * r.rz + r.iz * r.iz;
	if ((w->pal == 1 || w->pal == 2 || w->pal == 4) && r.a == w->p.it_max)
		return (BLACK);
	if (w->pal == 8 && r.a == w->p.it_max && w->color % 2 == 0)
		return (BLACK);
	else if ((w->pal == 3 || w->pal == 5) && r.a == w->p.it_max)
		return (WHITE);
	else if (w->pal == 1)
		return (999 * r.a / w->p.it_max);
	else if (w->pal == 2 || w->pal == 3)
		return (ft_smooth_1(r.a, w->p.it_max, mult, w->color));
	else if (w->pal == 4 || w->pal == 5)
		return (ft_normal_1(r.a, w->color));
	else if (w->pal == 6)
		return (ft_spiral(r.a, w->p.it_max, mult, w->color));
	else if (w->pal == 7)
		return (ft_blackandwhite(r.iz, w->color));
	else if (w->pal == 8)
		if (r.a != 0 && (w->psych * w->p.it_max / r.a > 0) \
			&& (w->psych * w->p.it_max / r.a < WHITE))
			return (w->psych * w->p.it_max / r.a);
	return (0);
}
