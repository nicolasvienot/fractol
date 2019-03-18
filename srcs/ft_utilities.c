/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:45:48 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/18 23:18:23 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_usage(void)
{
	write(1, "Usage: ./fractol [fractal name]\n\n", 34);
	write(1, "Fractal names (use name, with uppercase letter) :\n", 51);
	write(1, "1. Mandelbrot\n2. Duobrot\n3. Tricorn\n4. BurningShip\n", 52);
	write(1, "5. Palmtree\n6. Multibrot\n7. Julia\n8. Andy\n", 43);
	write(1, "9. Microcells\n10. Brain\n11. Flower\n12. Multijulia\n", 51);
	write(1, "\nExample: './fractol Mandelbrot' - Displays Mandelbrot\n", 56);
	exit(EXIT_FAILURE);
}

int				ft_exit(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
	mlx_destroy_image(win->mlx_ptr, win->vig.img_ptr);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit(EXIT_SUCCESS);
}

void			ft_viseur(t_win *win)
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

void			mlx_put_pixel_to_image(t_img img, int x, int y, int a)
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
