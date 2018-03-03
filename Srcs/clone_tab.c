/*
** my_tab_and_malloc.c for  in /home/armin.pc/delivery/PSU_2016_minishell1/srcs
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Jan  6 20:03:16 2017 Enguerrand Arminjon
** Last update Fri May 12 13:49:55 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	**clone_my_tab(char **ev, char **my_tab)
{
  int	j;
  int	a;
  int	i;

  i = 0;
  while (ev != NULL && ev[i] != '\0')
    i++;
  a = i;
  i = 0;
  if ((my_tab = malloc(sizeof(char *) * (a + 2))) == NULL)
    return (NULL);
  while (ev != NULL && ev[i] != '\0')
    {
      j = -1;
      if ((my_tab[i] = malloc(sizeof(char) * (my_strlen(ev[i]) + 1))) == NULL)
	return (NULL);
      while (ev[i][++j] != '\0')
	my_tab[i][j] = ev[i][j];
      my_tab[i++][j] = '\0';
    }
  my_tab[i] = NULL;
  return (my_tab);
}
