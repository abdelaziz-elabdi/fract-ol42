/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:42:34 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/06/10 12:29:57 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_esc(int key, t_data *data)
{
	if (key == 53)
		fractol_exit(data);
	return (0);
}

int	fractol_key(int key, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (key == 4)
		data->zoom *= 1.3;
	else if (key == 5)
		data->zoom /= 1.3;
	return (0);
}

int	fractol_exit(t_data *data)
{
	mlx_destroy_image(data->fract_mlx, data->fract_img);
	mlx_destroy_window(data->fract_mlx, data->fract_win);
	exit(0);
}

void	ft_handle_hook(t_data *data)
{
	mlx_key_hook(data->fract_win, ft_key_esc, data);
	mlx_mouse_hook(data->fract_win, fractol_key, data);
	mlx_hook(data->fract_win, 17, 0, fractol_exit, data);
	mlx_loop_hook(data->fract_mlx, calc_fractol, data);
}
