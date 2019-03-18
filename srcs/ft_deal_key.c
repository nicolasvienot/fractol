/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:39:39 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/18 19:51:35 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		deal_key_reset(int key, t_win *win)
{
	if (key == TOUCH_PLUS)
	{
		if (win->fract == 12)
			win->fract = 1;
		else
			win->fract += 1;
	}
	else if (key == TOUCH_LESS)
	{
		if (win->fract == 1)
			win->fract = 12;
		else
			win->fract -= 1;
	}
	ft_reset_fractal(win);
}

static int		deal_key_4(int key, t_win *w, int a)
{
	if (key == TOUCH_P && ++a > 0)
	{
		if (w->pal == 8)
			w->pal = 1;
		else
			w->pal += 1;
	}
	else if (key == TOUCH_X && ++a > 0)
	{
		if (w->immersive == 0)
			w->immersive = 1;
		else
			w->immersive = 0;
	}
	else if (key == TOUCH_STAR && w->pal == 8 && ++a > 0)
	{
		if (w->psych < (WHITE - w->psych))
			w->psych += 9999;
		else
			w->psych = 999;
	}
	else if (key == TOUCH_ESC && ++a > 0)
		ft_exit(w);
	return (a);
}

static int		deal_key_3(int key, t_win *w, int a)
{
	if (key == TOUCH_Z && ++a > 0)
	{
		if (w->menu == 0)
			w->menu = 1;
		else
			w->menu = 0;
	}
	else if (key == TOUCH_V && ++a > 0)
	{
		if (w->vig_it == 0)
			w->vig_it = 1;
		else
			w->vig_it = 0;
	}
	else if (key == TOUCH_M && w->fract > 6 && ++a > 0)
	{
		if (w->motion == 0)
			w->motion = 1;
		else
			w->motion = 0;
	}
	return (a);
}

static int		deal_key_2(int key, t_win *w, int a)
{
	if (key == SUP && (w->fract == 6 || w->fract == 12) && ++a > 0)
		w->p.power += 0.1;
	else if (key == INF && (w->fract == 6 \
		|| w->fract == 12) && w->p.power > 1 && ++a > 0)
		w->p.power -= 0.1;
	else if (key == CRF && (w->fract == 6 || w->fract == 12) && ++a > 0)
		w->p.power += 1;
	else if (key == CRO && (w->fract == 6 \
		|| w->fract == 12) && w->p.power > 1 && ++a > 0)
		w->p.power -= 1;
	else if (key == PAGE_UP && ++a > 0)
		w->p.it_max += 1;
	else if (key == PAGE_DOWN && w->p.it_max > 2 && ++a > 0)
		w->p.it_max -= 1;
	else if (key == TOUCH_C && ++a > 0)
	{
		if (w->color == 4)
			w->color = 1;
		else
			w->color += 1;
	}
	return (a);
}

int				deal_key(int k, t_win *win)
{
	int a;

	a = 0;
	if (k == ARROW_UP && ++a > 0)
		win->p.moove_ver -= SIZE_MOV / win->p.zoom;
	else if (k == ARROW_DOWN && ++a > 0)
		win->p.moove_ver += SIZE_MOV / win->p.zoom;
	else if (k == ARROW_RIGHT && ++a > 0)
		win->p.moove_hor += SIZE_MOV / win->p.zoom;
	else if (k == ARROW_LEFT && ++a > 0)
		win->p.moove_hor -= SIZE_MOV / win->p.zoom;
	else if ((k == TOUCH_PLUS || k == TOUCH_LESS \
		|| k == TOUCH_R) && ++a > 0)
		deal_key_reset(k, win);
	else if (k == SUP || k == INF || k == CRF || k == CRO \
	|| k == PAGE_UP || k == PAGE_DOWN || k == TOUCH_C)
		a = deal_key_2(k, win, a);
	else if (k == TOUCH_Z || k == TOUCH_V || k == TOUCH_M)
		a = deal_key_3(k, win, a);
	else if (k == TOUCH_P || k == TOUCH_X || k == TOUCH_STAR || k == TOUCH_ESC)
		a = deal_key_4(k, win, a);
	if (a > 0)
		ft_create_all(win);
	return (1);
}
