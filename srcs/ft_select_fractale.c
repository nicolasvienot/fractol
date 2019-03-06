/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_fractale.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:37:00 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/06 19:23:28 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_win	*ft_select_fractale(char *str)
{
	t_win	*win;

	if (!(win = (t_win*)malloc(sizeof(t_win))))
		return (0);
	ft_init_start(&win);
	if (!ft_strcmp(str, "mandelbrot"))
	{
		win->fract = 1;
		ft_init_mandelbrot(&win);
	}
	if (!ft_strcmp(str, "julia"))
	{
		win->fract = 2;
		ft_init_julia(&win);
	}
	if (!ft_strcmp(str, "tricorne"))
	{
		win->fract = 3;
		ft_init_mandelbrot(&win);
	}
	if (!ft_strcmp(str, "burningship"))
	{
		win->fract = 4;
		ft_init_mandelbrot(&win);
	}
	return (win);
}

void	ft_reset_fractale(t_win **win)
{
	if ((*win)->fract == 1)
		ft_init_mandelbrot(win);
	if ((*win)->fract == 2)
		ft_init_julia(win);
	if ((*win)->fract == 3)
		ft_init_mandelbrot(win);
	if ((*win)->fract == 4)
		ft_init_mandelbrot(win);
	(*win)->moove_hor = 0;
	(*win)->moove_ver = 0;
}

void	ft_draw_fractale(t_win **win)
{
	if ((*win)->fract == 1)
		ft_create_mandelbrot(win);
	if ((*win)->fract == 2)
		ft_create_julia(win);
	if ((*win)->fract == 3)
		ft_create_tricorn(win);
	if ((*win)->fract == 4)
		ft_create_bship(win);
	mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 0, 0);
	ft_print_menu(win);
	ft_put_vig(win);
}

void		ft_multithreading(t_win *win)
{
	t_render	*render2;
	int			i;

	i = 0;
	render2 = &win->render;
	while (i < NB_THREADS)
	{
		render2->thrds[i].id = i;
		render2->thrds[i].win = win;
		if (pthread_create(&render2->threads[i], NULL, ft_create_mandelbrot_multi, &render2->thrds[i]))
		{
			ft_putstr("erreur pthread create poto");
			return ;
		}
		i++;
	}
	i = 0;
	while (i < NB_THREADS)
	{
		if (pthread_join(render2->threads[i], NULL))
		{
			ft_putstr("erreur pthread join poto");
			return ;
		}
		i++;
	}
}