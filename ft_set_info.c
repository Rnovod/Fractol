/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:12:52 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/04 16:13:00 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_set_color(t_info *info, int ac)
{
	if (ac == 2)
		info->col.c2 = 0xFF0000;
	else if (ac == 3)
		info->col.c2 = 0xFF00;
	else if (ac == 4)
		info->col.c2 = 0xFF;
	else if (ac >= 5 && ac <= 7)
	{
		if (ac == 5)
			info->col.c2 = 0xFF0000;
		if (ac == 6)
			info->col.c2 = 0xFF00;
		if (ac == 7)
			info->col.c2 = 0xFF;
		info->col.c3 = info->col.c2;
	}
	else
	{
		info->col.c2 = 0xFFFFFF / ac;
		info->col.c3 = info->col.c2;
	}
}

void			ft_set_info(t_info *info, int ac)
{
	info->col.c1 = 0x0;
	info->col.c3 = 0x0;
	if (info->win.width != 0)
		ac = ac - 3;
	ft_set_color(info, ac);
	info->col.color = &info->col.c2;
	info->col.change = 0;
	info->press = 0;
	info->mouse.stop = 0;
	info->sw = 0;
	info->max_it = 40;
	info->pow = 2;
	info->col.phyco = 0;
}
