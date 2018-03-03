/*
** my_unset.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu May 18 11:37:11 2017 Enguerrand Arminjon
** Last update Thu May 18 13:16:05 2017 Enguerrand Arminjon
*/

#include "my.h"
#include "shell.h"

int	my_unset_argu(t_shell *shell, char **my_tab, char *str)
{
  int	pos;
  int	i;

  pos = -1;
  while (my_tab != NULL && my_tab[++pos] != NULL)
    {
      i = 0;
      while (shell->my_set != NULL && shell->my_set[i] != NULL)
	{
	  if (shell->my_set[i][0] != NULL &&
	      (my_strcmp(shell->my_set[i][0], str)) == 0)
	    {
	      shell->my_set = delete_line_t_my_tab(shell->my_set, i);
	      return (0);
	    }
	  ++i;
	}
    }
  return (0);
}

int	my_unset(t_shell *shell, char **my_tab)
{
  int	nb;

  nb = 1;
  if (my_tab[1] == NULL)
    return (my_puterror("unset: Too few arguments.\n", 2, 1));
  else
    nb = my_unset_argu(shell, my_tab, my_tab[1]);
  return (nb);
}
