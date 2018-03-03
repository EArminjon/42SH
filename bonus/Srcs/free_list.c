/*
** free_list.c for  in /home/armin.pc/delivery/PSU_2016_minishell2
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu Mar 23 14:35:12 2017 Enguerrand Arminjon
** Last update Wed May 17 17:59:49 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "shell.h"
#include "my.h"

int		free_t_my_tab(char ***my_tab)
{
  int		i;

  i = 0;
  if (my_tab != NULL)
    {
      while (my_tab[i] != NULL)
	{
	  free_my_tab(my_tab[i]);
	  i++;
	}
      free(my_tab);
    }
  return (0);
}

void		*free_list(t_chained *list)
{
  t_chained	*tmp;
  int		i;

  i = 0;
  while (list != NULL)
    {
      tmp = list->next;
      if (list->my_tab != NULL)
	free_t_my_tab(list->my_tab);
      if (i != 0)
	free(list);
      list = tmp;
      i++;
    }
  return (NULL);
}
