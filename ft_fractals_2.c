/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractals_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:25:09 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/02 14:25:10 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_heart(t_info *info, double re, double im)
{
	int			i;
	double		x_y;
	double		two_x_y;
	double		x_i;
	double		y_i;

	x_i = info->move == 0 ? re : re + info->mouse.x;
	y_i = info->move == 0 ? im : im + info->mouse.y;
	i = 0;
	while (i < info->max_it)
	{
		x_y = ft_calc_x_y(info->pow, fabs(re), im);
		two_x_y = ft_calc_two_x_y(info->pow, fabs(re), im);
		re = x_y + x_i;
		im = two_x_y + y_i;
		if ((re * re + im * im) > 16)
			break ;
		i++;
	}
	return (i);
}

int			ft_mandelbar(t_info *info, double re, double im)
{
	int			i;
	double		x_y;
	double		two_x_y;
	double		x_i;
	double		y_i;

	x_i = info->move == 0 ? re : re + info->mouse.x;
	y_i = info->move == 0 ? im : im + info->mouse.y;
	i = 0;
	while (i < info->max_it)
	{
		x_y = ft_calc_x_y(info->pow, re, im);
		two_x_y = -ft_calc_two_x_y(info->pow, re, im);
		re = x_y + x_i;
		im = two_x_y + y_i;
		if ((re * re + im * im) > 16)
			break ;
		i++;
	}
	return (i);
}

int			ft_mandelbrot(t_info *info, double re, double im)
{
	int			i;
	double		x_y;
	double		two_x_y;
	double		x_i;
	double		y_i;

	x_i = info->move == 0 ? re : re + info->mouse.x;
	y_i = info->move == 0 ? im : im + info->mouse.y;
	i = 0;
	while (i < info->max_it)
	{
		x_y = ft_calc_x_y(info->pow, re, im);
		two_x_y = ft_calc_two_x_y(info->pow, re, im);
		re = x_y + x_i;
		im = two_x_y + y_i;
		if ((re * re + im * im) > 16)
			break ;
		i++;
	}
	return (i);
}

int			ft_perpendicular(t_info *info, double re, double im)
{
	int			i;
	double		x_y;
	double		two_x_y;
	double		x_i;
	double		y_i;

	x_i = info->move == 0 ? re : re + info->mouse.x;
	y_i = info->move == 0 ? im : im + info->mouse.y;
	i = 0;
	while (i < info->max_it)
	{
		x_y = ft_calc_x_y(info->pow, re, im);
		two_x_y = -ft_calc_two_x_y(info->pow, fabs(re), im);
		re = x_y + x_i;
		im = two_x_y + y_i;
		if ((re * re + im * im) > 16)
			break ;
		i++;
	}
	return (i);
}
