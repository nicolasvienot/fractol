/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:29:22 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/08 17:18:16 by nvienot          ###   ########.fr       */
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

// static void	ft_print_menu_2(t_win *win)
// {
	// char *x;
	// char *y;

	// if (!(x = ft_itoa(win->aff_x - (WIN_HOR_SIZE - IMG_HOR_SIZE) / 2)))
	// 	ft_exit(-42);
	// if (!(y = ft_itoa(win->aff_y - (WIN_VER_SIZE - IMG_VER_SIZE) / 2)))
	// 	ft_exit(-42);
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 195, 440, PURPLE, "X = ");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 235, 440, PURPLE, x);
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 195, 465, PURPLE, "Y = ");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 235, 465, PURPLE, y);
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1500, 10, PURPLE, \
	// 		"Press M to display");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1500, 30, PURPLE, \
	// 		"or hide the menu");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1500, 60, PURPLE, \
	// 		"Hold * to get");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1500, 80, PURPLE, \
	// 		"the animation");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 950, 970, PURPLE, \
	// 	"MAP NAME :");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1060, 970, PURPLE, \
	// 	win->filename);

	// free(x);
	// free(y);
// }

static void	ft_print_menu_1(t_win *win)
{
	char *x;
	char *y;

	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 10, GREY, "Fractale : ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 115, 10, GREY, x = ft_itoa(win->fract));
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 30, GREY, "Modifier iterations : O/P | ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 290, 30, GREY, y = ft_itoa(win->params.it_max));
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 50, GREY, "Zoom : Molette");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 70, GREY, "Restart : R");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 90, GREY, "Modifier variation couleur : C");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 110, GREY, "Modifier palette couleur : V");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 130, GREY, "Quit : Esc");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1520, 390, PURPLE, \
	// 	"MENU ");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1440, 420, PURPLE, \
	// 		"Parallel projection : P");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1440, 440, PURPLE, \
	// 		"Isometric projection : I");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1440, 460, PURPLE, \
	// 		"Restart : O");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1440, 480, PURPLE, \
	// 		"Increase alt : Page up");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1440, 500, PURPLE, \
	// 		"Decrease alt : Page down");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1440, 520, PURPLE, \
	// 		"Zoom in : + / Scroll");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1440, 540, PURPLE, \
	// 		"Zoom out : - / Scroll");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1440, 560, PURPLE, \
	// 		"Move : Arrow keys");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1440, 580, PURPLE, \
	// 		"Rotate : R & T");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1440, 600, PURPLE, \
	// 		"Change color type : C");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1440, 620, PURPLE, \
	// 	"Quit : Esc");

	free (x);
	free (y);
}

int			ft_print_menu(t_win *win)
{
	// if (win->menu == 1)
	ft_print_menu_1(win);
	// ft_print_menu_2(win);
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
