/*
** my_getset.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu May 18 09:40:09 2017 Enguerrand Arminjon
** Last update Thu May 18 11:13:01 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	*my_getset(char ***my_set, char *s)
{
  int	i;
  char	*new;

  i = 0;
  new = NULL;
  while (my_set != NULL && my_set[i] != NULL)
    {
      if ((my_strcmp(my_set[i][0], s)) == 0)
	return (my_strcat_malloc(NULL, my_set[i][1]));
      ++i;
    }
  return (new);
}
