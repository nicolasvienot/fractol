/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:48:56 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/16 03:28:56 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_usage(void)
{
	write(1, "Usage: ./fractol [fractal name]\n\n", 34);
	write(1, "Fractal names (use name, with uppercase letter) :\n", 51);
	write(1, "1. Mandelbrot\n2. Duobrot\n3. Tricorn\n4. Burningship\n", 52);
	write(1, "5. Palmtree\n6. Multibrot\n7. Julia\n8. Andy\n", 43);
	write(1, "9. Microcells\n10. Brain\n11. Flower\n12. Multijulia\n", 51);
	write(1, "\nExample: './fractol Mandelbrot' - Displays Mandelbrot\n", 56);
	exit(EXIT_FAILURE);
}

int			ft_exit(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
	mlx_destroy_image(win->mlx_ptr, win->vig.img_ptr);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit(EXIT_SUCCESS);
}
