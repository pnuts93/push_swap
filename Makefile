# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 17:11:39 by pnuti             #+#    #+#              #
#    Updated: 2021/12/17 17:56:49 by pnuti            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS=		-Werror -Wall -Wextra
NAME=		push_swap
NAME_BONUS=	checker
NAME_PLAY=	ps_play
FILES=		check_ifsorted.c	fill_stack.c		get_order.c		\
			get_scheme.c		halve_n_sort.c		init_stack.c	\
			is_same_string.c	mv_push.c			mv_rotate_rev.c	\
			mv_rotate.c			mv_swap.c			ps_main.c		\
			purge_bottom.c		purge_stack.c		retrieve_b.c	\
			sort_eq_couple.c	sort_small.c		sort_stack.c	\
			stack_size.c

FILES_BONUS=checker_main.c		do_mvs.c			is_next_valid.c	\
			check_ifsorted.c	fill_stack.c		init_stack.c	\
			is_same_string.c	purge_bottom.c		exhaust_in.c	\
			purge_stack.c		stack_size.c		mute_push.c		\
			mute_rotate_rev.c	mute_rotate.c		mute_swap.c

PLAY=		play_main.c			play_do_mvs.c		is_next_valid.c	\
			check_ifsorted.c	fill_stack.c		init_stack.c	\
			is_same_string.c	purge_bottom.c		exhaust_in.c	\
			purge_stack.c		stack_size.c		mute_push.c		\
			mute_rotate_rev.c	mute_rotate.c		mute_swap.c		\
			play_print_stack.c

all : $(NAME)

$(NAME) : complib
	$(CC) $(FLAGS) $(FILES) -o $@ -L libft/ -lft
complib : download_lib
	cd libft/ && make
download_lib:
	ls libft/ || git clone https://github.com/pnuts93/libft.git
fclean:
	rm -f $(NAME) $(NAME_BONUS) $(NAME_PLAY)
	rm -fr libft
clean :
	cd libft/ && make clean
re : fclean all

bonus:
	$(CC) $(FLAGS) $(FILES_BONUS) -o $(NAME_BONUS) -L libft/ -lft
play:
	$(CC) $(FLAGS) $(PLAY) -o $(NAME_PLAY) -L libft/ -lft
