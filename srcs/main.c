/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/06 20:02:07 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			deal_key(int keycode, t_win *win)
{
	if (keycode == ARROW_DOWN)
		win->moove_ver += SIZE_MOV;
	else if (keycode == ARROW_UP)
		win->moove_ver -= SIZE_MOV;
	else if (keycode == ARROW_RIGHT)
		win->moove_hor += SIZE_MOV;
	else if (keycode == ARROW_LEFT)
		win->moove_hor -= SIZE_MOV;
	else if (keycode == TOUCH_PLUS)
		win->it_max += 5;
	else if (keycode == TOUCH_LESS && win->it_max >= 5)
		win->it_max -= 5;
	else if (keycode == TOUCH_R)
		ft_reset_fractale(win);
	else if (keycode == TOUCH_ESC)
		ft_exit(win);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, IMG_HOR_SIZE, IMG_VER_SIZE);
	// ft_draw_fractale(win);
	ft_multithreading(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	ft_print_menu(win);
	ft_put_vig(win);
	return (1);
}

void		ft_pick_fractale(int x, int y, t_win *win)
{
	if (x > WIN_HOR_SIZE - VIG_HOR_SIZE && x < WIN_HOR_SIZE)
	{
		if (y > 0 && y < (WIN_VER_SIZE - 4 * WIN_VER_SIZE / 5))
			win->fract = 1;
		else if (y > (WIN_VER_SIZE - 4 * WIN_VER_SIZE / 5) && y < WIN_VER_SIZE - 3 * WIN_VER_SIZE / 5)
			win->fract = 2;
		else if (y > WIN_VER_SIZE - 3 * WIN_VER_SIZE / 5 && y < WIN_VER_SIZE - 2 * WIN_VER_SIZE / 5)
			win->fract = 3;
		else if (y > WIN_VER_SIZE - 2 * WIN_VER_SIZE / 5 && y < WIN_VER_SIZE - 1 * WIN_VER_SIZE / 5)
			win->fract = 4;
		else if (y > WIN_VER_SIZE - 1 * WIN_VER_SIZE / 5 && y < WIN_VER_SIZE)
			win->fract = 5;
	}
}

int			deal_mouse(int mouse, int x, int y, t_win *win)
{
	double	oldx;
	double	oldy;

	if (x > 0 && y > 0)
	{
		oldx = win->x1 + (double)x / win->zoom;
		oldy = win->y1 + (double)y / win->zoom;
		if (mouse == 4 && win->zoom > 10)
		{	
			win->zoom /= (double)COEF_ZOOM;
			win->x1 = oldx - (double)x / win->zoom;
			win->y1 = oldy - (double)y / win->zoom;
		}
		if (mouse == 5)
		{
			win->zoom *= (double)COEF_ZOOM;
			win->x1 = oldx - (double)x / win->zoom;
			win->y1 = oldy - (double)y / win->zoom;
		}
		if (mouse == 1 && x > WIN_VER_SIZE - VIG_HOR_SIZE && x < WIN_HOR_SIZE)
		{
			ft_pick_fractale(x, y, win);
			ft_reset_fractale(win);
		}
	}
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, IMG_HOR_SIZE, IMG_VER_SIZE);
	ft_multithreading(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	ft_print_menu(win);
	ft_put_vig(win);
	return (0);
}

int		deal_expose(t_win *win)
{
	// ft_draw_fractale(win);
	ft_multithreading(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	ft_print_menu(win);
	ft_put_vig(win);
	return (0);
}

void	ft_hook(t_win *win)
{
	mlx_expose_hook(win->win_ptr, deal_expose, win);
	mlx_hook(win->win_ptr, 2, 1L << 0, deal_key, win);
	mlx_mouse_hook(win->win_ptr, deal_mouse, win);
	mlx_hook(win->win_ptr, 17, 1L << 17, ft_exit, win);
	mlx_loop(win->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_win	*win;

	if (ac != 2)
		ft_usage();
	if (!ft_strcmp(av[1], "mandelbrot") || !ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "tricorne") || !ft_strcmp(av[1], "burningship"))
	{
		win = ft_select_fractale(av[1]);
		ft_hook(win);
	}
	else
		ft_usage();	
	return (0);
}