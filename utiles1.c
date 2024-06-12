/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:47:31 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/06/10 17:06:37 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atoi_to_double(char *s)
{
	double	pre_part;
	double	deu_part;
	int		sign;

	sign = 1;
	deu_part = 0.0;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	pre_part = (double)ft_atoi(s);
	while (*s != '\0' && *s != '.')
		s++;
	if (*s == '.')
	{
		s++;
		deu_part = ft_divise(s);
	}
	return (sign * (pre_part + deu_part));
}

void	check_julia(char **av, int ac, t_data *data)
{
	if (ac == 4)
	{
		if (valid_input(av[2], av[3]) == 1)
		{
			data->j_x = ft_atoi_to_double(av[2]);
			data->j_y = ft_atoi_to_double(av[3]);
			data->parsing = 2;
			if ((data->j_x <= -2 || data->j_x >= 2) || \
					(data->j_y <= -2 || data->j_y >= 2))
			{
				write(1, "Invalid arguments \"julia\"\n", 27);
				exit(1);
			}
		}
		else
		{
			write(1, "Invalid arguments \"julia\"\n", 27);
			exit(1);
		}
	}
}

int	fractol_parssing(char **av, int ac, t_data *data)
{
	if (ac < 2 || ac > 4)
	{
		write(1, "Fractols Available \"mandelbrot\",  \"julia\"\n", 43);
		return (0);
	}
	else if (ft_strncmp(av[1], "mandelbrot") == 0 && ac == 2)
		data->parsing = 1;
	else if (ft_strncmp(av[1], "julia") == 0 && ac == 4)
		check_julia(av, ac, data);
	else
	{
		write(1, "Invalid fractols \"mandelbrot\",  \"julia\"\n", 40);
		return (0);
	}
	return (1);
}
