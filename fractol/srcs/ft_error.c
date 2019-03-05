/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:48:56 by auguyon           #+#    #+#             */
/*   Updated: 2019/03/04 22:54:42 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_usage(void)
{
	write(1, "usage: ./fractol file\n", 22);
	exit(EXIT_FAILURE);
}

int			ft_exit(t_win **win)
{
	free(*win);
	exit(EXIT_SUCCESS);
}