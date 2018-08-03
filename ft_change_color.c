/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 14:32:54 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/24 14:32:55 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		ft_change_red(int *color, int key)
{
	int		r;
	int		g;
	int		b;

	r = ft_get_rvalue(*color);
	g = ft_get_gvalue(*color);
	b = ft_get_bvalue(*color);
	if (key == 86 && r < 255)
		r++;
	else if (key == 83 && r > 0)
		r--;
	return (r << 16 | g << 8 | b);
}

static	int		ft_change_green(int *color, int key)
{
	int		r;
	int		g;
	int		b;

	r = ft_get_rvalue(*color);
	g = ft_get_gvalue(*color);
	b = ft_get_bvalue(*color);
	if (key == 87 && g < 255)
		g++;
	else if (key == 84 && g > 0)
		g--;
	return (r << 16 | g << 8 | b);
}

static	int		ft_change_blue(int *color, int key)
{
	int		r;
	int		g;
	int		b;

	r = ft_get_rvalue(*color);
	g = ft_get_gvalue(*color);
	b = ft_get_bvalue(*color);
	if (key == 88 && b < 255)
		b++;
	else if (key == 85 && b > 0)
		b--;
	return (r << 16 | g << 8 | b);
}

static	void	ft_change_c2(t_col *col)
{
	if (col->change == 0)
		*col->color = 0xFF0000;
	else if (col->change == 1)
		*col->color = 0x00FF00;
	else if (col->change == 2)
		*col->color = 0x0000FF;
	else if (col->change == 3)
		*col->color = 0x45dcf4;
	else if (col->change == 4)
		*col->color = 0x00b234;
	else if (col->change == 5)
		*col->color = 0xff60ff;
	else if (col->change == 6)
		*col->color = 0xffd700;
	else if (col->change == 7)
		*col->color = 0xa020f0;
	else if (col->change == 8)
		*col->color = 0xFFFFFF;
	else if (col->change == 9)
		*col->color = 0x0;
}

void			ft_change_color(t_info *info, int key)
{
	if (info->sw == 0)
		info->col.color = &info->col.c2;
	else if (info->sw == 1)
		info->col.color = &info->col.c1;
	else
		info->col.color = &info->col.c3;
	if (key == 78 && info->col.change > 0)
		info->col.change--;
	if (key == 69 && info->col.change < 9)
		info->col.change++;
	if (key == 83 || key == 86)
		*info->col.color = ft_change_red(info->col.color, key);
	else if (key == 84 || key == 87)
		*info->col.color = ft_change_green(info->col.color, key);
	else if (key == 85 || key == 88)
		*info->col.color = ft_change_blue(info->col.color, key);
	else
		ft_change_c2(&info->col);
}
