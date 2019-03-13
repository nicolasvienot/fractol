/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vignettes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:38:11 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/13 20:16:20 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_vig(t_win *win)
{
	int		x;
	int		y;
	double	color;

	if (win->p.it_max != win->p.old_it_max)
	{
		x = 0;
		while (x < VIG_HOR_SIZE)
		{
			y = 0;
			while (y < WIN_VER_SIZE)
			{
				if (y == 140 || y == 280 || y == 420 || y == 560 || x == 0)
					color = 256 * 256 * 100 + 256 * 100 + 100;
				else
					color = 256 * 256 * 256 * 180 + 256 * 256 * 100 \
						+ 256 * 100 + 100;
				mlx_put_pixel_to_image(&win->vig, x, y, color);
				y++;
			}
			x++;
		}
		ft_multithreading_vig(win);
		win->p.old_it_max = win->p.it_max;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->vig.img_ptr, 800, 0);
}
