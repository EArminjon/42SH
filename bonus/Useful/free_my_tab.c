/*
** free_my_my_tab.c for  in /home/armin.pc/delivery/PSU_2016_minishell1
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Jan  6 18:17:05 2017 Enguerrand Arminjon
** Last update Wed May 17 14:35:58 2017 Enguerrand Arminjon
*/

#include <stdlib.h>

char	**free_my_my_tab(char **my_tab)
{
  int	i;

  i = 0;
  if (my_tab == NULL)
    return (NULL);
  while (my_tab[i] != NULL)
    {
      if (my_tab[i] != NULL)
	free(my_tab[i]);
      i++;
    }
  if (my_tab != NULL)
    free(my_tab);
  return (NULL);
}
