/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:06:39 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/23 18:06:40 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_new_process(t_info *info, char **av)
{
	pid_t			child;

	if ((child = fork()) == 0)
	{
		if (execv("fractol", av) < 0)
			ft_error(errno);
	}
	else if (child > 0)
		info->fract.name = ft_name_fractol(av[0]);
	else
		ft_error(errno);
	return (0);
}
