/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:29:22 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/16 01:52:14 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_get(t_win *win)
{
	printf("%f\n", win->p.pow);
	char *x;

	float salut;
	int salut2;

	salut = (float)win->p.pow;
	salut2 = (int)(10 * salut);
	salut2 = salut2 % 10;

	x = ft_itoa(salut);
	x = ft_strjoinnfree(x, ".", 1);
	x = ft_strjoinnfree(x, ft_itoa(salut2), 3);

	mlx_string_put(win->mlx_ptr, win->win_ptr, 170, 45, GREY, x);

	free(x);
}

static void	ft_print_menu_1(t_win *win)
{
	char *x;

	if (win->fract == 1)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 5, GREY, F1);
	else if (win->fract == 2)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 5, GREY, F2);
	else if (win->fract == 3)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 5, GREY, F3);
	else if (win->fract == 4)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 5, GREY, F4);
	else if (win->fract == 5)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 5, GREY, F5);
	else if (win->fract == 6)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 5, GREY, F6);
	else if (win->fract == 7)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 5, GREY, F7);
	else if (win->fract == 8)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 5, GREY, F8);
	else if (win->fract == 9)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 5, GREY, F9);
	else if (win->fract == 10)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 5, GREY, F10);
	else if (win->fract == 11)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 5, GREY, F11);
	else if (win->fract == 12)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 5, GREY, F12);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 140, 25, \
		GREY, x = ft_itoa(win->p.it_max));
	// ft_get(win);
	free(x);
}

static void	ft_print_menu_2(t_win *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 85, \
		GREY, "Move : Arrow keys");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 105, GREY, "Zoom : Scroll");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 125, \
		GREY, "Change fractale : +/-");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 145, \
		GREY, "Change iterations : Page-up/Page-down");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 165, \
		GREY, "Change power : 0.1 = </> | 1 = [/]");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 185, \
		GREY, "Change color variation : C");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 205, \
		GREY, "Change color palette : X");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 225, \
		GREY, "Activate motion mode : M/Click");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 245, \
		GREY, "Activate sample mode : V");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 265, \
		GREY, "Activate immersive mode : X");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 285, GREY, "Reset : R");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 305, GREY, "Quit : Esc");
}

void		ft_print_menu(t_win *w)
{
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, 5, GREY, "Fractale | ");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, 25, GREY, "Iterations |");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, 45, GREY, "Power (Multi) |");
	ft_print_menu_1(w);
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, 65, \
		GREY, "Press Z to display controls");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, 635, GREY, "Motion_ju mode");
	if (w->motion == 1)
		mlx_string_put(w->mlx_ptr, w->win_ptr, 160, 635, GREEN, "ON");
	else
		mlx_string_put(w->mlx_ptr, w->win_ptr, 160, 635, RED, "OFF");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, 655, GREY, "Sample_it mode ");
	if (w->vig_it == 1)
		mlx_string_put(w->mlx_ptr, w->win_ptr, 160, 655, GREEN, "ON");
	else
		mlx_string_put(w->mlx_ptr, w->win_ptr, 160, 655, RED, "OFF");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, 675, GREY, "Immersive mode");
	if (w->immersive == 1)
		mlx_string_put(w->mlx_ptr, w->win_ptr, 160, 675, GREEN, "ON");
	else
		mlx_string_put(w->mlx_ptr, w->win_ptr, 160, 675, RED, "OFF");
	if (w->menu == 1)
		ft_print_menu_2(w);
}

void		mlx_put_pixel_to_image(t_img img, int x, int y, int a)
{
	int		octet;

	octet = img.bpp / 8;
	if (x >= 0 && y >= 0 && x < IMG_HOR_SIZE && y < IMG_VER_SIZE)
	{
		if (!(ft_memcpy(&img.data[octet * x + img.sizeline * y], \
			&a, octet)))
			return ;
	}
}

void		ft_viseur(t_win *win)
{
	int x;
	int y;
	int color;

	x = (WIN_HOR_SIZE / 2) + 2;
	y = (WIN_VER_SIZE / 2) - 1 - 8;
	color = WHITE;
	while (y <= (WIN_VER_SIZE / 2) - 1 + 8)
	{
		mlx_put_pixel_to_image(win->img, x, y, color);
		y++;
	}
	y = (WIN_VER_SIZE / 2) - 1;
	x = (WIN_HOR_SIZE / 2) + 2 - 8;
	while (x <= (WIN_HOR_SIZE / 2) + 2 + 8)
	{
		mlx_put_pixel_to_image(win->img, x, y, color);
		x++;
	}
}
