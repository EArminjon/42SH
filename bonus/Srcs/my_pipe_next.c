/*
** my_pipe_next.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Apr 15 19:30:58 2017 Enguerrand Arminjon
** Last update Fri Apr 28 13:27:34 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	**modif_av(char **av)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (my_strcmp(av[i], "|") != 0)
    ++i;
  ++i;
  while (av[i])
    {
      av[j] = av[i];
      ++i;
      ++j;
    }
  av[j] = NULL;
  return (av);
}
