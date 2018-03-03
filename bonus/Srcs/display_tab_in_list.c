/*
** display_my_tab_in_list.c for  in /home/armin.pc/delivery/PSU_2016_minishell2
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Mar 31 09:47:54 2017 Enguerrand Arminjon
** Last update Sat Apr 15 15:27:01 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "shell.h"
#include "my.h"

void	display_my_tab_in_list(t_chained *chain)
{
  int	i;

  i = 0;
  while (chain != NULL)
    {
      while (chain->my_tab[i] != NULL)
	{
	  if (chain->my_tab[i] != NULL)
	    print_my_tab(chain->my_tab[i]);
	  i++;
	}
      chain = chain->next;
    }
}
