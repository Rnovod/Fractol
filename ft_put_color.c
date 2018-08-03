/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:28:56 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/26 13:28:56 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	double		ft_procent(double now, double start, double end)
{
	if (now == start)
		return (0.0);
	if (now == end)
		return (1.0);
	return ((now - start) / (end - start));
}

static void			ft_phycodelic(t_info *info, int x, int y, t_pixel p)
{
	if (p.i == 0)
		p.i = 1;
	info->img.img_str[POSITION] = (int)p.i * 2147483647 /
	(info->max_it * p.i * 0.1);
}

void				ft_put_color(t_info *info, int x, int y, t_pixel p)
{
	double	proc;

	proc = ft_procent(p.i, 0, info->max_it);
	if (info->col.phyco == 0)
	{
		if (p.i == info->max_it)
			info->img.img_str[POSITION] = info->col.c3;
		else
			info->img.img_str[POSITION] =
		ft_gradient(info->col.c1, info->col.c2, proc);
	}
	else
		ft_phycodelic(info, x, y, p);
}
