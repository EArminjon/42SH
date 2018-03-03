/*
** my_main_cd.c for  in /home/armin.pc/delivery/PSU_2016_minishell2
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Mar 28 09:04:33 2017 Enguerrand Arminjon
** Last update Mon May 15 13:11:25 2017 Enguerrand Arminjon
*/

#include "my_macro.h"
#include "shell.h"
#include "my.h"

int	my_cd(t_shell *shell, char **my_tab)
{
  int	nb;

  nb = 1;
  if (my_strcmp(my_tab[0], "..") == SUCCESS)
    nb = my_cd_back(shell, 0);
  else if (my_strcmp(my_tab[0], "...") == SUCCESS)
    nb = my_cd_back(shell, 1);
  else if (my_tab[1] == NULL || my_strcmp(my_tab[1], "--") == SUCCESS)
    nb = my_cd_home(shell);
  else if (my_strcmp(my_tab[1], "-") == SUCCESS)
    nb = my_cd_safe_back(shell);
  else if (my_tab[1] != NULL && my_tab[2] == NULL)
    nb = my_cd_path(shell, my_tab);
  else
    {
      my_fprintf("%s: Too many arguments.\n", my_tab[0]);
      nb = 2;
    }
  return (nb);
}
