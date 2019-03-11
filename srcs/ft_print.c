/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:29:22 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/11 17:30:40 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// static void	ft_print_menu_3(t_win *win)
// {
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 285, 970, PURPLE, \
	// 		"Color type :");
	// if (win->choosecolor == 0)
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 415, 970, PURPLE, \
	// 		"Color gradient w/ GREY");
	// else if (win->choosecolor == 1)
	// 	mlx_string_put(win->mlx_ptr, win->win_ptr, 415, 970, PURPLE, \
	// 		"Color gradient");
	// else if (win->choosecolor == 2)
	// 	mlx_string_put(win->mlx_ptr, win->win_ptr, 415, 970, PURPLE, \
	// 		"Colors from file");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 1075, PURPLE, \
	// 		"Copyright 2019 nvienot");
// }

static void	ft_print_menu_2(t_win *win)
{
	if (win->fract == 1)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 10, GREY, "Mandelbrot");
	else if (win->fract == 2)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 10, GREY, "Duobrot");
	else if (win->fract == 3)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 10, GREY, "Tricorn");
	else if (win->fract == 4)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 10, GREY, "BurningShip");
	else if (win->fract == 5)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 10, GREY, "Julia");
	else if (win->fract == 6)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 10, GREY, "Flower");
	else if (win->fract == 7)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 10, GREY, "Flower2");
	else if (win->fract == 8)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 10, GREY, "Flower3");
}

static void	ft_print_menu_1(t_win *win)
{
	// char *x;
	char *y;

	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 10, GREY, "Fractale : ");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 10, GREY, x = ft_itoa(win->fract));
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 30, GREY, "Modifier iterations : O/P | ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 290, 30, GREY, y = ft_itoa(win->params.it_max));
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 50, GREY, "Move : Arrow keys");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 70, GREY, "Zoom : Molette");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 90, GREY, "Change fractale : -/+");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 110, GREY, "Modifier variation couleur : C");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 130, GREY, "Modifier palette couleur : V");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 150, GREY, "Motion : ");
	if (win->motion == 1)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 100, 150, GREEN, "ON");
	else
		mlx_string_put(win->mlx_ptr, win->win_ptr, 100, 150, RED, "OFF");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 150, GREY, "Motion : ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 170, GREY, "Restart : R");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 190, GREY, "Quit : Esc");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1520, 390, PURPLE, \
	// 	"MENU ");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1440, 580, PURPLE, \
	// 		"Rotate : R & T");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1440, 600, PURPLE, \
	// 		"Change color type : C");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1440, 620, PURPLE, \
	// 	"Quit : Esc");

	// free (x);
	free (y);
}

int			ft_print_menu(t_win *win)
{
	// if (win->menu == 1)
	ft_print_menu_1(win);
	ft_print_menu_2(win);
	// ft_print_menu_3(win);
	return (1);
}

void		mlx_put_pixel_to_image(t_img *img, int x, int y, int a)
{
	int		octet;

	octet = img->bpp / 8;
	if (x >= 0 && y >= 0 && x < IMG_HOR_SIZE && y < IMG_VER_SIZE)
	{
		if (!(ft_memcpy(&img->data[octet * x + img->sizeline * y], \
			&a, octet)))
			ft_putstr("wow c chaud");
	}
}

void		ft_viseur(t_win *win)
{
	int x;
	int y;
	int color;
	x = WIN_HOR_SIZE / 2;
	y = (WIN_VER_SIZE / 2) - 8;
	color = WHITE;
	while (y <= (WIN_VER_SIZE / 2) + 8)
	{
		mlx_put_pixel_to_image(&win->img, x, y, color);
		y++;
	}
	y = WIN_VER_SIZE / 2;
	x = (WIN_HOR_SIZE / 2) - 8;
	while (x <= (WIN_HOR_SIZE / 2) + 8)
	{
		mlx_put_pixel_to_image(&win->img, x, y, color);
		x++;
	}
}
