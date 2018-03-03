##
## Makefile for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
##
## Made by Enguerrand Arminjon
## Login   <armin.pc@epitech.net>
##
## Started on  Thu May 11 12:40:59 2017 Enguerrand Arminjon
## Last update Sun May 28 09:22:29 2017 Enguerrand Arminjon
##

SRCS 	=	Useful/my_putstr.c			\
		Useful/my_putchar.c			\
		Useful/my_put_nbr.c			\
		Useful/my_getnbr.c			\
		Useful/my_revstr.c			\
		Useful/printf/my_printf.c		\
		Useful/printf/my_printf2.c		\
		Useful/printf/my_printf3.c		\
		Useful/printf/my_printf4.c		\
		Useful/printf/my_put_short.c		\
		Useful/printf/my_put_long.c		\
		Useful/fprintf/my_fprintf.c		\
		Useful/fprintf/my_fprintf2.c		\
		Useful/fprintf/my_fprintf3.c		\
		Useful/fprintf/my_fprintf4.c		\
		Useful/fprintf/my_fput_short.c		\
		Useful/fprintf/my_fput_long.c		\
		Useful/fprintf/my_fputchar.c		\
		Useful/fprintf/my_fputstr.c		\
		Useful/fprintf/my_fput_nbr.c		\
		Useful/print_tab.c			\
		Useful/my_strcat.c			\
		Useful/my_strcat_malloc.c		\
		Useful/my_strcmp.c			\
		Useful/my_strcmp_2.c			\
		Useful/my_str_isalpha.c			\
		Useful/my_str_isnum.c			\
		Useful/free_my_tab.c			\
		Useful/free_tab.c			\
		Useful/my_realloc.c			\
		Useful/get_next_line.c			\
		Useful/my_puterror.c			\
		Useful/my_strncmp.c			\
		Srcs/bin_path.c				\
		Srcs/free_list.c			\
		Srcs/my_put_in_list.c			\
		Srcs/my_put_in_list_next.c		\
		Srcs/clone_tab.c			\
		Srcs/my_fork.c				\
		Srcs/my_env.c				\
		Srcs/my_cd.c				\
		Srcs/my_main_cd.c			\
		Srcs/my_exit.c				\
		Srcs/my_parsing.c			\
		Srcs/debug_shell.c			\
		Srcs/my_exec.c				\
		Srcs/my_redirection.c			\
		Srcs/my_redir.c				\
		Srcs/my_pipe.c				\
		Srcs/my_pipe_next.c			\
		Srcs/display_tab_in_list.c		\
		Srcs/loop_shell.c			\
		Srcs/my_builtin.c			\
		Srcs/my_echo.c				\
		Srcs/my_nb_argu.c			\
		Srcs/my_display_error.c			\
		Srcs/my_item_tab.c			\
		Srcs/my_error_str.c			\
		Srcs/edit_tab.c				\
		Srcs/my_star.c				\
		Srcs/my_new_row_env.c			\
		Srcs/print_t_tab.c			\
		Srcs/my_dollard.c			\
		Srcs/count_redir.c			\
		Srcs/can_i_continu.c			\
		Srcs/my_rev_strcmp.c			\
		Srcs/my_inibitor.c			\
		Srcs/my_clear_str.c			\
		Srcs/ambi_output.c			\
		Srcs/useful_history.c			\
		Srcs/modify_history.c			\
		Srcs/history.c				\
		Srcs/delete_false_row.c			\
		Srcs/my_count_pipes.c			\
		Srcs/fix_path.c				\
		Srcs/center_of_control.c		\
		Srcs/tools_for_put_in_list.c		\
		Srcs/my_alias.c				\
		Srcs/add_an_alias.c			\
		Srcs/str_to_tab.c			\
		Srcs/my_42shrc.c			\
		Srcs/edit_my_shell.c			\
		Srcs/my_prompt.c			\
		Srcs/print_env.c			\
		Srcs/stock_bin_path.c			\
		Srcs/my_where.c				\
		Srcs/my_which.c				\
		Srcs/check_builts.c			\
		Srcs/my_if.c				\
		Srcs/my_tab_to_str.c			\
		Srcs/my_repeat.c			\
		Srcs/my_foreach.c			\
		Srcs/build_a_tab.c			\
		Srcs/my_foreach_next.c			\
		Srcs/my_set.c				\
		Srcs/my_copy_t_my_tab.c			\
		Srcs/my_getset.c			\
		Srcs/my_unset.c				\
		Srcs/tab/triple/delete_line_t_my_tab.c	\
		Srcs/tab/triple/count_t_row.c		\
		Srcs/tab/triple/add_line_t_my_tab.c	\
		Srcs/tab/double/add_line_my_tab.c	\
		Srcs/tab/double/my_copy_tab.c		\
		Srcs/tab/double/delete_line_my_tab.c	\
		Srcs/set_last_cmds.c			\
		Srcs/my_music.c				\
		Srcs/load_music.c			\
		Srcs/destroy_music.c			\
		Srcs/my_music_cmds.c			\
		Srcs/main.c

OBJS 	=  	$(SRCS:.c=.o)

CFLAGS 	+=	-I include -Wall -Wextra -W -lcsfml-audio

NAME 	=	42sh

CC	= 	gcc

$(NAME): 	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

all:		$(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
