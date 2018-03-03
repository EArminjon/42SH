/*
** delete_line_t_my_tab.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh/Srcs/tab/triple
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu May 18 13:15:45 2017 Enguerrand Arminjon
** Last update Fri May 19 11:22:49 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	***delete_line_t_my_tab(char ***tab, int pos)
{
  char	**tmp;

  if (tab != NULL && tab[pos] != NULL)
    {
      while (tab[pos] != NULL && tab[pos + 1] != NULL)
	{
	  tmp = tab[pos];
	  tab[pos] = tab[pos + 1];
	  tab[pos + 1] = tmp;
	  pos = pos + 1;
	}
      free_my_tab(tab[pos]);
      tab[pos] = NULL;
    }
  return (tab);
}

char	***my_copy_t_my_tab(char ***tab, int pos)
{
  int	i;
  int	size;
  char	***new;

  size = count_t_row(tab);
  if (tab == NULL || pos < 0 ||
      ((new = malloc(sizeof(char *) * (size + 1))) == NULL))
    return (NULL);
  while (tab[i] != NULL)
    new[pos++] = my_copy_my_tab(NULL, tab[i++]);
  new[pos] = NULL;
  return (new);
}
