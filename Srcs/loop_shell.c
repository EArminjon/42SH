/*
** loop_shell.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri May 12 17:07:01 2017 Enguerrand Arminjon
** Last update Fri May 19 15:24:05 2017 Enguerrand Arminjon
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_macro.h"
#include "my.h"
#include "shell.h"

int		my_clear_var(t_chained *chain)
{
  if (chain != NULL)
    free_list(chain);
  return (SUCCESS);
}

int		start_shell(t_shell *shell, char *s, int nb)
{
  t_chained	c;

  if ((my_put_in_list(s, &c, my_strlen(s))) == ERROR)
    return (ERROR);
  if (c.my_tab != NULL && c.my_tab[0] != NULL && c.my_tab[0][0] != NULL)
    nb = exec_the_prompt(shell, &c, 0);
  if ((my_clear_var(&c)) == ERROR)
    return (ERROR);
  return (nb);
}

int		loop_shell(t_shell *shell, char *s)
{
  int		nb;

  nb = 0;
  while (shell->exit == 0)
    {
      g_error = 0;
      if ((isatty(0)) == 1)
	my_putstr("42sh> ");
      if ((s = check_inibitor(get_next_line(0))) == NULL && g_error == 0)
	return (isatty(0) == 1 ? my_puterror("exit\n", 1, nb)
		: my_puterror("", 1, nb));
      nb = g_error;
      nb = start_shell(shell, s, nb);
    }
  return (nb);
}
