/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vignettes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:38:11 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/14 18:08:33 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_vig(t_win *win, int test)
{
	int		x;
	int		y;
	double	color;

	if ((win->p.it_max != win->p.old_it_max && win->p.it_max < 100) || test == 1)
	{
		x = 0;
		while (x < VIG_HOR_SIZE)
		{
			y = 0;
			while (y < IMG_VIG_VER_SIZE)
			{
				if (y == 0 || y == 131 || y == 263 || y == 395 || y == 527 || y == 659 || x == 0 || x == 189)
					color = 256 * 256 * 100 + 256 * 100 + 100;
				else
					color = 256 * 256 * 256 * 180 + 256 * 256 * 100 \
						+ 256 * 100 + 100;
				mlx_put_pixel_to_image(win->vig, x, y, color);
				y++;
			}
			x++;
		}
		ft_multithreading_vig(win);
		win->p.old_it_max = win->p.it_max;
	}
}
