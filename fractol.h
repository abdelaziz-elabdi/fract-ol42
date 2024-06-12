/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:15:28 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/06/11 10:32:39 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>

# define WIDTH 700
# define HEIGHT 700

typedef struct s_pixel
{
	double	re;
	double	im;
}	t_pixel;
typedef struct s_data
{
	char	*fract_addr;
	void	*fract_mlx;
	void	*fract_win;
	void	*fract_img;
	int		bits_per_pexel;
	int		endian;
	int		line_lenth;
	int		parsing;
	int		max;
	int		x;
	int		y;
	double	re;
	double	im;
	int		iteration;
	double	j_x;
	double	j_y;
	double	zoom;
	t_pixel	pxl;
	t_pixel	c;
}	t_data;

int		fractol_parssing(char **av, int ac, t_data *data);
int		ft_strncmp(const char *s1, const char *s2);
int		init_fractol(t_data *data);
void	mlx_win(t_data *data);
int		fractol_exit(t_data *data);
int		calc_fractol(t_data *data);
int		fractol_key(int key, int x, int y, t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
void	ft_handle_hook(t_data *data);
void	check_julia(char **av, int ac, t_data *data);
double	ft_atoi_to_double(char *s);
int		ft_atoi(const char *str);
int		ft_color(int iter, int max_iter);
int		calc_julia(t_data *data);
int		calc_mandelbrot(t_data *data);
double	ft_scale_y(t_data *data, int k);
double	ft_scale_x(t_data *data, int k);
int		calc_iter(t_data *data, t_pixel z, t_pixel c);
int		valid_input(char *str1, char *str2);
double	ft_divise(char *s);

#endif