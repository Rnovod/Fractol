/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_fract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:14:20 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/01 12:14:21 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_choose_own(t_info *info, int key)
{
	if (key == 12)
		info->fract.name = 11;
	if (key == 13)
		info->fract.name = 12;
}

static	void	ft_choose_name(t_info *info, int key)
{
	if (info->move == 1)
		info->move++;
	if (key == 18 && info->fract.name != 1)
		info->fract.name = 1;
	else if (key == 19)
		info->fract.name = 2;
	else if (key == 20 && info->fract.name != 3)
		info->fract.name = 3;
	else if (key == 21 && info->fract.name != 4)
		info->fract.name = 4;
	else if (key == 23 && info->fract.name != 5)
		info->fract.name = 5;
	else if (key == 22 && info->fract.name != 6)
		info->fract.name = 6;
	else if (key == 26 && info->fract.name != 7)
		info->fract.name = 7;
	else if (key == 28 && info->fract.name != 8)
		info->fract.name = 8;
	else if (key == 25 && info->fract.name != 9)
		info->fract.name = 9;
	else if (key == 29 && info->fract.name != 10)
		info->fract.name = 10;
	else
		info->move++;
}

void			ft_choose_fract(t_info *info, int key)
{
	if (key >= 12 && key <= 16)
		ft_choose_own(info, key);
	else
		ft_choose_name(info, key);
	if (info->move > 1)
		info->move = 0;
	ft_set_settings(info);
	info->mouse.stop = 0;
}
