/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_re_im.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:14:31 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/28 19:14:32 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		ft_get_re(t_info *info, double x)
{
	double	p_re;
	double	res;

	p_re = (info->fract.max_re - info->fract.min_re) / info->win.width;
	res = x * p_re + info->fract.min_re;
	return (res);
}

double		ft_get_im(t_info *info, double y)
{
	double	p_im;
	double	res;

	p_im = (info->fract.max_im - info->fract.min_im) / info->win.height;
	res = y * p_im + info->fract.min_im;
	return (res);
}
