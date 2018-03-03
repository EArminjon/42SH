/*
** my_strcmp_2 for  in /home/armin.pc/delivery/CPool_Day06
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Oct 10 17:09:59 2016 Enguerrand Arminjon
** Last update Mon May 15 13:23:07 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my_macro.h"

int	my_strcmp_2(char *s1, char *s2, char sep)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (FAIL);
  while (s1[i] == s2[i])
    i++;
  if (s1[i] == sep && s2[i] == '\0')
    return (SUCCESS);
  return (FAIL);
}

int	my_strcmp_3(char *s1, char *s2, char sep)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (FAIL);
  while (s1[i] == s2[i])
    i++;
  if (s1[i] == sep && s2[i] == '\0')
    return (i);
  return (-1);
}
