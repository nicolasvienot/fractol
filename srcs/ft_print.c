/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:29:22 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/18 17:10:10 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_get_pow(t_win *win)
{
	char	*x;
	char	*y;
	float	ent;
	int		dec;

	ent = (float)win->p.power;
	dec = ((int)(10 * ent) % 10);
	x = ft_strjoinnfree(ft_itoa(ent), ".", 1);
	x = ft_strjoinnfree(x, ft_itoa(dec), 3);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 170, 45, GREY, x);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 140, 25, \
		GREY, y = ft_itoa(win->p.it_max));
	free(x);
	free(y);
}

static void	ft_print_color(t_win *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 65, GREY, "Color pal |");
	if (win->pal == 1)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 130, 65, GREY, P1);
	else if (win->pal == 2)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 130, 65, GREY, P2);
	else if (win->pal == 3)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 130, 65, GREY, P3);
	else if (win->pal == 4)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 130, 65, GREY, P4);
	else if (win->pal == 5)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 130, 65, GREY, P5);
	else if (win->pal == 6)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 130, 65, GREY, P6);
	else if (win->pal == 7)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 130, 65, GREY, P7);
}

static void	ft_print_menu_2(t_win *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 105, \
		GREY, "Move : Arrow keys");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 125, GREY, "Zoom : Scroll");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 145, \
		GREY, "Change fractal : +/-");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 165, \
		GREY, "Change iterations : Page-up/Page-down");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 185, \
		GREY, "Change power : 0.1 = </> | 1 = [/]");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 205, \
		GREY, "Change color variation : C");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 225, \
		GREY, "Change color palette : X");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 245, \
		GREY, "Activate motion mode : M/Click");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 265, \
		GREY, "Activate sample mode : V");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 285, \
		GREY, "Activate immersive mode : X");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 305, GREY, "Reset : R");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 325, GREY, "Quit : Esc");
}

static void	ft_print_menu_1(t_win *win)
{
	if (win->fract == 1)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 110, 5, GREY, F1);
	else if (win->fract == 2)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 110, 5, GREY, F2);
	else if (win->fract == 3)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 110, 5, GREY, F3);
	else if (win->fract == 4)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 110, 5, GREY, F4);
	else if (win->fract == 5)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 110, 5, GREY, F5);
	else if (win->fract == 6)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 110, 5, GREY, F6);
	else if (win->fract == 7)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 110, 5, GREY, F7);
	else if (win->fract == 8)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 110, 5, GREY, F8);
	else if (win->fract == 9)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 110, 5, GREY, F9);
	else if (win->fract == 10)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 110, 5, GREY, F10);
	else if (win->fract == 11)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 110, 5, GREY, F11);
	else if (win->fract == 12)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 110, 5, GREY, F12);
}

void		ft_print_menu(t_win *w)
{
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, 5, GREY, "Fractal | ");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, 25, GREY, "Iterations |");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, 45, GREY, "Power (Multi) |");
	ft_print_menu_1(w);
	ft_print_color(w);
	ft_get_pow(w);
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, 85, \
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
