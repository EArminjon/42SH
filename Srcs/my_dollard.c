/*
** my_dollard.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Apr 15 15:40:48 2017 Enguerrand Arminjon
** Last update Sat May 20 11:14:52 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	**dollard_number(char **my_tab, int i, int j)
{
  if (my_tab[i][j + 1] == '\0')
    {
      my_tab = delete_line_my_tab(my_tab, i);
      my_putchar('$');
      return (my_tab);
    }
  return (NULL);
}

void	free_this_varia(char *str, char *str2, char *str3)
{
  free(str);
  free(str2);
  free(str3);
}

char	**my_dollard(char **my_tab, int i, int j, t_shell *shell)
{
  char	*s;
  char	*env;
  char	*new;

  if ((dollard_number(my_tab, i, j)) == NULL)
    {
      s = get_str(&my_tab[i][j + 1]);
      if (shell->my_set == NULL ||
	  (env = my_getset(shell->my_set, &my_tab[i][1])) == NULL)
	{
	  if ((env = my_getenv(shell->envp, s)) == NULL)
	    {
	      my_error_str(s, '=', 2, 1);
	      my_fprintf(": Undefined variable.\n");
	      free(s);
	      g_dollard = 1;
	      return (NULL);
	    }
	}
      new = my_new_str(my_tab[i], env);
      free_this_varia(my_tab[i], s, env);
      my_tab[i] = new;
      return (my_tab);
    }
  return (my_tab);
}
