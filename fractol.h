/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:35:47 by rnovodra          #+#    #+#             */
/*   Updated: 2018/02/22 13:35:48 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <errno.h>
# include <sys/types.h>
# include <pthread.h>
# define POSITION info->img.width * y + x
# define THREADS 8
# define SQR(x) x * x
# define DSQR(x) x * x * x * x
# define DIF_IM (info->fract.max_im - info->fract.min_im)
# define DIF_RE (info->fract.max_re - info->fract.min_re)
# define ZOOM 1.05

typedef	struct		s_win
{
	void			*p_mlx;
	void			*p_win;
	void			*p_img;
	int				width;
	int				height;
}					t_win;

typedef	struct		s_fract
{
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	int				name;
}					t_fract;

typedef	struct		s_mouse
{
	double			x;
	double			y;
	int				stop;
	double			press_x;
	double			press_y;
}					t_mouse;

typedef	struct		s_img
{
	int				width;
	int				bpp;
	int				s_line;
	int				endian;
	int				*img_str;
}					t_img;

typedef	struct		s_col
{
	int				phyco;
	int				c1;
	int				c2;
	int				c3;
	int				*color;
	int				change;
}					t_col;

typedef	struct		s_pixel
{
	double			re;
	double			im;
	int				i;
}					t_pixel;

typedef	struct		s_info
{
	t_win			win;
	t_img			img;
	t_fract			fract;
	t_mouse			mouse;
	t_col			col;
	int				sw;
	int				max_it;
	int				pow;
	int				move;
	int				press;
}					t_info;

typedef	struct		s_thread
{
	int				thread_id;
	pthread_t		tid;
	pthread_attr_t	attr;
	t_info			*info;
}					t_thread;

int					ft_events(t_info *info);
int					ft_name_fractol(char *av);
int					ft_creat_win(t_info *info);
int					ft_creat_fractol(t_info *info);
void				ft_choose_fract(t_info *info, int key);
int					ft_gradient(int f_color, int s_color, double procent);
int					ft_check_arguments(char **argv, t_info *info);
void				ft_change_color(t_info *info, int key);
void				ft_put_color(t_info *info, int x, int y, t_pixel p);

int					ft_general_process(t_info *info, char *av);
int					ft_new_process(t_info *info, char **av);
int					ft_child_process(t_info *info, char *av);

void				ft_set_info(t_info *info, int ac);
void				ft_set_settings(t_info *info);
void				ft_settings_1(t_info *info);
void				ft_settings_2(t_info *info);

int					ft_draw_img(t_info *info);

int					ft_mandelbrot(t_info *info, double re, double im);
int					ft_mandelbar(t_info *info, double re, double im);
int					ft_julia(t_info *info, double re, double im);
int					ft_heart(t_info *info, double re, double im);
int					ft_celtic(t_info *info, double re, double im);
int					ft_burning_ship(t_info *info, double re, double im);
int					ft_buffalo(t_info *info, double re, double im);
int					ft_celtic_heart(t_info *info, double re, double im);
int					ft_burnship_per(t_info *info, double re, double im);
int					ft_perpendicular(t_info *info, double re, double im);
int					ft_grid(t_info *info, double re, double im);
int					ft_snowflake(t_info *info, double re, double im);

int					ft_move_burnship(t_info *info, double re, double im);
int					ft_move_buffalo(t_info *info, double re, double im);
int					ft_move_mandelbrot(t_info *info, double re, double im);
int					ft_move_celtic(t_info *info, double re, double im);

double				ft_calc_two_x_y(int pow, double re, double im);
double				ft_calc_x_y(int pow, double re, double im);
double				ft_get_im(t_info *info, double y);
double				ft_get_re(t_info *info, double x);

void				ft_zoom(t_info *info, double zoom, int x, int y);
int					ft_mouse_move(int x, int y, t_info *info);
int					ft_keys(int key, t_info *info);
int					ft_mouse(int button, int x, int y, t_info *info);
int					ft_mouse_down(int button, int x, int y, t_info *info);
int					ft_mouse_up(int button, int x, int y, t_info *info);
int					ft_mouse_unpress(int button, int x, int y, t_info *info);

int					ft_get_rvalue(int color);
int					ft_get_gvalue(int color);
int					ft_get_bvalue(int color);

void				ft_error(int error);
int					ft_exit(void);

#endif
