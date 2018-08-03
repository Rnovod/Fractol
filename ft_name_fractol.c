/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_name_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:39:36 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/22 13:39:40 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int			ft_name_continue(char *av)
{
	if (!ft_strcmp(av, "buffalo") ||
		!ft_strcmp(av, "Buffalo") || !ft_strcmp(av, "-b"))
		return (7);
	else if (!ft_strcmp(av, "celtic heart") ||
		!ft_strcmp(av, "Celtic heart") || !ft_strcmp(av, "-ch"))
		return (8);
	else if (!ft_strcmp(av, "burnship per") ||
		!ft_strcmp(av, "Burnship per") || !ft_strcmp(av, "-bsp"))
		return (9);
	else if (!(ft_strcmp(av, "perpendicular")) ||
		!ft_strcmp(av, "Perpendicular") || !ft_strcmp(av, "-p"))
		return (10);
	else if (!(ft_strcmp(av, "grid")) ||
		!ft_strcmp(av, "Grid") || !ft_strcmp(av, "-g"))
		return (11);
	else if (!(ft_strcmp(av, "snowflake")) ||
		!ft_strcmp(av, "Snowflake") || !ft_strcmp(av, "-s"))
		return (12);
	ft_error(-2);
	return (-1);
}

int					ft_name_fractol(char *av)
{
	if (!ft_strcmp(av, "mandelbrot") ||
		!ft_strcmp(av, "Mandelbrot") || !ft_strcmp(av, "-m"))
		return (1);
	else if (!ft_strcmp(av, "julia") ||
		!ft_strcmp(av, "Julia") || !ft_strcmp(av, "-j"))
		return (2);
	else if (!ft_strcmp(av, "mandelbar") ||
		!ft_strcmp(av, "Mandelbar") || !ft_strcmp(av, "-mb"))
		return (3);
	else if (!ft_strcmp(av, "heart") ||
		!ft_strcmp(av, "Heart") || !ft_strcmp(av, "-h"))
		return (4);
	else if (!(ft_strcmp(av, "celtic")) ||
		!ft_strcmp(av, "Celtic") || !ft_strcmp(av, "-c"))
		return (5);
	else if (!ft_strcmp(av, "burnship") ||
		!ft_strcmp(av, "Burnship") || !ft_strcmp(av, "-bs"))
		return (6);
	else
		return (ft_name_continue(av));
}
