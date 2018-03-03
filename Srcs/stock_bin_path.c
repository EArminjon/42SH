/*
** stock_bin_path.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu May 11 10:49:14 2017 Enguerrand Arminjon
** Last update Wed May 17 16:53:23 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my.h"
#include "shell.h"

int	stock_bin_path(t_shell *shell)
{
  char	*str;

  if (shell != NULL && shell->cd != NULL && shell->cd->home != NULL)
    free(shell->cd->home);
  shell->bin_path = NULL;
  shell->cd->home = my_getenv(shell->envp, "HOME=");
  if (shell->envp == NULL || (search_in_my_tab(shell->envp, "PATH")) == 1)
    str = my_strcat_malloc(NULL, shell->default_path);
  else if ((str = my_getenv(shell->envp, "PATH=")) == NULL)
    return (SUCCESS);
  if (str[0] == '\0')
    {
      free(str);
      return (SUCCESS);
    }
  shell->bin_path = bin_path_my_tab(str, shell->bin_path);
  free(str);
  return (SUCCESS);
}
