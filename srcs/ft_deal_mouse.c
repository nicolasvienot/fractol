/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:40:43 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/11 20:23:52 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_pick_fractale(int x, int y, t_win *win)
{
	if (x > WIN_HOR_SIZE - VIG_HOR_SIZE && x < WIN_HOR_SIZE)
	{
		if (y > 0 && y < (WIN_VER_SIZE - 4 * WIN_VER_SIZE / 5))
			win->fract = 1;
		else if (y > (WIN_VER_SIZE - 4 * WIN_VER_SIZE / 5) \
			&& y < WIN_VER_SIZE - 3 * WIN_VER_SIZE / 5)
			win->fract = 2;
		else if (y > WIN_VER_SIZE - 3 * WIN_VER_SIZE / 5 \
			&& y < WIN_VER_SIZE - 2 * WIN_VER_SIZE / 5)
			win->fract = 3;
		else if (y > WIN_VER_SIZE - 2 * WIN_VER_SIZE / 5 \
			&& y < WIN_VER_SIZE - 1 * WIN_VER_SIZE / 5)
			win->fract = 4;
		else if (y > WIN_VER_SIZE - 1 * WIN_VER_SIZE / 5 \
			&& y < WIN_VER_SIZE)
			win->fract = 5;
		win->motion = 0;
	}
}

int			deal_motion(int x, int y, t_win *win)
{
	if (win->motion == 1 && win->fract >= 5)
	{
		if (x >= 0 && y >= 0 && x <= WIN_HOR_SIZE && y <= WIN_VER_SIZE)
		{
			win->params.rc = ((double)x - ((WIN_HOR_SIZE) / 2)) / 300;
			win->params.ic = ((double)y - (WIN_VER_SIZE / 2)) / 300;
		}
		ft_create_it(win);
	}
	return (1);
}

int			deal_mouse(int mouse, int x, int y, t_win *win)
{
	double	oldx;
	double	oldy;

	if (x > 0 && y > 0)
	{
		oldx = win->params.x1 + (double)x / win->params.zoom;
		oldy = win->params.y1 + (double)y / win->params.zoom;
		if (mouse == 4 && win->params.zoom > 10)
		{
			win->params.zoom /= (double)COEF_ZOOM;
			win->params.x1 = oldx - (double)x / win->params.zoom;
			win->params.y1 = oldy - (double)y / win->params.zoom;
		}
		if (mouse == 5)
		{
			win->params.zoom *= (double)COEF_ZOOM;
			win->params.x1 = oldx - (double)x / win->params.zoom;
			win->params.y1 = oldy - (double)y / win->params.zoom;
		}
		if (mouse == 1 && x > (WIN_HOR_SIZE - VIG_HOR_SIZE) && x < WIN_HOR_SIZE)
		{
			ft_pick_fractale(x, y, win);
			ft_reset_fractale(win);
		}
		if (mouse == 1 && x > 0 && x < (WIN_HOR_SIZE - VIG_HOR_SIZE) \
			&& win->fract >= 5)
		{
			if (win->motion == 0)
				win->motion = 1;
			else
				win->motion = 0;
		}
	}
	ft_create_it(win);
	return (1);
}
