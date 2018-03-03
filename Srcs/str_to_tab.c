/*
** str_to_my_tab.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Apr 29 12:12:32 2017 Enguerrand Arminjon
** Last update Mon May 15 13:54:12 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	**str_to_my_tab(char *str)
{
  int	i;
  int	j;
  int	a;
  char	**my_tab;

  a = 0;
  i = 0;
  my_tab = NULL;
  my_tab = malloc_my_my_tab(my_tab, str);
  while (str != NULL && str[a] != '\0')
    {
      j = 0;
      if (str[a] != ' ' && str[a] != '\t')
	{
	  while (str[a] != ' ' && str[a] != '\t' && str[a] != '\0')
	    my_tab[i][j++] = str[a++];
	  my_tab[i++][j] = '\0';
	}
      if (str[a] != '\0')
	++a;
    }
  my_tab[i] = NULL;
  return (my_tab);
}
