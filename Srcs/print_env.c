/*
** print_env.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu May 11 09:35:34 2017 Enguerrand Arminjon
** Last update Mon May 15 15:23:37 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my.h"

int	search_in_my_tab(char **my_tab, char *str)
{
  int	i;

  i = 0;
  if (str == NULL || my_tab != NULL)
    while (my_tab[i] != NULL)
      {
	if (my_strcmp_2(my_tab[i], str, '=') == 0)
	  return (SUCCESS);
	++i;
      }
  return (FAIL);
}

int	print_env(t_shell *shell, char **my_tab)
{
  int	i;

  i = 0;
  if (my_tab == NULL)
    return (SUCCESS);
  while (shell->envp != NULL && shell->envp[i] != NULL)
    {
      my_putstr(shell->envp[i]);
      my_putchar('\n');
      ++i;
    }
  return (FAIL);
}
