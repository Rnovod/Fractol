/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings_fract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:56:49 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/28 16:56:50 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_settings_1(t_info *info)
{
	info->fract.min_re = -2.0;
	info->fract.max_re = 0.5;
	info->fract.min_im = -1.25;
	info->fract.max_im = 1.25;
}

void	ft_settings_2(t_info *info)
{
	info->fract.min_re = -2.0;
	info->fract.max_re = 2.0;
	info->fract.min_im = -2.0;
	info->fract.max_im = 2.0;
}
