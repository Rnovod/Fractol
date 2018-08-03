/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_own_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:28:26 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/05 12:28:27 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_grid(t_info *info, double re, double im)
{
	int		i;
	double	x_y;
	double	two_x_y;
	double	x_i;
	double	y_i;

	re = sin(re);
	im = cos(im);
	x_i = info->mouse.x;
	y_i = info->mouse.y;
	i = 0;
	while (i < info->max_it)
	{
		x_y = fabs(ft_calc_x_y(info->pow, re, im));
		two_x_y = fabs(ft_calc_two_x_y(info->pow, re, im));
		re = fabs(x_y + x_i);
		im = fabs(two_x_y + y_i);
		if ((re * re + im * im) > 16)
			break ;
		i++;
	}
	return (i);
}

int			ft_snowflake(t_info *info, double re, double im)
{
	int		i;
	double	x_y;
	double	two_x_y;
	double	x_i;
	double	y_i;

	x_i = sin(info->mouse.x);
	y_i = cos(info->mouse.y);
	i = 0;
	while (i < info->max_it)
	{
		x_y = ft_calc_x_y(info->pow, re, im);
		two_x_y = fabs(ft_calc_two_x_y(info->pow, re, im));
		re = fabs(x_y) + x_i;
		im = fabs(two_x_y) + y_i;
		if ((re * re + im * im) > 16)
			break ;
		i++;
	}
	return (i);
}
