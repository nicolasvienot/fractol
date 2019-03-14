/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:39:39 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/14 02:01:23 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		deal_key_reset(int key, t_win *win)
{
	if (key == TOUCH_PLUS)
		(win->fract == 10) ? (win->fract = 1) : (win->fract += 1);
	else if (key == TOUCH_LESS)
		(win->fract == 1) ? (win->fract = 10) : (win->fract -= 1);
	ft_reset_fractale(win);
}

static void		deal_key_move(int key, t_win *win)
{
	if (key == ARROW_UP)
		win->p.moove_ver -= SIZE_MOV / win->p.zoom;
	else if (key == ARROW_DOWN)
		win->p.moove_ver += SIZE_MOV / win->p.zoom;
	else if (key == ARROW_RIGHT)
		win->p.moove_hor += SIZE_MOV / win->p.zoom;
	else if (key == ARROW_LEFT)
		win->p.moove_hor -= SIZE_MOV / win->p.zoom;
}

int				deal_key(int key, t_win *win)
{
	if (key == ARROW_DOWN || key == ARROW_UP \
		|| key == ARROW_RIGHT || key == ARROW_LEFT)
		deal_key_move(key, win);
	else if (key == TOUCH_P)
		win->p.it_max += 1;
	else if (key == TOUCH_O && win->p.it_max > 1)
		win->p.it_max -= 1;
	else if (key == TOUCH_V)
		(win->vig_it == 0) ? (win->vig_it += 1) \
			: (win->vig_it = 0);
	else if (key == TOUCH_M && win->fract > 5)
		(win->motion == 0) ? (win->motion += 1) \
			: (win->motion = 0);
	else if (key == TOUCH_C)
		(win->p.color > 999999999) ? (win->p.color = 99) \
			: (win->p.color *= 1.5);
	else if (key == TOUCH_PLUS || key == TOUCH_LESS \
		|| key == TOUCH_R)
		deal_key_reset(key, win);
	else if (key == TOUCH_ESC)
		ft_exit(win);
	ft_create_it(win);
	return (1);
}
