/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_fractale.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:37:00 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/14 01:35:10 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_select_fractale(t_win *win, char *str)
{
	if (!ft_strcmp(str, "mandelbrot"))
		win->fract = 1;
	else if (!ft_strcmp(str, "duobrot"))
		win->fract = 2;
	else if (!ft_strcmp(str, "tricorn"))
		win->fract = 3;
	else if (!ft_strcmp(str, "burningship"))
		win->fract = 4;
	else if (!ft_strcmp(str, "palmtree"))
		win->fract = 5;
	else if (!ft_strcmp(str, "julia"))
		win->fract = 6;
	else if (!ft_strcmp(str, "andy"))
		win->fract = 7;
	else if (!ft_strcmp(str, "microcells"))
		win->fract = 8;
	else if (!ft_strcmp(str, "brain"))
		win->fract = 9;
	else if (!ft_strcmp(str, "flower"))
		win->fract = 10;
	ft_reset_fractale(win);
}

void		ft_reset_fractale(t_win *win)
{
	if (win->fract <= 5)
		ft_init_mandelbrot(win);
	else if (win->fract > 5)
		ft_init_julia(win);
	win->p.moove_hor = 0;
	win->p.moove_ver = 0;
	win->p.it_max = 50;
	win->p.old_it_max = 0;
	win->p.rc = 0;
	win->p.ic = 0;
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
		if (win->fract <= 5)
			if (pthread_create(&mthrds->threads[i], NULL, \
				ft_create_mandelbrot, &mthrds->thrd[i]))
				ft_exit(win);
		if (win->fract > 5)
			if (pthread_create(&mthrds->threads[i], NULL, \
				ft_create_julia, &mthrds->thrd[i]))
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
