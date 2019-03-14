/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:39:39 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/14 00:59:22 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_create_it(t_win *win)
{
	ft_multithreading(win);
	if (win->motion == 1)
		ft_viseur(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->img.img_ptr, 0, 0);
	if (win->vig_it == 1)
		ft_put_vig(win, 0);
	ft_print_menu(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->vig.img_ptr, 800, 0);
}

static void	deal_key_reset(int keycode, t_win *win)
{
	if (keycode == TOUCH_PLUS)
		(win->fract == 10) ? (win->fract = 1) : (win->fract += 1);
	else if (keycode == TOUCH_LESS)
		(win->fract == 1) ? (win->fract = 10) : (win->fract -= 1);
	ft_reset_fractale(win);
}

int			deal_key(int keycode, t_win *win)
{
	if (keycode == ARROW_DOWN)
		win->p.moove_ver += SIZE_MOV / win->p.zoom;
	else if (keycode == ARROW_UP)
		win->p.moove_ver -= SIZE_MOV / win->p.zoom;
	else if (keycode == ARROW_RIGHT)
		win->p.moove_hor += SIZE_MOV / win->p.zoom;
	else if (keycode == ARROW_LEFT)
		win->p.moove_hor -= SIZE_MOV / win->p.zoom;
	else if (keycode == TOUCH_P)
		win->p.it_max += 1;
	else if (keycode == TOUCH_O && win->p.it_max >= 5)
		win->p.it_max -= 1;
	else if (keycode == PAGE_UP)
		win->p.zoom *= (double)COEF_ZOOM;
	else if (keycode == PAGE_DOWN)
		win->p.zoom /= (double)COEF_ZOOM;
	else if (keycode == TOUCH_ESC)
		ft_exit(win);
	else if (keycode == TOUCH_V)
		(win->vig_it == 0) ? (win->vig_it += 1) \
			: (win->vig_it = 0);
	else if (keycode == TOUCH_M && win->fract >= 5)
		(win->motion == 0) ? (win->motion += 1) \
			: (win->motion = 0);
	else if (keycode == TOUCH_C)
		(win->p.color > 999999999) ? (win->p.color = 99) \
			: (win->p.color *= 1.5);
	else if (keycode == TOUCH_PLUS || keycode == TOUCH_LESS \
		|| keycode == TOUCH_R)
		deal_key_reset(keycode, win);
	ft_create_it(win);
	return (1);
}
