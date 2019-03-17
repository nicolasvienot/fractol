/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:39:39 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/17 22:29:25 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		deal_key_reset(int key, t_win *win)
{
	if (key == TOUCH_PLUS)
		(win->fract == 12) ? (win->fract = 1) : (win->fract += 1);
	else if (key == TOUCH_LESS)
		(win->fract == 1) ? (win->fract = 12) : (win->fract -= 1);
	ft_reset_fractal(win);
}

static int		deal_key_2(int key, t_win *w, int a)
{
	if (key == TOUCH_SUP && (w->fract == 6 || w->fract == 12) && ++a > 0)
		w->p.power += 0.1;
	else if (key == TOUCH_INF && (w->fract == 6 \
		|| w->fract == 12) && w->p.power > 1 && ++a > 0)
		w->p.power -= 0.1;
	else if (key == TOUCH_CRF && (w->fract == 6 || w->fract == 12) && ++a > 0)
		w->p.power += 1;
	else if (key == TOUCH_CRO && (w->fract == 6 \
		|| w->fract == 12) && w->p.power > 1 && ++a > 0)
		w->p.power -= 1;
	else if (key == TOUCH_Z && ++a > 0)
		(w->menu == 0) ? (w->menu += 1) : (w->menu = 0);
	else if (key == TOUCH_X && ++a > 0)
		(w->immersive == 0) ? (w->immersive += 1) : (w->immersive = 0);
	else if (key == TOUCH_V && ++a > 0)
		(w->vig_it == 0) ? (w->vig_it += 1) : (w->vig_it = 0);
	else if (key == TOUCH_M && w->fract > 6 && ++a > 0)
		(w->motion == 0) ? (w->motion += 1) : (w->motion = 0);
	else if (key == PAGE_UP && ++a > 0)
		w->p.it_max += 1;
	else if (key == PAGE_DOWN && w->p.it_max > 2 && ++a > 0)
		w->p.it_max -= 1;
	else if (key == TOUCH_STAR && w->pal == 1 && ++a > 0)
		(w->psych > 999999999) ? (w->psych = 999) : (w->psych *= 1.5);
	return (a);
}

int				deal_key(int key, t_win *win)
{
	int a;

	a = 0;
	if (key == ARROW_UP && ++a > 0)
		win->p.moove_ver -= SIZE_MOV / win->p.zoom;
	else if (key == ARROW_DOWN && ++a > 0)
		win->p.moove_ver += SIZE_MOV / win->p.zoom;
	else if (key == ARROW_RIGHT && ++a > 0)
		win->p.moove_hor += SIZE_MOV / win->p.zoom;
	else if (key == ARROW_LEFT && ++a > 0)
		win->p.moove_hor -= SIZE_MOV / win->p.zoom;
	else if (key == TOUCH_P && ++a > 0)
		(win->pal == 7) ? (win->pal = 1) : (win->pal += 1);
	else if (key == TOUCH_C && ++a > 0)
		(win->color == 4) ? (win->color = 1) : (win->color += 1);
	else if ((key == TOUCH_PLUS || key == TOUCH_LESS \
		|| key == TOUCH_R) && ++a > 0)
		deal_key_reset(key, win);
	else if (key == TOUCH_ESC && ++a > 0)
		ft_exit(win);
	else
		a = deal_key_2(key, win, a);
	if (a > 0)
		ft_create_all(win);
	return (1);
}
