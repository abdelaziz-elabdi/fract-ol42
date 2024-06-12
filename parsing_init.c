/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:37:55 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/06/11 10:30:27 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_win(t_data *data)
{
	data->zoom = 1;
	data->max = 100;
	data->fract_mlx = mlx_init();
	if (!data->fract_mlx)
		exit(1);
	data->fract_win = mlx_new_window(data->fract_mlx, \
			WIDTH, HEIGHT, "FRACTAL");
	if (!data->fract_win)
		exit(1);
	data->fract_img = mlx_new_image(&data->fract_mlx, \
			WIDTH, WIDTH);
	if (!data->fract_img)
	{
		mlx_destroy_image(data->fract_mlx, data->fract_win);
		exit(1);
	}
	data->fract_addr = mlx_get_data_addr(data->fract_img,
			&data->bits_per_pexel, &data->line_lenth, &data->endian);
	if (!data->fract_addr)
		fractol_exit(data);
}

int	ft_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_valid(char *s)
{
	int	k;

	if (s == NULL || *s == '\0')
		return (0);
	k = 1;
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '.')
		return (0);
	while (*s != '\0')
	{
		if (*s == '.')
		{
			s++;
			if (k == 0 || *s == '\0')
				return (0);
			k = 0;
			s--;
		}
		else if (ft_digit(*s) == 0)
			return (0);
		s++;
	}
	return (1);
}

int	valid_input(char *str1, char *str2)
{
	if (check_valid(str1) == 0)
		return (0);
	if (check_valid(str2) == 0)
		return (0);
	return (1);
}

double	ft_divise(char *s)
{
	double		k;
	double		divise;

	divise = 0.0;
	k = 1;
	while (*s != '\0')
	{
		divise = divise * 10 + *s - 48;
		k = k * 10;
		s++;
	}
	return (divise / k);
}
