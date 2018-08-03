/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:20:50 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/24 16:20:52 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	double			ft_inter(double start, double end, double inter)
{
	return (start + ((end - start) * inter));
}

void					ft_zoom(t_info *info, double zoom, int x, int y)
{
	double		inter;
	double		mouse_re;
	double		mouse_im;

	inter = 1.0 / zoom;
	mouse_re = ft_get_re(info, x);
	mouse_im = ft_get_im(info, y);
	info->fract.min_re = ft_inter(mouse_re, info->fract.min_re, inter);
	info->fract.max_re = ft_inter(mouse_re, info->fract.max_re, inter);
	info->fract.min_im = ft_inter(mouse_im, info->fract.min_im, inter);
	info->fract.max_im = ft_inter(mouse_im, info->fract.max_im, inter);
}
