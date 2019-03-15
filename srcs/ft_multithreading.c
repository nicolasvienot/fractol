/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multithreading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:27:56 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/15 12:48:34 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*ft_vig(void *thrds)
{
	t_thrd		*thrd;

	thrd = (t_thrd *)thrds;
	ft_create_mandelbrot_vig(thrd);
	ft_create_duobrot_vig(thrd);
	ft_create_tricorn_vig(thrd);
	ft_create_julia_vig(thrd);
	ft_create_andy_vig(thrd);
	pthread_exit(NULL);
}

void		ft_multithreading(t_win *win)
{
	t_mthrds	*mthrds;
	int			i;

	mthrds = &win->mthrds;
	i = -1;
	while (++i < NB_THREADS)
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
	}
	i = -1;
	while (++i < NB_THREADS)
	{
		if (pthread_join(mthrds->threads[i], NULL))
			ft_exit(win);
	}
}

void		ft_multithreading_vig(t_win *win)
{
	t_mthrds	*mthrds;
	int			i;

	mthrds = &win->mthrds;
	i = 0;
	while (i < NB_THREADS)
	{
		mthrds->thrd[i].id = i;
		mthrds->thrd[i].w = win;
		if (pthread_create(&mthrds->threads[i], NULL, \
			ft_vig, &mthrds->thrd[i]))
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
