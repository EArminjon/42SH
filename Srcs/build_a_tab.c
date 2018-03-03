/*
** build_a_tab.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue May 16 14:54:34 2017 Enguerrand Arminjon
** Last update Wed May 17 08:39:31 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	**build_a_tab(char *str, char **tab)
{
  int	i;
  int	pos;
  char **new;

  i = count_row(tab);
  pos = 0;
  if ((new = malloc(sizeof(char *) * (i + 2))) == NULL)
    return (NULL);
  i = 0;
  while (tab != NULL && tab[i] != NULL)
    new[pos++] = tab[i++];
  new[pos++] = my_strcat_malloc(NULL, str);
  new[pos] = NULL;
  free(tab);
  return (new);
}
