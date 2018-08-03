/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:45:42 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/22 13:45:43 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_error_c(int error)
{
	if (error == -5)
		ft_putendl("No child process is created");
	else if (error == -6)
		ft_putendl("Error: didn't put correct data about the window");
	else if (error == -7)
		ft_putendl("Error: "
		"Width and height must be greater or equal then 200");
	else if (error == -8)
		ft_putendl("Error: "
		"The width must be less then 1200, the height - less 1200");
	else if (error == -9)
	{
		ft_putendl("Error: "
		"To many arguments. Try less then 15");
		ft_error(-1);
	}
	else if (error > 0)
	{
		ft_putstr("Error: ");
		ft_putendl(strerror(error));
	}
}

void			ft_error(int error)
{
	if (error == -1)
		ft_putendl("Usage : fractol <name_fractol> ... -w <width> <height>\n"
			"Names of fractol's are:\n"
			"Mandelbrot(-m)\nJulia(-j)\nMandelbar(-mb)\nHeart(-h)\nCeltic(-c)\n"
			"Burnship(-bs)\nBuffalo(-b)\nCeltic heart(-ch)\nBurnship per(-bsp)"
			"\nPerpendicular(-p)\nSnowflake(-s)\nGrid(-g)");
	else if (error == -2)
		ft_putendl("Error: incorrect fractol's name\n"
			"Names of fractol's are:\n"
			"Mandelbrot(-m)\nJulia(-j)\nMandelbar(-mb)\nHeart(-h)\nCeltic(-c)\n"
			"Burnship(-bs)\nBuffalo(-b)\nCeltic heart(-ch)\nBurnship per(-bsp)"
			"\nPerpendicular(-p)\nSnowflake(-s)\nGrid(-g)");
	else if (error == -3)
		ft_putendl("Something bad happened with mlx");
	else
		ft_error_c(error);
	ft_exit();
}
