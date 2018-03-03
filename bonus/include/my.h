/*
** my.h for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri May 12 16:54:34 2017 Enguerrand Arminjon
** Last update Sat May 20 10:49:52 2017 Enguerrand Arminjon
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>
# include <stdarg.h>
# include <SFML/Audio.h>
# include "shell.h"

int	g_error;
int	g_dollard;
char	*g_prompt;

/*
** Tab lib
*/

int	set_last_cmds(t_shell *shell, t_chained *chain, int i);
char	**add_line_my_tab(char **tab, char *new, int pos);
char	***add_line_t_my_tab(char ***tab, char **new, int pos);
char	***delete_line_t_my_tab(char ***tab, int pos);
int	count_t_row(char ***tab);

/*
** Project's functions
*/

int	my_print_builtin(t_shell *shell, char **my_tab);
int	destroy_music(t_shell *shell);
int	load_music();
int	my_music_play(t_shell *shell, char **my_tab);
int	my_music_pause(t_shell *shell, char **my_tab);
int	my_music_random(t_shell *shell, char **my_tab);
int	my_music_stop(t_shell *shell, char **my_tab);
int	my_music(t_shell *shell, char **my_tab);
char	*my_getset(char ***my_tab, char *s);
int	my_set_argu(t_shell *shell, char *tmp);
int	free_t_my_tab(char ***tab);
char	***my_copy_t_my_tab_custom(char ***t, int one, int *here, char *sep);
char	*replace_var_by_argu_next(char *cmds_str, char *argu, t_shell *shell);
char	*my_var(char *str, char **envp, int i);
char	**build_a_tab(char *str, char **cmds);
int	my_foreach(t_shell *shell, char **my_tabs);
int	start_shell(t_shell *shell, char *str, int nb);
char	*my_tab_to_str(char **my_tab);
int	my_repeat(t_shell *shell, char **my_tab);
int	my_if(t_shell *shell, char **my_tab);
int	my_set(t_shell *shell, char **my_tab);
int	my_unset(t_shell *shell, char **my_tab);
int	my_alias(t_shell *shell, char **my_tab);
int	my_where_alias(t_shell *shell, char **my_tab, int pos);
char	*my_keyboard();
int	check_builts(char *);
t_keys	*my_keys(char **envp);
char	**my_builtin_my_tab();
int	my_which(t_shell *shell, char **my_tab);
int	my_where(t_shell *shell, char **my_tab);
int	stock_bin_path(t_shell *shell);
int	search_in_my_tab(char **my_tab, char *str);
int	print_env(t_shell *shell, char **my_tab);
char	***my_put_my_tab(char ***my_tab, char *str, int *pos, int zero);
void	my_prompt();
int	edit_my_shell(t_shell *shell, char **my_tab);
char	*clear_str(char *str);
char	**add_an_alias(t_shell *shell, char **my_tab);
int	my_42shrc(t_shell *shell, char *name);
char	**malloc_my_my_tab(char **my_tab, char *str);
char	**str_to_my_tab(char *str);
char	**find_an_alias(t_shell *shell, char **my_tab);
int	add_or_display_alias(t_shell *shell, char **my_tab);
int	my_limit(char *str);
char	**cut_last_line(char **my_tab, int a);
void	increment_i(char *str, int *i, int *sep, char limit);
void	decrement_i(char *str, int *i, int *sep, char limit);
int	my_redir(char *file, int *fd, mode_t flag, int ret);
char	*fix_path(char *new, char *cmds, char *path);
int	my_count_pipes(char **my_tab);
int	delete_false_row(t_chained *chain);
int	init_sig(void);
int	put_history(char **s, t_shell *shell);
int	my_strcmspace(char *, char *);
char	*take_following(char *);
char	*modify_with_simple(char *, char *);
char	*modify_with_double(char *, char *);
char	*last_history_line(char *, int, int *);
char	*mallocat(char *, char *);
int	check_hist(char *);
int	ambi_direct(char **my_tab, int i);
char	*my_clear_str(char *str);
char	**put_in_my_tab(char *str);
char	*check_inibitor(char *str);
char	**find_build(char **my_tab);
int	my_rev_strcmp(char *str, char *ref);
char	**remove_bad_line(char **my_tab, char *str);
char	**modif_av(char **my_tab);
int	can_i_continu(char ***my_tab, int *i, int nb, int *stop);
int	my_reset(int *left, int *right, int *d_left, int *d_right);
int	count_redir(char *str, int reset_1);
char	**delete_two_lines(char **my_tab, int pos);
char	*get_str(char *str);
char	*my_new_str(char *str, char *tmp_env);
char	**my_dollard(char **my_tab, int i, int j, t_shell *shell);
char	**my_put_in_my_tab(char *copy, char **my_tab, int *pos);
char	**my_put_in_my_tab_2(char *copy, char **my_tab, int *pos);
int	print_t_my_tab(char ***my_tab);
char	**delete_my_tab(char **my_tab, int pos);
char	*my_new_row_env(char **my_tab);
int	count_row(char **my_tab);
char	**my_star(char **my_tab, int i, int size, char **t);
int	my_error_str(char *str, char sep, int canal, int ret);
char	**delete_line_my_tab(char **my_tab, int i);
char	**my_item_my_tab(char **my_tab, t_shell *shell);
char	*my_getenv(char **envp, char *str);
int	my_display_error(int *fd, char *file);
int	my_echo(t_shell *shell, char **my_tab);
int	my_nb_argu(char *str);
int	my_put_in_list(char *str, t_chained *chain, int size);
int	my_builtin(t_shell *shell, char ***my_tab);
int	loop_shell(t_shell *shell, char *s);
int	check_cmds_perms(char *str, t_shell *shell, char **my_tab);
int	series_of_test(t_shell *shell, t_chained *chain, int *fd, int zero);
int	do_redirection(char **my_tab);
int	my_cd_back(t_shell *shell, int nb);
int	my_cd_home(t_shell *shell);
int	my_cd_safe_back(t_shell *shell);
int	my_cd_path(t_shell *shell, char **my_tab);
int	exec_the_prompt(t_shell *shell, t_chained *chain, int nb);
int	debug_chain_my_tab_before(t_chained *chain);
char	*my_parser(char *str, char *copy, int *i);
int	my_cd(t_shell *shell, char **my_tab);
int	my_exit(t_shell *shell, char **my_tab);
int	my_setenv(t_shell *shell, char **my_tab);
int	my_unsetenv(t_shell *shell, char **my_tab);
int	my_fork(t_shell *shell, char **my_tab, char *str);
char	*my_getenv(char **envp, char *fin);
char	**bin_path_my_tab(char *str, char **my_tab);
void	*free_list(t_chained *chain);
char	**my_copy_my_tab(char **my_tab_1, char **my_tab_2);
char	**clone_my_tab(char **envp, char **my_tab);
char	**prepair_pipe(t_shell *shell, char **my_tab, int *tmp);
int	my_execve(t_shell *shell, char **my_tab);

/*
** Other functions
*/

int	my_str_isalpha(char *str);
int	my_puterror(char *str, int canal, int return_error);
int	print_my_tab(char **my_tab);
char	*get_next_line(int fd);
char	**free_my_tab(char **my_tab);
char	my_strcmp(char *str_1, char *str_2);
int	my_strncmp(char *str_1, char *str_2, int nb);
int	my_strcmp_2(char *str_1, char *str_2, char sep);
int	my_strcmp_3(char *str_1, char *str_2, char sep);
char	*my_strcat(char *dest, char *src);
char	*my_strcat_malloc(char *dest, char *src);
char	*my_strcat_malloc_free(char *dest, char *src);
char	*my_realloc(char *str, int new_size);
void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
char	*my_revstr(char *str);
int	my_str_isnum(char *str);
void	find_history_line_loop(char *find, char *str, char **path);

/*
** My printf
*/

int	my_printf(char *s, ...);
void	for_my_pitch(int i, int zero);
int	my_size_c(int nb);
void	the_hashtag(char *s, va_list ap, int *a);
void	the_else_print(int *a);
void	the_flags(char *s, va_list ap, int *a);
void	my_octal(long int nb);
int	my_put_short(short nb);
int	my_size(int nb);
void	my_binari(int nb);
void	my_hexadecimal(long int nb);
void	my_hexadecimal_2(long int nb);
int	my_putstr_int(int *str);
int	my_put_long(long int nb);

/*
** My fprintf
*/

int	my_fprintf(char *s, ...);
void	for_my_pitch(int i, int zero);
int	my_fsize_c(int nb);
void	fthe_hashtag(char *s, va_list ap, int *a);
void	fthe_else_print(int *a);
void	fthe_flags(char *s, va_list ap, int *a);
void	my_foctal(long int nb);
int	my_fput_short(short nb);
int	my_fsize(int nb);
void	my_fbinari(int nb);
void	my_fhexadecimal(long int nb);
void	my_fhexadecimal_2(long int nb);
int	my_fputstr_int(int *str);
int	my_fput_long(long int nb);
int	my_fput_nbr(int nb);
int	my_fputstr(char *str);
void	my_fputchar(char c);

#endif /* !MY_H_ */
