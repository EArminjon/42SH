/*
** count_t_row.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh/Srcs/tab/triple
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu May 18 13:17:29 2017 Enguerrand Arminjon
** Last update Fri May 19 08:44:26 2017 Enguerrand Arminjon
*/

#include <stdlib.h>

int	count_t_row(char ***tab)
{
  int	size;

  size = 0;
  while (tab != NULL && tab[size] != NULL)
    ++size;
  return (size);
}
