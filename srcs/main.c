/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/16 18:19:44 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			deal_expose(t_win *win)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
	ft_print_menu(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->vig.img_ptr, 790, 20);
	return (0);
}

static void	ft_hook(t_win *win)
{
	mlx_expose_hook(win->win_ptr, deal_expose, win);
	mlx_hook(win->win_ptr, 2, 1L << 0, deal_key, win);
	mlx_mouse_hook(win->win_ptr, deal_mouse, win);
	mlx_hook(win->win_ptr, 17, 1L << 17, ft_exit, win);
	mlx_hook(win->win_ptr, 6, 1L << 6, deal_motion, win);
	mlx_loop(win->mlx_ptr);
}

int			main(int ac, char **av)
{
	t_win	win;

	if (ac != 2)
		ft_usage();
	if (!ft_strcmp(av[1], F1) || !ft_strcmp(av[1], F2) \
		|| !ft_strcmp(av[1], F3) || !ft_strcmp(av[1], F4) \
		|| !ft_strcmp(av[1], F5) || !ft_strcmp(av[1], F6) \
		|| !ft_strcmp(av[1], F7) || !ft_strcmp(av[1], F8) \
		|| !ft_strcmp(av[1], F9) || !ft_strcmp(av[1], F10) \
		|| !ft_strcmp(av[1], F11) || !ft_strcmp(av[1], F12))
	{
		ft_init_start(&win);
		ft_select_fractal(&win, av[1]);
		ft_multithreading(&win);
		ft_hook(&win);
	}
	else
		ft_usage();
	return (0);
}
