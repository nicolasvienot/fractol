/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:48:56 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/14 01:38:50 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_usage(void)
{
	write(1, "usage: ./fractol mandelbrot / duobrot / tricorn / burningship / \
palmtree / julia / andy / microcells / brain / flower\n", 118);
	exit(EXIT_FAILURE);
}

int			ft_exit(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
	mlx_destroy_image(win->mlx_ptr, win->vig.img_ptr);
	ft_putstr("oublie pas de gerer exit ;) et de voir avec pthread");
	exit(EXIT_SUCCESS);
}
