/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:47:50 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/06/11 10:13:48 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_scale_x(t_data *data, int k)
{
	return ((k - WIDTH / 2.0) * (4.0 * data->zoom) / WIDTH);
}

double	ft_scale_y(t_data *data, int k)
{
	return (-(k - HEIGHT / 2.0) * (4.0 * data->zoom) / HEIGHT);
}

int	calc_mandelbrot(t_data *data)
{
	data->c.re = 0;
	data->c.im = 0;
	return (calc_iter(data, data->c, data->pxl));
}

int	calc_julia(t_data *data)
{
	data->c.re = data->j_x;
	data->c.im = data->j_y;
	return (calc_iter(data, data->pxl, data->c));
}
