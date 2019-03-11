/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:39:39 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/11 19:59:59 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_create_it(t_win *win)
{
//	mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
//	win->img.img_ptr = mlx_new_image(win->mlx_ptr, \
//		IMG_HOR_SIZE, IMG_VER_SIZE);
	ft_multithreading(win);
	if (win->motion == 1)
		ft_viseur(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->img.img_ptr, 0, 0);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->vig.img_ptr, 800, 0);
	ft_print_menu(win);
//	ft_put_vig(win);
}

static void	deal_key_reset(int keycode, t_win *win)
{
	if (keycode == TOUCH_PLUS)
		(win->fract == 8) ? (win->fract = 1) : (win->fract += 1);
	else if (keycode == TOUCH_LESS)
		(win->fract == 1) ? (win->fract = 8) : (win->fract -= 1);
	ft_reset_fractale(win);
}

int			deal_key(int keycode, t_win *win)
{
	if (keycode == ARROW_DOWN)
		win->params.moove_ver += SIZE_MOV;
	else if (keycode == ARROW_UP)
		win->params.moove_ver -= SIZE_MOV;
	else if (keycode == ARROW_RIGHT)
		win->params.moove_hor += SIZE_MOV;
	else if (keycode == ARROW_LEFT)
		win->params.moove_hor -= SIZE_MOV;
	else if (keycode == TOUCH_P)
		win->params.it_max += 1;
	else if (keycode == TOUCH_O && win->params.it_max >= 5)
		win->params.it_max -= 1;
	else if (keycode == TOUCH_ESC)
		ft_exit(win);
	else if (keycode == TOUCH_M && win->fract >= 5)
		(win->motion == 0) ? (win->motion += 1) \
			: (win->motion = 0);
	else if (keycode == TOUCH_C)
		(win->params.color > 999999999) ? (win->params.color = 99) \
			: (win->params.color *= 1.5);
	else if (keycode == TOUCH_PLUS || keycode == TOUCH_LESS \
		|| keycode == TOUCH_R)
		deal_key_reset(keycode, win);
	ft_create_it(win);
	return (1);
}
