/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_vig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:38:11 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/06 00:39:18 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mlx_put_pixel_to_image_2(t_win **win, int x, int y, int a)
{
	int		octet;

	octet = (*win)->bpp2 / 8;
	if (x >= 0 && y >= 0 && x < IMG_HOR_SIZE && y < IMG_VER_SIZE)
	{
		if (!(ft_memcpy(&(*win)->data2[octet * x + (*win)->sizeline2 * y], \
			&a, octet)))
			ft_putstr("wow c chaud");
	}
}

void	ft_put_vig(t_win **win)
{
	int x;
	int y;
	int color, a, r, g, b;
	a = 180;
	r = 100;
	g = 100;
	b = 100;
	
	if ((*win)->it_max != (*win)->old_it_max)
	{
		x = 0;
		while (x < VIG_HOR_SIZE)
		{
			y = 0;
			while (y < WIN_VER_SIZE)
			{
				if (y == 140 || y == 280 || y == 420 || y == 560 || x == 0)
					color = 256 * 256 * r + 256 * g + b;
				else
					color = 256 * 256 * 256 * a + 256 * 256 * r + 256 * g + b;
				mlx_put_pixel_to_image_2(win, x, y, color);
				y++;
			}
			x++;
		}
		ft_create_mandelbrot2(win);
		ft_create_julia2(win);
		(*win)->old_it_max = (*win)->it_max;
	}
	mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_vig, 800, 0);
}