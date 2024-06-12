/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:21:32 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/06/11 10:23:18 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_iter(t_data *data, t_pixel z, t_pixel c)
{
	t_data	tmp;
	int		iteration;

	iteration = 0;
	while ((z.re * z.re) + (z.im * z.im) < 4 && iteration < data->max)
	{
		tmp.re = ((z.re * z.re) - (z.im * z.im)) + c.re;
		tmp.im = 2 * z.re * z.im + c.im;
		z.re = tmp.re;
		z.im = tmp.im;
		iteration++;
	}
	return (iteration);
}

int	init_fractol(t_data *data)
{
	int	color;
	int	iter;

	iter = 0;
	data->pxl.re = ft_scale_x(data, data->x);
	data->pxl.im = ft_scale_y(data, data->y);
	if (data->parsing == 1)
	{
		iter = calc_mandelbrot(data);
	}
	else if (data->parsing == 2)
	{
		iter = calc_julia(data);
	}
	color = ft_color(iter, data->max);
	put_pixel(data, data->x, data->y, color);
	return (0);
}

int	calc_fractol(t_data *data)
{
	data->x = 0;
	data->y = 0;
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			init_fractol(data);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->fract_mlx, \
			data->fract_win, data->fract_img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (fractol_parssing(av, ac, &data) == 0)
		exit(1);
	mlx_win(&data);
	ft_handle_hook(&data);
	mlx_loop(data.fract_mlx);
	fractol_exit(&data);
	return (0);
}
