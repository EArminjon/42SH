/*
** my_builtin.c for  in /home/armin.pc/delivery/PSU_2016_minishell2
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Apr  3 11:10:54 2017 Enguerrand Arminjon
** Last update Tue May 16 16:50:46 2017 Enguerrand Arminjon
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_macro.h"
#include "ptr.h"
#include "shell.h"
#include "my.h"

char	**malloc_this_my_tab(int row, int col)
{
  char	**my_tab;
  int	i;

  i = 0;
  if ((my_tab = malloc(sizeof(char *) * (row + 1))) == NULL)
    return (NULL);
  while (i < row)
    {
      if ((my_tab[i] = malloc(sizeof(char *) * (col + 1))) == NULL)
	return (NULL);
      my_tab[i][0] = '\0';
      ++i;
    }
  my_tab[i] = NULL;
  return (my_tab);
}

int	redir_on_pointer_on_builtin(t_shell *shell, char ***t)
{
  int	nb;
  int	i;

  i = 0;
  nb = 1;
  while (i < BUILTIN &&
	 ((nb = my_strcmp(t[0][0], ptrf_builtin[i].name)) != SUCCESS))
    ++i;
  if (nb == 0)
    nb = ptrf_builtin[i].ptr_function(shell, t[0]);
  else
    return (-2);
  return (nb == 2 ? FAIL : nb);
}

int	my_builtin(t_shell *shell, char ***my_tab)
{
  int	nb;

  nb = 1;
  if (((my_tab == NULL || *my_tab == NULL || *my_tab[0] == NULL))
      || (((my_strcmp(my_tab[0][0], "alias")) != SUCCESS)
	  && ((my_tab[0] = find_an_alias(shell, my_tab[0])) == NULL)))
    return (ERROR);
  nb = redir_on_pointer_on_builtin(shell, my_tab);
  return (nb);
}
