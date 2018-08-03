/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:48:51 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/22 12:48:51 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_info	info;
	int		check;

	if (ac == 1)
		ft_error(-1);
	if (ac > 16)
		ft_error(-9);
	info.fract.name = -1;
	if ((check = ft_check_arguments(&av[1], &info)) == 1)
		info.fract.name = ft_name_fractol(av[1]);
	else if (check > 1)
		ft_new_process(&info, &av[1]);
	else
		ft_error(-1);
	ft_set_info(&info, ac);
	ft_creat_win(&info);
	ft_set_settings(&info);
	ft_creat_fractol(&info);
	ft_events(&info);
	return (0);
}
