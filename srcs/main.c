/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/15 16:10:57 by nvienot          ###   ########.fr       */
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
	if (!ft_strcmp(av[1], "mandelbrot") || !ft_strcmp(av[1], "duobrot") \
		|| !ft_strcmp(av[1], "tricorn") || !ft_strcmp(av[1], "burningship") \
		|| !ft_strcmp(av[1], "palmtree") || !ft_strcmp(av[1], "julia") \
		|| !ft_strcmp(av[1], "andy") || !ft_strcmp(av[1], "microcells") \
		|| !ft_strcmp(av[1], "brain") || !ft_strcmp(av[1], "flower"))
	{
		ft_init_start(&win);
		ft_select_fractale(&win, av[1]);
		ft_multithreading(&win);
		ft_hook(&win);
	}
	else
		ft_usage();
	return (0);
}
