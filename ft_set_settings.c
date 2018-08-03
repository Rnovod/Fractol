/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:11:37 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/28 19:11:38 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_settings(t_info *info)
{
	if (info->fract.name == 1 && info->move == 0 && info->pow == 2)
		ft_settings_1(info);
	else
		ft_settings_2(info);
}
