/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:48:56 by auguyon           #+#    #+#             */
/*   Updated: 2019/03/08 17:44:33 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_usage(void)
{
	write(1, "usage: ./fractol mandelbrot / julia / tricorne / burningship / flower\n", 47);
	exit(EXIT_FAILURE);
}

int			ft_exit(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
	mlx_destroy_image(win->mlx_ptr, win->vig.img_ptr);
	ft_putstr("oublie pas de gerer exit ;)");
	exit(EXIT_SUCCESS);
}
