/*
** tools_for_put_in_list.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Apr 28 15:35:14 2017 Enguerrand Arminjon
** Last update Mon May 15 12:43:38 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my_macro.h"

int	my_limit(char *str)
{
  if ((str[0] == '&' && str[1] == '&') || (str[0] == '|' && str[1] == '|'))
    return (OFF);
  return (ON);
}

char	**cut_last_line(char **my_tab, int a)
{
  int	tmp;

  tmp = a;
  while (my_tab[a] != NULL)
    free(my_tab[a++]);
  my_tab[tmp] = NULL;
  return (my_tab);
}

void	increment_i(char *str, int *i, int *sep, char limit)
{
  if (str[*i] == limit)
    {
      *i = *i + 1;
      *sep = 1;
    }
}

void	decrement_i(char *str, int *i, int *sep, char limit)
{
  if (str[*i] == limit)
    {
      *i = *i + 1;
      *sep = 0;
    }
}
