/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_pow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:55:00 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/01 16:55:01 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double			ft_calc_two_x_y(int pow, double re, double im)
{
	if (pow == 1)
		return (re * im);
	else if (pow == 2)
		return (pow * re * im);
	else if (pow == 3)
		return ((SQR(re) * pow - (SQR(im))) * im);
	else if (pow == 4)
		return (4 * re * im * (SQR(re) - SQR(im)));
	else if (pow == 5)
		return (im * (5 * DSQR(re) - 10 * SQR(re) * SQR(im) + DSQR(im)));
	return (0);
}

double			ft_calc_x_y(int pow, double re, double im)
{
	if (pow == 1)
		return (re - im);
	else if (pow == 2)
		return (SQR(re) - SQR(im));
	else if (pow == 3)
		return ((SQR(re) - (SQR(im) * pow)) * re);
	else if (pow == 4)
		return (DSQR(re) + DSQR(im) - 6 * SQR(re) * SQR(im));
	else if (pow == 5)
		return (re * (DSQR(re) - 10 * SQR(re) * SQR(im) + 5 * DSQR(im)));
	return (0);
}
