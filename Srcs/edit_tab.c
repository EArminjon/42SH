/*
** swap_my_tab.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Apr 14 10:18:49 2017 Enguerrand Arminjon
** Last update Fri May 19 11:34:12 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	*after_star(char *str)
{
  int	i;

  i = 0;
  if (str[i] != '\0')
    {
      while (str[i] != '\0' && str[i] != '*')
	i++;
      if (str[i] == '*')
	i++;
    }
  return (&str[i]);
}

char	**remove_bad_line(char **t, char *ref)
{
  int	i;

  i = 1;
  ref = after_star(ref);
  while (t[i] != NULL)
    {
      if (ref != NULL && ref[0] != '\0' && (my_rev_strcmp(t[i], ref) == 1))
	{
	  t = delete_line_my_tab(t, i);
	  i = -1;
	}
      i++;
    }
  return (t);
}

char	**delete_two_lines(char **my_tab, int i)
{
  char	*tmp;
  char	*tmp2;

  while (my_tab != NULL && my_tab[i + 1] != NULL && my_tab[i + 2] != NULL)
    {
      tmp = my_tab[i + 2];
      tmp2 = my_tab[i + 1];
      my_tab[i + 1] = my_tab[i];
      my_tab[i] = tmp;
      my_tab[i + 2] = tmp2;
      i++;
    }
  free(my_tab[i]);
  free(my_tab[i + 1]);
  my_tab[i] = NULL;
  return (my_tab);
}

char	**delete_my_tab(char **my_tab, int i)
{
  while (my_tab[i] != NULL)
    {
      free(my_tab[i]);
      my_tab[i] = NULL;
      i++;
    }
  return (my_tab);
}
