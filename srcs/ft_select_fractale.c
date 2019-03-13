/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_fractale.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:37:00 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/14 00:12:12 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_select_fractale(t_win *win, char *str)
{
	ft_init_start(win);
	if (!ft_strcmp(str, "mandelbrot"))
	{
		win->fract = 1;
		ft_init_mandelbrot(win);
	}
	if (!ft_strcmp(str, "julia"))
	{
		win->fract = 5;
		ft_init_julia(win);
	}
	if (!ft_strcmp(str, "tricorne"))
	{
		win->fract = 3;
		ft_init_mandelbrot(win);
	}
	if (!ft_strcmp(str, "burningship"))
	{
		win->fract = 4;
		ft_init_mandelbrot(win);
	}
	if (!ft_strcmp(str, "flower"))
	{
		win->fract = 6;
		ft_init_julia(win);
	}
	if (!ft_strcmp(str, "flower2"))
	{
		win->fract = 7;
		ft_init_julia(win);
	}
	if (!ft_strcmp(str, "flower3"))
	{
		win->fract = 8;
		ft_init_julia(win);
	}
	if (!ft_strcmp(str, "duobrot"))
	{
		win->fract = 2;
		ft_init_mandelbrot(win);
	}
	if (!ft_strcmp(str, "juliacarre"))
	{
		win->fract = 9;
		ft_init_julia(win);
	}
	ft_put_vig(win, 1);
}

void		ft_reset_fractale(t_win *win)
{
	if (win->fract == 1)
		ft_init_mandelbrot(win);
	if (win->fract == 5)
		ft_init_julia(win);
	if (win->fract == 3)
		ft_init_mandelbrot(win);
	if (win->fract == 4)
		ft_init_mandelbrot(win);
	if (win->fract == 6)
		ft_init_julia(win);
	if (win->fract == 7)
		ft_init_julia(win);
	if (win->fract == 8)
		ft_init_julia(win);
	if (win->fract == 2)
		ft_init_mandelbrot(win);
	if (win->fract == 9)
		ft_init_julia(win);
	win->p.moove_hor = 0;
	win->p.moove_ver = 0;
}

void		ft_multithreading(t_win *win)
{
	t_mthrds	*mthrds;
	int			i;

	i = 0;
	mthrds = &win->mthrds;
	while (i < NB_THREADS)
	{
		mthrds->thrd[i].id = i;
		mthrds->thrd[i].w = win;
		if (win->fract <= 4)
			if (pthread_create(&mthrds->threads[i], NULL, \
				ft_create_mandelbrot_multi, &mthrds->thrd[i]))
				ft_exit(win);
		if (win->fract > 4)
			if (pthread_create(&mthrds->threads[i], NULL, \
				ft_create_julia_multi, &mthrds->thrd[i]))
				ft_exit(win);
		i++;
	}
	i = 0;
	while (i < NB_THREADS)
	{
		if (pthread_join(mthrds->threads[i], NULL))
			ft_exit(win);
		i++;
	}
}

void		ft_multithreading_vig(t_win *win)
{
	t_mthrds	*mthrds;
	int			i;

	i = 0;
	mthrds = &win->mthrds;
	while (i < NB_THREADS)
	{
		mthrds->thrd[i].id = i;
		mthrds->thrd[i].w = win;
		if (pthread_create(&mthrds->threads[i], NULL, \
			ft_create_mandelbrot_vig, &mthrds->thrd[i]))
			ft_exit(win);
		if (pthread_create(&mthrds->threads[i], NULL, \
			ft_create_julia_vig, &mthrds->thrd[i]))
			ft_exit(win);
		if (pthread_create(&mthrds->threads[i], NULL, \
			ft_create_tricorn_vig, &mthrds->thrd[i]))
			ft_exit(win);
		if (pthread_create(&mthrds->threads[i], NULL, \
			ft_create_bship_vig, &mthrds->thrd[i]))
			ft_exit(win);
		if (pthread_create(&mthrds->threads[i], NULL, \
			ft_create_flower_vig, &mthrds->thrd[i]))
			ft_exit(win);
		i++;
	}
	i = 0;
	while (i < NB_THREADS)
	{
		if (pthread_join(mthrds->threads[i], NULL))
			ft_exit(win);
		i++;
	}
}
