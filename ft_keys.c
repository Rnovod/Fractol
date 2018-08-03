/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:17:44 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/02 14:17:44 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_key_move(int key, t_info *info)
{
	if (key == 126)
	{
		info->fract.min_im += DIF_IM * 0.01;
		info->fract.max_im += DIF_IM * 0.01;
	}
	else if (key == 125)
	{
		info->fract.min_im -= DIF_IM * 0.01;
		info->fract.max_im -= DIF_IM * 0.01;
	}
	else if (key == 123)
	{
		info->fract.min_re += DIF_RE * 0.01;
		info->fract.max_re += DIF_RE * 0.01;
	}
	else if (key == 124)
	{
		info->fract.min_re -= DIF_RE * 0.01;
		info->fract.max_re -= DIF_RE * 0.01;
	}
}

static	void	ft_key_1(int key, t_info *info)
{
	if (key == 116)
		info->max_it++;
	else if (key == 121 && info->max_it > 1)
		info->max_it--;
	else if (key == 36)
		ft_set_settings(info);
	else if (key == 49)
	{
		if (++info->mouse.stop > 1)
			info->mouse.stop = 0;
	}
	else if (key == 27 && info->pow > 1)
	{
		info->pow--;
		ft_set_settings(info);
	}
	else if (key == 24 && info->pow < 5)
	{
		info->pow++;
		ft_set_settings(info);
	}
	else
		ft_key_move(key, info);
}

int				ft_keys(int key, t_info *info)
{
	if (key == 53)
		ft_exit();
	else if (key == 69 || key == 78 || (key >= 83 && key <= 88))
		ft_change_color(info, key);
	else if (key == 82)
	{
		if (++info->sw > 2)
			info->sw = 0;
	}
	else if ((key >= 18 && key <= 23) || key == 25 ||
		key == 26 || key == 28 || key == 29 ||
		(key >= 12 && key <= 13))
		ft_choose_fract(info, key);
	else if (key == 10)
	{
		if (++info->col.phyco > 1)
			info->col.phyco = 0;
	}
	else
		ft_key_1(key, info);
	ft_creat_fractol(info);
	return (0);
}
