/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:48:56 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/11 20:04:41 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_usage(void)
{
	write(1, "usage: ./fractol mandelbrot / duobrot / julia / tricorne / \
		burningship / flower / flower2 / flower3\n", 100);
	exit(EXIT_FAILURE);
}

int			ft_exit(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
	mlx_destroy_image(win->mlx_ptr, win->vig.img_ptr);
	ft_putstr("oublie pas de gerer exit ;)");
	exit(EXIT_SUCCESS);
}
