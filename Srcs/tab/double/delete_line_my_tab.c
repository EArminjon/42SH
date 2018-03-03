/*
** delete_line_my_tab.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri May 19 11:33:41 2017 Enguerrand Arminjon
** Last update Fri May 19 11:35:39 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	**delete_line_my_tab(char **my_tab, int i)
{
  char	*tmp;

  tmp = NULL;
  if (my_tab != NULL)
    {
      while (my_tab[i + 1] != NULL)
	{
	  tmp = my_tab[i];
	  my_tab[i] = my_tab[i + 1];
	  my_tab[i + 1] = tmp;
	  i++;
	}
      if (my_tab[i] != NULL)
	free(my_tab[i]);
      my_tab[i] = NULL;
    }
  return (my_tab);
}
