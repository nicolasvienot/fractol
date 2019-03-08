/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vignettes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:38:11 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/08 17:44:14 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void		mlx_put_pixel_to_image_2(t_img *img, int x, int y, int a)
// {
// 	int		octet;

// 	octet = img->bpp / 8;
// 	if (x >= 0 && y >= 0 && x < IMG_HOR_SIZE && y < IMG_VER_SIZE)
// 	{
// 		if (!(ft_memcpy(&img->data[octet * x + img->sizeline * y], &a, octet)))
// 			ft_putstr("wow c chaud");
// 	}
// }

void	ft_put_vig(t_win *win)
{
	int x;
	int y;
	int color, a, r, g, b;
	a = 180;
	r = 100;
	g = 100;
	b = 100;
	
	if (win->params.it_max != win->params.old_it_max)
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
				mlx_put_pixel_to_image(&win->vig, x, y, color);
				y++;
			}
			x++;
		}
		ft_multithreading_vig(win);
		win->params.old_it_max = win->params.it_max;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->vig.img_ptr, 800, 0);
}