/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:06:11 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/02 18:06:12 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_mouse_unpress(int button, int x, int y, t_info *info)
{
	(void)x;
	(void)y;
	if (button == 1)
		info->press = 0;
	return (0);
}

static	void		ft_move(t_info *info, int x, int y)
{
	long double inter_x;
	long double inter_y;

	inter_x = info->mouse.press_x - ft_get_re(info, x);
	inter_y = info->mouse.press_y - ft_get_im(info, y);
	info->fract.min_im += inter_y;
	info->fract.max_im += inter_y;
	info->fract.min_re += inter_x;
	info->fract.max_re += inter_x;
}

int					ft_mouse(int button, int x, int y, t_info *info)
{
	if (button == 4)
	{
		ft_zoom(info, ZOOM, x, y);
		ft_creat_fractol(info);
	}
	if (button == 5)
	{
		ft_zoom(info, 1 / ZOOM, x, y);
		ft_creat_fractol(info);
	}
	if (button == 1 && x > 0 && y > 0 &&
		x < info->win.width && y < info->win.width)
	{
		info->mouse.press_x = ft_get_re(info, x);
		info->mouse.press_y = ft_get_im(info, y);
		info->press = 1;
	}
	return (0);
}

int					ft_mouse_move(int x, int y, t_info *info)
{
	if (info->mouse.stop == 0 && (info->fract.name == 2 ||
		(info->fract.name >= 11 && info->fract.name <= 15)
		|| info->move == 1) &&
		x > 0 && y > 0 && x < info->win.width && y < info->win.width &&
		info->press == 0)
	{
		info->mouse.x = ft_get_re(info, x);
		info->mouse.y = ft_get_im(info, y);
		ft_creat_fractol(info);
	}
	if (info->press == 1)
	{
		ft_move(info, x, y);
		ft_creat_fractol(info);
	}
	return (0);
}
