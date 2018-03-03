/*
** my_foreach.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue May 16 14:00:32 2017 Enguerrand Arminjon
** Last update Thu May 18 09:26:42 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "my.h"

int	replace_var_by_argu(char *var, char *cmds_str,
			    char *argu, t_shell *shell)
{
  char	*tmp;
  int	nb;
  int	i;

  i = 0;
  nb = 0;
  while (cmds_str != NULL && cmds_str[i] != '\0')
    {
      if (cmds_str[i] == '$'
	  && ((((my_strcmp(&cmds_str[i + 1], var)) == 0)) ||
	      (((my_strcmp_2(&cmds_str[i + 1], var, ' ')) == 0))))
	cmds_str = replace_var_by_argu_next(cmds_str, argu, shell);
      ++i;
    }
  nb = start_shell(shell, cmds_str, nb);
  if (((tmp = my_strcat_malloc_free(NULL, var)) == NULL) ||
      ((tmp = my_strcat_malloc_free(tmp, "=")) == NULL) ||
      ((tmp = my_strcat_malloc_free(tmp, argu)) == NULL))
    return (84);
  my_set_argu(shell, tmp);
  free(tmp);
  return (nb);
}

int	my_exec_foreach(t_shell *shell, char **tab, char **cmds)
{
  char	*cmds_str;
  int	pos;
  int	nb;
  int	i;

  pos = 3;
  nb = 0;
  while (my_strcmp(tab[pos], ")") != 0)
    {
      i = 0;
      while (cmds[i] != NULL)
	{
	  cmds_str = my_strcat_malloc(NULL, cmds[i]);
	  nb = replace_var_by_argu(tab[1], cmds_str, tab[pos], shell);
	  ++i;
	}
      ++pos;
    }
  return (nb);
}

int	exit_my_foreach()
{
  if (isatty(0) == 1)
    return (my_puterror("foreach: end not found.\n", 2, 1));
  return (my_puterror("", 2, 0));
}

int	my_foreach_prompt(t_shell *shell, char **tab, int nb)
{
  char	*s;
  char	**cmds;

  cmds = NULL;
  while (1)
    {
      if (isatty(0) == 1)
	my_putstr("foreach? ");
      s = get_next_line(0);
      if (s == NULL || ((nb = my_strcmp(s, "end")) == 0))
	{
	  if (s != NULL)
	    free(s);
	  break ;
	}
      if ((cmds = build_a_tab(s, cmds)) == NULL)
	return (84);
      free(s);
    }
  if (nb == 1)
    return (exit_my_foreach());
  nb = my_exec_foreach(shell, tab, cmds);
  free_my_tab(cmds);
  return (nb);
}

int	my_foreach(t_shell *shell, char **tab)
{
  int	nb;

  nb = 1;
  if (tab[1] == NULL || tab[2] == NULL || tab[3] == NULL)
    return (my_puterror("foreach: Too few arguments.\n", 2, 1));
  else if (tab[2][0] != '(')
    return (my_puterror("foreach: Words not parenthesized.\n", 2, 1));
  else
    nb = my_foreach_prompt(shell, tab, 1);
  return (nb);
}
