/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:18:46 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/01 19:18:47 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int			ft_algo_continue(t_info *info, t_pixel *p)
{
	if (info->fract.name == 11)
		return (ft_grid(info, p->re, p->im));
	else if (info->fract.name == 12)
		return (ft_snowflake(info, p->re, p->im));
	else if (info->fract.name == 13)
		return (ft_mandelbar(info, p->re, p->im));
	else if (info->fract.name == 14)
		return (ft_heart(info, p->re, p->im));
	return (1);
}

static	int			ft_choose_algo_fract(t_info *info, int x, int y, t_pixel *p)
{
	p->re = ft_get_re(info, x);
	p->im = ft_get_im(info, y);
	if (info->fract.name == 1)
		return (ft_mandelbrot(info, p->re, p->im));
	else if (info->fract.name == 2)
		return (ft_julia(info, p->re, p->im));
	else if (info->fract.name == 3)
		return (ft_mandelbar(info, p->re, p->im));
	else if (info->fract.name == 4)
		return (ft_heart(info, p->re, p->im));
	else if (info->fract.name == 5)
		return (ft_celtic(info, p->re, p->im));
	else if (info->fract.name == 6)
		return (ft_burning_ship(info, p->re, p->im));
	else if (info->fract.name == 7)
		return (ft_buffalo(info, p->re, p->im));
	else if (info->fract.name == 8)
		return (ft_celtic_heart(info, p->re, p->im));
	else if (info->fract.name == 9)
		return (ft_burnship_per(info, p->re, p->im));
	else if (info->fract.name == 10)
		return (ft_perpendicular(info, p->re, p->im));
	else
		return (ft_algo_continue(info, p));
	return (1);
}

static	void		*ft_draw(void *param)
{
	int				part;
	t_thread		*t;
	int				x;
	int				y;
	t_pixel			p;

	t = (t_thread*)param;
	y = t->info->win.height / THREADS * t->thread_id;
	part = t->info->win.height / THREADS * (t->thread_id + 1);
	while (y < part)
	{
		x = 0;
		while (x < t->info->win.width)
		{
			p.i = ft_choose_algo_fract(t->info, x, y, &p);
			ft_put_color(t->info, x, y, p);
			x++;
		}
		y++;
	}
	return (0);
}

int					ft_draw_img(t_info *info)
{
	t_thread	t[THREADS];
	int			id;
	int			error;

	id = 0;
	while (id < THREADS)
	{
		t[id].info = info;
		t[id].thread_id = id;
		if (pthread_attr_init(&t[id].attr) != 0)
			ft_error(ENOMEM);
		if ((error = pthread_create(&t[id].tid,
			&t[id].attr, ft_draw, &t[id])) != 0)
			ft_error(error);
		id++;
	}
	id = 0;
	while (id < THREADS)
	{
		if ((error = pthread_join(t[id].tid, NULL)) != 0)
			ft_error(error);
		id++;
	}
	return (0);
}
