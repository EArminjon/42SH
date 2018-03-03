/*
** tab_to_str.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue May 16 10:33:15 2017 Enguerrand Arminjon
** Last update Tue May 16 10:54:12 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

int	count_all_carac(char **tab)
{
  int	size;
  int	i;

  size = 0;
  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      size = size + my_strlen(tab[i]);
      ++i;
    }
  return (size);
}

char	*my_tab_to_str(char **tab)
{
  char	*new;
  int	size;
  int	pos;
  int	j;
  int	i;

  size = count_all_carac(tab);
  if (tab == NULL || ((new = malloc(sizeof(char) * (2 * size))) == NULL))
    return (NULL);
  new[0] = '\0';
  i = 0;
  pos = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      if (tab[i][j] != '\0')
	{
	  while (tab[i][j] != '\0')
	    new[pos++] = tab[i][j++];
	  ++i;
	  new[pos++] = ' ';
	}
    }
  new[pos] = '\0';
  return (new);
}
