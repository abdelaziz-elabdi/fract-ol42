/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:40:47 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/06/10 13:48:09 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((*s1 || *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_atoi(const char *str)
{
	int		d;
	int		mr;
	size_t	ben;

	d = 0;
	mr = 1;
	ben = 0;
	while (str[d] == 32 || (str[d] >= 9 && str[d] <= 13))
		d++;
	if (str[d] == '-' || str[d] == '+')
	{
		if (str[d] == '-')
			mr = -mr;
		d++;
	}
	while (str[d] >= '0' && str[d] <= '9')
	{
		ben = ben * 10 + str[d] - 48;
		if (ben >= 9223372036854775807 && mr == 1)
			return (-1);
		else if (ben > 9223372036854775807 && mr == -1)
			return (0);
		d++;
	}
	return (mr * ben);
}

int	ft_color(int iter, int max_iter)
{
	int	color_red;
	int	color_blue;
	int	color_green;

	if (iter == max_iter)
		return (0x000000);
	else
	{
		color_red = (iter * 8) % 255;
		color_green = (iter * 6) % 255;
		color_blue = (iter * 10) % 255;
		return ((color_red << 16) | (color_green << 8) | color_blue);
	}
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->fract_addr + (y * data->line_lenth + \
			x * (data->bits_per_pexel / 8));
	*(unsigned int *)dst = color;
}
