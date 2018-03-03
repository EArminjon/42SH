/*
** add_line_t_my_tab.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri May 19 08:46:07 2017 Enguerrand Arminjon
** Last update Fri May 19 10:50:37 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	***add_line_t_my_tab(char ***tab, char **new, int pos)
{
  int	i;
  int	a;
  int	size;
  char	***new_tab;

  i = 0;
  a = 0;
  size = count_t_row(tab);
  if (pos > size  || new == NULL ||
      (new_tab = malloc(sizeof(char *) * (size + 2))) == NULL)
    return (NULL);
  while (tab != NULL && tab[i] != NULL && i < pos)
    new_tab[a++] = tab[i++];
  new_tab[a++] = my_copy_my_tab(NULL, new);
  while (tab != NULL && tab[i] != NULL)
    new_tab[a++] = tab[i++];
  new_tab[a] = NULL;
  free(tab);
  return (new_tab);
}
