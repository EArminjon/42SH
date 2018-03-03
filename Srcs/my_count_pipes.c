/*
** my_count_pipe.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Apr 25 15:42:00 2017 Enguerrand Arminjon
** Last update Tue Apr 25 15:45:35 2017 Enguerrand Arminjon
*/

#include "my.h"

int	my_count_pipes(char **my_tab)
{
  int	i;
  int	waits;

  i = -1;
  waits = 0;
  while (my_tab[++i])
    if (my_strcmp(my_tab[i], "|") == 0)
      ++waits;
  return (waits);
}
