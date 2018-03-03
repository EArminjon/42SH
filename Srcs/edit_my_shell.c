/*
** edit_my_shell.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Apr 29 14:15:43 2017 Enguerrand Arminjon
** Last update Mon May 15 12:58:54 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my.h"
#include "shell.h"

int	launch_alias(char **my_tab, t_shell *shell)
{
  shell->alias = add_an_alias(shell, my_tab);
  return (SUCCESS);
}

int	launch_env(char **my_tab, t_shell *shell)
{
  my_setenv(shell, my_tab);
  return (SUCCESS);
}

int	launch_history(char **my_tab, t_shell *shell)
{
  int	size;

  size = 0;
  size = my_getnbr(my_tab[1]);
  if (size > 0)
    shell->size_history = size;
  return (SUCCESS);
}

int	edit_my_shell(t_shell *shell, char **my_tab)
{
  if (my_tab == NULL || my_tab[0] == '\0')
    return (SUCCESS);
  else if (my_strcmp(my_tab[0], "alias") == 0)
    launch_alias(my_tab, shell);
  else if (my_strcmp(my_tab[0], "env") == 0)
    launch_env(my_tab, shell);
  else if (my_strcmp(my_tab[0], "history") == 0)
    launch_history(my_tab, shell);
  return (SUCCESS);
}
