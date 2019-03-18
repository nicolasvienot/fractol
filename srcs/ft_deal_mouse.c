/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:40:43 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/18 19:54:34 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_immersive(t_win *win, int test)
{
	if (test == 1)
	{
		if (win->immersive == 1 && win->p.it_max > 2)
			win->p.it_max -= 1;
	}
	else if (test == 2)
	{
		if (win->immersive == 1)
			win->p.it_max += 1;
	}
}

static void		ft_pick_fractal(int x, int y, t_win *win)
{
	if (x > WIN_HOR_SIZE - VIG_HOR_SIZE - MRG && x < WIN_HOR_SIZE - MRG)
	{
		if (y > MRG && y < (MRG + VIG_VER_SIZE))
			win->fract = 1;
		else if (y > (MRG + VIG_VER_SIZE) && y < (MRG + VIG_VER_SIZE * 2))
			win->fract = 2;
		else if (y > (MRG + VIG_VER_SIZE * 2) && y < (MRG + VIG_VER_SIZE * 3))
			win->fract = 3;
		else if (y > (MRG + VIG_VER_SIZE * 3) && y < (MRG + VIG_VER_SIZE * 4))
			win->fract = 7;
		else if (y > (MRG + VIG_VER_SIZE * 4) && y < (MRG + VIG_VER_SIZE * 5))
			win->fract = 8;
		win->motion = 0;
	}
}

int				deal_motion(int x, int y, t_win *win)
{
	if (win->motion == 1 && win->fract > 6)
	{
		if (x >= 0 && y >= 0 && x <= WIN_HOR_SIZE && y <= WIN_VER_SIZE)
		{
			win->p.rc = ((double)x - ((WIN_HOR_SIZE) / 2)) / 300;
			win->p.ic = ((double)y - (WIN_VER_SIZE / 2)) / 300;
		}
		ft_create_all(win);
	}
	return (1);
}

static void		deal_mouse_click(t_win *win, int x, int y)
{
	if (x > WIN_HOR_SIZE - VIG_HOR_SIZE - MRG && x < WIN_HOR_SIZE \
		- MRG && y > MRG && y < (MRG + VIG_VER_SIZE * 5))
	{
		ft_pick_fractal(x, y, win);
		ft_reset_fractal(win);
	}
	else if (win->fract > 6)
	{
		if (win->motion == 0)
			win->motion = 1;
		else
			win->motion = 0;
	}
}

int				deal_mouse(int mouse, int x, int y, t_win *win)
{
	double	oldx;
	double	oldy;

	if (x > 0 && y > 0 && (mouse == 4 || mouse == 5 || mouse == 1))
	{
		oldx = win->p.x1 + (double)x / win->p.zoom;
		oldy = win->p.y1 + (double)y / win->p.zoom;
		if (mouse == 4 && win->p.zoom > 10)
		{
			win->p.zoom /= (double)COEF_ZOOM;
			win->p.x1 = oldx - (double)x / win->p.zoom;
			win->p.y1 = oldy - (double)y / win->p.zoom;
			ft_immersive(win, 1);
		}
		else if (mouse == 5)
		{
			win->p.zoom *= (double)COEF_ZOOM;
			win->p.x1 = oldx - (double)x / win->p.zoom;
			win->p.y1 = oldy - (double)y / win->p.zoom;
			ft_immersive(win, 2);
		}
		(mouse == 1) ? deal_mouse_click(win, x, y) : 0;
		ft_create_all(win);
	}
	return (1);
}
