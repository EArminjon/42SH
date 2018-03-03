/*
** delete_false_row.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Apr 25 14:36:43 2017 Enguerrand Arminjon
** Last update Mon May 15 12:58:03 2017 Enguerrand Arminjon
*/

#include "my_macro.h"
#include "shell.h"
#include "my.h"

char		***delete_this_argument(char ***my_tab, int del)
{
  char		**tmp;

  tmp = NULL;
  if (my_tab != NULL)
    {
      while (my_tab[del + 1] != NULL)
	{
	  tmp = my_tab[del];
	  my_tab[del] = my_tab[del + 1];
	  my_tab[del + 1] = tmp;
	  del++;
	}
      if (my_tab[del] != NULL)
	free_my_tab(my_tab[del]);
      my_tab[del] = NULL;
    }
  return (my_tab);

}

int		check_this_triple_my_tab(char ***t)
{
  if (t[0] != NULL && t[0][0] != NULL && my_strcmp(t[0][0], "&&") == 0)
    if ((t = delete_this_argument(t, 0)) == NULL)
      return (ERROR);
  return (SUCCESS);
}

int		delete_false_row(t_chained *chain)
{
  t_chained	*tmp;

  tmp = chain;
  while (tmp != NULL)
    {
      if (tmp->my_tab != NULL)
	check_this_triple_my_tab(tmp->my_tab);
      tmp = tmp->next;
    }
  return (SUCCESS);
}
