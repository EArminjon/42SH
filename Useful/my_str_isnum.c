/*
** my_str_isnum.c for  in /home/armin.pc/delivery/CPool_Day07/lib/my
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Oct 12 08:51:31 2016 Enguerrand Arminjon
** Last update Mon May 15 13:21:30 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my_macro.h"

int	my_str_isnum(char *str)
{
  int	a;

  a = 0;
  if (str == NULL)
    return (FAIL);
  while (str[a] != '\0' && str[a] >= '0' && str[a] <= '9')
    {
      a = a + 1;
      if (str[a] == '\0')
	return (SUCCESS);
    }
  return (FAIL);
}
