/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/14 00:19:34 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		deal_expose(t_win *win)
{
	ft_multithreading(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
	ft_print_menu(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->vig.img_ptr, 800, 0);
	return (0);
}

void	ft_hook(t_win *win)
{
	mlx_expose_hook(win->win_ptr, deal_expose, win);
	mlx_hook(win->win_ptr, 2, 1L << 0, deal_key, win);
	mlx_mouse_hook(win->win_ptr, deal_mouse, win);
	mlx_hook(win->win_ptr, 17, 1L << 17, ft_exit, win);
	mlx_hook(win->win_ptr, 6, 1L << 6, deal_motion, win);
	mlx_loop(win->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_win	win;

	if (ac != 2)
		ft_usage();
	if (!ft_strcmp(av[1], "mandelbrot") || !ft_strcmp(av[1], "julia") \
		|| !ft_strcmp(av[1], "tricorne") || !ft_strcmp(av[1], "burningship") \
		|| !ft_strcmp(av[1], "flower") || !ft_strcmp(av[1], "flower2") \
		|| !ft_strcmp(av[1], "flower3") || !ft_strcmp(av[1], "duobrot") \
		|| !ft_strcmp(av[1], "juliacarre"))
	{
		ft_init_start(&win);
		ft_select_fractale(&win, av[1]);
		ft_put_vig(&win, 1);
		ft_hook(&win);
	}
	else
		ft_usage();
	return (0);
}
