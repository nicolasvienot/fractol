/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:57:06 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/17 20:01:19 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	basics(int i, int iter_max, int color)
{
	color = 999;
	if (i == iter_max)
		return (0);
	else
		return(color * i / iter_max);
}


unsigned int	psycho(int i, int iter_max, int color)
{
	if (i == iter_max)
		return (0);
	else
		return(color * i / iter_max);
}

unsigned int	aqua_blue(int i, int iter_max)
{
	double red;
	double green;
	double blue;

	if (i == iter_max)
		return (BLACK);
	red = sin(0.3 * (double)i);
	green = sin(0.3 * (double)i + 3) * 127 + 128;
	blue = sin(0.3 * (double)i + 3) * 127 + 128;
	return ((UI)red << 16 | (UI)green << 8 | (UI)blue);
}

unsigned int	shade_of_grey(int i, int iter_max)
{
	double red;
	double green;
	double blue;

	if (i == iter_max)
		return (WHITE);
	red = sin(0.3 * (double)i) * 127 + 128;
	green = sin(0.3 * (double)i) * 127 + 128;
	blue = sin(0.3 * (double)i) * 127 + 128;
	return ((UI)red << 16 | (UI)green << 8 | (UI)blue);
}

unsigned int	rainbow2(int i, int iter_max)
{
	double red;
	double green;
	double blue;

	if (i == iter_max)
		return (WHITE);
	red = sin(0.3 * (double)i + 0.0) * 127.0 + 128.0;
	green = sin(0.3 * (double)i + 2.0) * 127.0 + 128.0;
	blue = sin(0.3 * (double)i + 4.0) * 127.0 + 128.0;
	return ((UI)red << 16 | (UI)green << 8 | (UI)blue);
}

unsigned int	smooth_aqua_blue(int i, int iter_max, double mult)
{
	double nu;
	double red;
	double green;
	double blue;

	if (i == iter_max)
		return (BLACK);
	nu = (i + 2 - log2(log2(sqrt(mult)))) / iter_max;
	nu = nu - (int)nu;
	red = (int)(74 * nu);
	green = (int)(205 * nu);
	blue = (int)(196 * nu);
	return ((UI)red << 16 | (UI)green << 8 | (UI)blue);
}


unsigned int	smooth_shade_of_grey(int i, int iter_max, double mult)
{
	double nu;
	double red;
	double green;
	double blue;

	if (i == iter_max)
		return (WHITE);
	nu = (i + 5 - log2(log2(sqrt(mult)))) / iter_max;
	nu = nu - (int)nu;
	red = (int)(255 * nu + 255 * nu);
	green = (int)(255 * nu + 255 * nu);
	blue = (int)(255 * nu + 255 * nu);
	return ((UI)red << 16 | (UI)green << 8 | (UI)blue);
}

unsigned int	vasarely(double zi)
{
	if (zi > 0)
		return (BLACK);
	return (WHITE);
}

unsigned int	zebra(int i, int iter_max, double mult)
{
	double nu;
	double red;
	double green;
	double blue;

	if (i == iter_max)
		return (WHITE);
	else
	{
		nu = (i + 5 - log2(log2(sqrt(mult)))) / iter_max;
		nu = nu - (int)nu;
		red = (int)(0 / nu);
		green = (int)(255 / nu);
		blue = (int)(255 / nu);
		return ((UI)red << 16 | (UI)green << 8 | (UI)blue);
	}
}

unsigned int	grey(int i, int iter_max, double mult)
{
	double nu;
	double red;
	double green;
	double blue;

	if (i == iter_max)
		return (BLACK);
	nu = (i + 3 - log2(log2(sqrt(mult)))) / iter_max;
	nu = nu - (int)nu;
	red = (int)(185 * nu + 70 * nu);
	green = (int)(55 * nu + 200 * nu);
	blue = (int)(25 * nu + 230 * nu);
	return ((UI)red << 16 | (UI)green << 8 | (UI)blue);
}

unsigned int	fire(int i, int iter_max, double mult)
{
	double nu;
	double red;
	double green;
	double blue;

	if (i == iter_max)
		return (BLACK);
	nu = (i + 3 - log2(log2(sqrt(mult)))) / iter_max;
	nu = nu - (int)nu;
	red = (int)(185 * nu + 70 * nu);
	green = (int)(55 * nu);
	blue = (int)(25 * nu);
	return ((UI)red << 16 | (UI)green << 8 | (UI)blue);
}

unsigned int	blue(int i, int iter_max, double mult)
{
	double nu;
	double red;
	double green;
	double blue;

	if (i == iter_max)
		return (BLACK);
	nu = (i + 3 - log2(log2(sqrt(mult)))) / iter_max;
	nu = nu - (int)nu;
	red = (int)(255 * nu - 221 * nu);
	green = (int)(255 * nu - 88 * nu);
	blue = (int)(255 * nu - 15 * nu);
	return ((UI)red << 16 | (UI)green << 8 | (UI)blue);
}

int				ft_choose_color(t_render r, int pal, int it_max, int color)
{
	double mult;

	mult = r.rz * r.rz + r.iz * r.iz;
	if (pal == 1)
		return(basics(r.a, it_max, color));
	else if (pal == 2)
		return(psycho(r.a, it_max, color));
	else if (pal == 3)
		return(aqua_blue(r.a, it_max));
	else if (pal == 4)
		return(shade_of_grey(r.a, it_max));
	else if (pal == 5)
		return(rainbow2(r.a, it_max));
	else if (pal == 6)
		return(zebra(r.a, it_max, mult));
	else if (pal == 7)
		return(smooth_shade_of_grey(r.a, it_max, mult));
	else if (pal == 8)
		return(smooth_aqua_blue(r.a, it_max, mult));
	else if (pal == 9)
		return(blue(r.a, it_max, mult));
	else if (pal == 10)
		return(grey(r.a, it_max, mult));
	else if (pal == 11)
		return(fire(r.a, it_max, mult));
	else if (pal == 12)
		return(vasarely(r.iz));
	else
		return (0);
}