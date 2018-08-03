/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 13:50:00 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/24 13:50:01 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int			ft_arg_size_win(t_info *info, char **av, int *i)
{
	if (!(av[*i + 1]) || !(av[*i + 2]))
		ft_error(-6);
	info->win.width = ft_atoi(av[*i + 1]);
	info->win.height = ft_atoi(av[*i + 2]);
	if (info->win.width < 200 || info->win.height < 200)
		ft_error(-7);
	if (info->win.width > 1200 || info->win.height > 1200)
		ft_error(-8);
	*i += 3;
	return (0);
}

static	int			ft_arguments(t_info *info, char **av)
{
	int		i;
	int		check;

	check = 0;
	i = 0;
	while (av[i] != NULL)
	{
		if (ft_strcmp(av[i], "-w") == 0)
		{
			ft_arg_size_win(info, av, &i);
			if (av[i] != NULL)
				ft_error(-1);
		}
		else if (ft_name_fractol(av[i]) > 0)
			check++;
		if (av[i])
			i++;
	}
	return (check);
}

int					ft_check_arguments(char **argv, t_info *info)
{
	int check;

	info->win.width = 0;
	info->win.height = 0;
	check = ft_arguments(info, argv);
	return (check);
}
