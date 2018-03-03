/*
** free_and_exit.c for  in /home/armin.pc/delivery/PSU_2016_minishell1
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Jan 19 16:30:01 2017 Enguerrand Arminjon
** Last update Wed Apr 12 12:06:35 2017 Enguerrand Arminjon
*/

#include <stdlib.h>

char	**free_my_tab(char **my_tab)
{
  int	i;

  i = 0;
  if (my_tab != NULL)
    {
      while (my_tab[i] != NULL)
	{
	  free(my_tab[i]);
	  ++i;
	}
      free(my_tab);
    }
  return (NULL);
}
