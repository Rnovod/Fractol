# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/10 14:27:39 by rnovodra          #+#    #+#              #
#    Updated: 2018/02/10 14:28:21 by rnovodra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = libft.a

OBJ = main.o \
		ft_name_fractol.o \
		ft_error.o \
		ft_creat_fractol.o \
		ft_creat_win.o \
		ft_events.o \
		ft_gradient.o \
		ft_new_process.o \
		ft_check_arguments.o \
		ft_change_color.o \
		ft_zoom.o \
		ft_put_color.o \
		ft_settings_fract.o \
		ft_set_settings.o \
		ft_take_re_im.o \
		ft_exit.o \
		ft_choose_fract.o \
		ft_calc_pow.o \
		ft_draw_img.o \
		ft_keys.o \
		ft_fractals_1.o \
		ft_fractals_2.o \
		ft_own_fractal.o \
		ft_julia.o \
		ft_mouses.o \
		ft_set_info.o

FLAGS = -Wall -Werror -Wextra

GRAPH = -framework OpenGL -framework AppKit -lmlx 

CC = gcc

all : $(LIBFT) $(NAME)

$(LIBFT) :
	make all -C libft/

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(GRAPH) $(OBJ) libft/$(LIBFT)

%.o : %.c
	$(CC) -c -o $@ $< $(FLAGS)

clean :
	rm -rf $(OBJ)
	make clean -C libft/

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft/

re : fclean all

.PHONY: all fclean clean re 
