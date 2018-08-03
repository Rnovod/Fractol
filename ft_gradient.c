/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gradient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:23:32 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/12 18:23:33 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_get_rvalue(int color)
{
	return (color >> 16 & 0xFF);
}

int					ft_get_gvalue(int color)
{
	return (color >> 8 & 0xFF);
}

int					ft_get_bvalue(int color)
{
	return (color & 0xFF);
}

static	int			ft_color(int first, int second, double procent)
{
	return ((first + (second - first) * procent));
}

int					ft_gradient(int first, int second, double procent)
{
	int r;
	int g;
	int b;

	if (first == second)
		return ((int)first);
	r = ft_color(ft_get_rvalue((int)first),
		ft_get_rvalue((int)second), procent);
	g = ft_color(ft_get_gvalue((int)first),
		ft_get_gvalue((int)second), procent);
	b = ft_color(ft_get_bvalue((int)first),
		ft_get_bvalue((int)second), procent);
	return (r << 16 | g << 8 | b);
}
