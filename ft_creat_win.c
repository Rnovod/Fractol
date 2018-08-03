/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:54:24 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/22 13:54:27 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_creat_win(t_info *info)
{
	if (info->win.width == 0)
		info->win.width = 800;
	if (info->win.height == 0)
		info->win.height = 800;
	if (!(info->win.p_mlx = mlx_init()))
		ft_error(-3);
	if (!(info->win.p_win = mlx_new_window(info->win.p_mlx,
		info->win.width, info->win.height, "rnovodra_and_fractol")))
		ft_error(-3);
	if (!(info->win.p_img = mlx_new_image(info->win.p_mlx,
		info->win.width, info->win.height)))
		ft_error(-3);
	if (!(info->img.img_str = (int*)mlx_get_data_addr(info->win.p_img,
		&info->img.bpp, &info->img.s_line, &info->img.endian)))
		ft_error(-3);
	info->img.width = info->img.s_line / (info->img.bpp / 8);
	return (0);
}
