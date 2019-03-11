/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/11 17:49:09 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			deal_motion(int x, int y, t_win *win)
{
	(void)y;
	if (win->motion == 1 && win->fract >= 5)
	{
		if (x >= 0 && y >= 0 && x <= WIN_HOR_SIZE && y <= WIN_VER_SIZE)
		{
		//	win->params.rc = ((double)x - ((WIN_HOR_SIZE - VIG_HOR_SIZE) / 2))  / 500;
		//	win->params.ic = ((double)y - (WIN_VER_SIZE / 2)) / 500;
			win->params.rc = ((double)x - ((WIN_HOR_SIZE) / 2))  / 300;
			win->params.ic = ((double)y - (WIN_VER_SIZE / 2)) / 300;
		}
		// if (x > 0 && x < WIN_HOR_SIZE && y > 0 && y < WIN_VER_SIZE)
		// {
		// 	if (x < WIN_HOR_SIZE / 2 && y < WIN_VER_SIZE / 2)
		// 		win->params.rc += 0.05;
		// 	if (x > WIN_HOR_SIZE / 2 && y < WIN_VER_SIZE / 2)
		// 		win->params.rc -= 0.05;
		// 	if (x < WIN_HOR_SIZE / 2 && y > WIN_VER_SIZE / 2)
		// 		win->params.ic += 0.05;
		// 	if (x > WIN_HOR_SIZE / 2 && y > WIN_VER_SIZE / 2)
		// 		win->params.ic -= 0.05;
		// }
		// if (y > (WIN_VER_SIZE / 2) && y < WIN_VER_SIZE)
		// {
		// 	ft_putnbr(x);
		// 	ft_putstr(" ");
		// 	win->params.rc += 0.005;
		// 	win->params.ic += 0.005;
		// }
		// else if (y < (WIN_VER_SIZE / 2) && y > 0)
		// {
		// 	ft_putnbr(x);
		// 	ft_putstr(" ");
		// 	win->params.rc -= 0.005;
		// 	win->params.ic -= 0.005;
		// }
		ft_multithreading(win);
		ft_viseur(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->vig.img_ptr, 800, 0);
		ft_print_menu(win);
	}	
	return (0);
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
	else if (keycode == TOUCH_PLUS)
	{
		if (win->fract == 8)
			win->fract = 1;
		else
			win->fract += 1;
		ft_reset_fractale(win);
	}
	else if (keycode == TOUCH_LESS)
	{
		if (win->fract == 1)
			win->fract = 8;
		else
			win->fract -= 1;
		ft_reset_fractale(win);
	}
	else if (keycode == TOUCH_P)
		win->params.it_max += 1;
	else if (keycode == TOUCH_O && win->params.it_max >= 5)
		win->params.it_max -= 1;
	else if (keycode == TOUCH_R)
		ft_reset_fractale(win);
	else if (keycode == TOUCH_ESC)
		ft_exit(win);
	else if (keycode == TOUCH_M && win->fract >= 5)
	{
		if (win->motion == 0)
			win->motion = 1;
		else
			win->motion = 0;
	}
	else if (keycode == TOUCH_C)
	{
		if (win->params.color > 999999999)
			win->params.color = 999;
		else
			win->params.color *= 1.5;
	}
	// mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
	// win->img.img_ptr = mlx_new_image(win->mlx_ptr, IMG_HOR_SIZE, IMG_VER_SIZE);
	ft_multithreading(win);
	if (win->motion == 1)
		ft_viseur(win);
	// ft_viseur(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->vig.img_ptr, 800, 0);
	ft_print_menu(win);
	// ft_put_vig(win);
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
		win->motion = 0;
	}
}

int			deal_mouse(int mouse, int x, int y, t_win *win)
{
	double	oldx;
	double	oldy;

	if (x > 0 && y > 0)
	{
		oldx = win->params.x1 + (double)x / win->params.zoom;
		oldy = win->params.y1 + (double)y / win->params.zoom;
		if (mouse == 4 && win->params.zoom > 10)
		{	
			win->params.zoom /= (double)COEF_ZOOM;
			win->params.x1 = oldx - (double)x / win->params.zoom;
			win->params.y1 = oldy - (double)y / win->params.zoom;
		}
		if (mouse == 5)
		{
			win->params.zoom *= (double)COEF_ZOOM;
			win->params.x1 = oldx - (double)x / win->params.zoom;
			win->params.y1 = oldy - (double)y / win->params.zoom;
		}
		if (mouse == 1 && x > (WIN_HOR_SIZE - VIG_HOR_SIZE) && x < WIN_HOR_SIZE)
		{
			ft_pick_fractale(x, y, win);
			ft_reset_fractale(win);
		}
		if (mouse == 1 && x > 0 && x < (WIN_HOR_SIZE - VIG_HOR_SIZE) && win->fract >= 5)
		{
			if (win->motion == 0)
				win->motion = 1;
			else
				win->motion = 0;
		}
	}
	// mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
	// win->img.img_ptr = mlx_new_image(win->mlx_ptr, IMG_HOR_SIZE, IMG_VER_SIZE);
	ft_multithreading(win);
	if (win->motion == 1)
		ft_viseur(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->vig.img_ptr, 800, 0);
	ft_print_menu(win);
	// ft_put_vig(win);
	return (0);
}

int		deal_expose(t_win *win)
{
	ft_multithreading(win);
	// ft_viseur(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
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
				|| !ft_strcmp(av[1], "flower3") || !ft_strcmp(av[1], "duobrot"))
	{
		ft_select_fractale(&win, av[1]);
		ft_hook(&win);
	}
	else
		ft_usage();	
	return (0);
}
