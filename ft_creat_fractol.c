/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_fractol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:50:01 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/22 13:50:02 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_put_continue(t_info *info, char *str, int color)
{
	free(str);
	str = ft_itoa(info->pow);
	mlx_string_put(info->win.p_mlx, info->win.p_win, 1, 75, color, "pow");
	mlx_string_put(info->win.p_mlx, info->win.p_win, 35, 75, color, str);
	free(str);
	str = ft_itoa(info->sw);
	mlx_string_put(info->win.p_mlx, info->win.p_win, 1, 95, color, "sw");
	mlx_string_put(info->win.p_mlx, info->win.p_win, 30, 95, color, str);
	free(str);
	str = ft_itoa(info->fract.name);
	mlx_string_put(info->win.p_mlx, info->win.p_win, 1, 115, color, "name");
	mlx_string_put(info->win.p_mlx, info->win.p_win, 40, 115, color, str);
	free(str);
}

static	void	ft_put_info(t_info *info)
{
	char	*str;
	int		color;

	if (info->col.c1 == 0xFFFFFF)
		color = 0x0;
	else
		color = 0xFFFFFF;
	str = ft_itoa(ft_get_rvalue(*info->col.color));
	mlx_string_put(info->win.p_mlx, info->win.p_win, 1, 1, color, "R");
	mlx_string_put(info->win.p_mlx, info->win.p_win, 15, 1, color, str);
	free(str);
	str = ft_itoa(ft_get_gvalue(*info->col.color));
	mlx_string_put(info->win.p_mlx, info->win.p_win, 1, 18, color, "G");
	mlx_string_put(info->win.p_mlx, info->win.p_win, 15, 18, color, str);
	free(str);
	str = ft_itoa(ft_get_bvalue(*info->col.color));
	mlx_string_put(info->win.p_mlx, info->win.p_win, 1, 35, color, "B");
	mlx_string_put(info->win.p_mlx, info->win.p_win, 15, 35, color, str);
	free(str);
	str = ft_itoa(ft_get_bvalue(info->max_it));
	mlx_string_put(info->win.p_mlx, info->win.p_win, 1, 55, color, "iter");
	mlx_string_put(info->win.p_mlx, info->win.p_win, 45, 55, color, str);
	ft_put_continue(info, str, color);
}

int				ft_creat_fractol(t_info *info)
{
	mlx_clear_window(info->win.p_mlx, info->win.p_win);
	ft_bzero(info->img.img_str, info->win.width * info->win.height * 4);
	ft_draw_img(info);
	mlx_put_image_to_window(info->win.p_mlx, info->win.p_win,
		info->win.p_img, 0, 0);
	ft_put_info(info);
	return (0);
}
