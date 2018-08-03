/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:10:44 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/22 14:10:44 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_events(t_info *info)
{
	mlx_hook(info->win.p_win, 5, 5, ft_mouse_unpress, info);
	mlx_hook(info->win.p_win, 6, 1L << 6, ft_mouse_move, info);
	mlx_hook(info->win.p_win, 2, 5, ft_keys, info);
	mlx_hook(info->win.p_win, 17, 1L << 17, ft_exit, NULL);
	mlx_mouse_hook(info->win.p_win, ft_mouse, info);
	mlx_loop(info->win.p_mlx);
	return (0);
}
