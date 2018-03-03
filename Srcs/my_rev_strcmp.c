/*
** my_rev_strcmp.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Apr 15 19:48:33 2017 Enguerrand Arminjon
** Last update Mon May 15 13:14:11 2017 Enguerrand Arminjon
*/

#include "my_macro.h"
#include "my.h"

int	my_rev_strcmp(char *str, char *find)
{
  int	i;
  int	j;

  if (str == NULL || find == NULL)
    return (FAIL);
  i = my_strlen(str);
  j = my_strlen(find);
  while (j > 0 && i > 0 && str[i] == find[j])
    {
      i = i - 1;
      j = j - 1;
      if (j == 0)
	return (SUCCESS);
    }
  return (FAIL);
}
