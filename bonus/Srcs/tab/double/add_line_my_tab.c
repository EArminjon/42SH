/*
** add_line_my_tab.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri May 19 09:51:14 2017 Enguerrand Arminjon
** Last update Fri May 19 10:16:22 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	**add_line_my_tab(char **tab, char *new, int pos)
{
  int	i;
  int	a;
  int	size;
  char	**new_tab;

  i = 0;
  a = 0;
  size = count_row(tab);
  if (pos > size || new == NULL ||
      ((new_tab = malloc(sizeof(char *) * (size + 2))) == NULL))
    return (NULL);
  while (tab != NULL && tab[i] != NULL && i < pos)
    new_tab[a++] = tab[i++];
  new_tab[a++] = my_strcat_malloc(NULL, new);
  while (tab != NULL && tab[i] != NULL)
    new_tab[a++] = tab[i++];
  new_tab[a] = NULL;
  free(tab);
  return (new_tab);
}
