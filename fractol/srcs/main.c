/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/05 01:37:09 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int			deal_key(int keycode, t_win **win)
{
	if (keycode == ARROW_DOWN)
		(*win)->moove_ver += SIZE_MOV;
	else if (keycode == ARROW_UP)
		(*win)->moove_ver -= SIZE_MOV;
	else if (keycode == ARROW_RIGHT)
		(*win)->moove_hor += SIZE_MOV;
	else if (keycode == ARROW_LEFT)
		(*win)->moove_hor -= SIZE_MOV;
	else if (keycode == TOUCH_PLUS)
		(*win)->it_max += 5;
	else if (keycode == TOUCH_LESS && (*win)->it_max >= 5)
		(*win)->it_max -= 5;
	else if (keycode == TOUCH_ESC)
		ft_exit(win);
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_ptr);
	(*win)->img_ptr = mlx_new_image((*win)->mlx_ptr, IMG_HOR_SIZE, IMG_VER_SIZE);
	ft_create_julia(win);
	// ft_create_mandelbrot(win);
	// ft_create_testlol(win);
	mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 0, 0);
	ft_print_menu(win);
	return (1);
}

int			deal_mouse(int mouse, int x, int y, t_win **win)
{
	double	oldx;
	double	oldy;

	if (x > 0 && y > 0)
	{
		oldx = (*win)->x1 + x / (*win)->zoom;
		oldy = (*win)->y1 + y / (*win)->zoom;
		if (mouse == 4)
		{	
			(*win)->zoom /= COEF_ZOOM;
			(*win)->x1 = oldx - x / (*win)->zoom;
			(*win)->y1 = oldy - y / (*win)->zoom;
		}
		if (mouse == 5)
		{
			(*win)->zoom *= COEF_ZOOM;
			(*win)->x1 = oldx - x / (*win)->zoom;
			(*win)->y1 = oldy - y / (*win)->zoom;
		}
	}
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_ptr);
	(*win)->img_ptr = mlx_new_image((*win)->mlx_ptr, IMG_HOR_SIZE, IMG_VER_SIZE);
	ft_create_julia(win);
	// ft_create_mandelbrot(win);
	// ft_create_testlol(win);
	mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 0, 0);
	ft_print_menu(win);
	return (0);
}

// int		deal_expose(t_win **win)
// {
// 	ft_anim_background(win);
// 	ft_print_menu(win);
// 	mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
// 	(*win)->img_ptr, 300, 150);
// 	return (1);
// }

void	ft_hook(t_win **win)
{
	mlx_hook((*win)->win_ptr, 2, 1L << 0, deal_key, win);
	mlx_mouse_hook((*win)->win_ptr, deal_mouse, win);
	// mlx_expose_hook((*win)->win_ptr, deal_expose, win);
	mlx_hook((*win)->win_ptr, 17, 1L << 17, ft_exit, win);
	mlx_loop((*win)->mlx_ptr);
}

void	ft_init_start(t_win **win)
{
	(*win)->mlx_ptr = mlx_init();
	(*win)->win_ptr = mlx_new_window((*win)->mlx_ptr, WIN_HOR_SIZE, WIN_VER_SIZE, "FRACT'OL");
	(*win)->img_ptr = mlx_new_image((*win)->mlx_ptr, IMG_HOR_SIZE, IMG_VER_SIZE);
	(*win)->data = mlx_get_data_addr((*win)->img_ptr, &(*win)->bpp, &(*win)->sizeline, &(*win)->endian);
	(*win)->moove_hor = 0;
	(*win)->moove_ver = 0;
	// (*win)->x1 = -2;
	// (*win)->y1 = -1.189;
	(*win)->x1 = -1.95;
	(*win)->y1 = -1.95;
	(*win)->zoom = 200;
	(*win)->it_max = 100;
	// if (!((*win)->filename = ft_get_file_name(av1)))
	// 	ft_exit(-42);
	// (*win)->start = 0;
	// (*win)->proj = 1;
	// (*win)->rota = 0;
	// (*win)->aff_x = 0;
	// (*win)->aff_y = 0;
	// (*win)->zix = 1;
	// (*win)->menu = 0;
	// (*win)->img = 0;
	// (*win)->choosecolor = 0;
	// ft_init_pix_and_pos_orthographic_projection(win);
	// ft_get_color(win);
}

int		main(int ac, char **av)
{
	t_win	*win;

	if (ac != 2)
		ft_usage();
	if (!(win = (t_win*)malloc(sizeof(t_win))))
		return (0);
	if (!ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "mandelbrot"))
	{
		if (!(win = (t_win*)malloc(sizeof(t_win))))
			return (0);
		ft_init_start(&win);
		ft_create_julia(&win);
		// ft_create_mandelbrot(&win);
		// ft_create_testlol(&win);
		mlx_put_image_to_window((win)->mlx_ptr, (win)->win_ptr, \
			(win)->img_ptr, 0, 0);
		ft_print_menu(&win);
	}
	else
		ft_usage();	
	ft_hook(&win);
	return (0);
}
