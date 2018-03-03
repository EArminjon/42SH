/*
** my_item_str.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Apr 12 15:08:22 2017 Enguerrand Arminjon
** Last update Thu May 18 13:10:31 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"
#include "my_macro.h"

char	*get_str(char *str)
{
  char	*new;
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    i++;
  new = malloc(sizeof(char) * (i + 2));
  new[0] = '\0';
  i = 0;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '=';
  new[i + 1] = '\0';
  return (new);
}

char	*my_new_str(char *str, char *add_piece)
{
  char	*new;
  int	str_len;

  str_len = my_strlen(str) + my_strlen(add_piece) + 1;
  if ((new = malloc(sizeof(char) * (str_len))) == NULL)
    return (NULL);
  new[0] = '\0';
  new = my_strcat(new, add_piece);
  return (new);
}

char	**edit_str_for_item(char **my_tab, int i, int j, t_shell *shell)
{
  if (my_tab[i][j] == '$')
    return (my_tab = my_dollard(my_tab, i, j, shell));
  else if (my_tab[i][j] == '*')
    return (my_tab = my_star(my_tab, i, 0, NULL));
  return (NULL);
}

char	**my_item_my_tab(char **t, t_shell *shell)
{
  int	i;
  int	j;
  char	**s;
  int	err;

  i = -1;
  err = 0;
  g_dollard = 0;
  while (g_dollard == 0 && t != NULL && t[++i] != NULL)
    {
      j = -1;
      while (g_dollard == 0 && t != NULL && t[i] != NULL && t[i][++j] != '\0')
	{
	  if (t[i][j] == '*' || t[i][j] == '$' || t[i][j] == '\\')
	    {
	      if ((s = edit_str_for_item(t, i, j, shell)) == NULL)
		err++;
	      else
		t = s;
	      i = 0;
	      j = -1;
	    }
	}
    }
  return (err > 0 ? NULL : t);
}
