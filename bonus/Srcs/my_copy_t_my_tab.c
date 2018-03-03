/*
** my_copy_t_tab.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed May 17 17:22:38 2017 Enguerrand Arminjon
** Last update Fri May 19 10:45:27 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	***my_copy_t_my_tab_custom(char ***tab, int one_for_new_row,
				   int *here, char *sep)
{
  int	i;
  int	nb;
  char	***new;
  int	pos;
  int	size;

  i = 0;
  nb = 1;
  pos = 0;
  size = count_t_row(tab);
  if (sep == NULL ||
      ((new = malloc(sizeof(char *) * (size + 1 + one_for_new_row))) == NULL))
    return (NULL);
  while (tab != NULL && tab[i] != NULL)
    {
      if (nb == 1 && (((nb = my_strcmp(sep, tab[i][0])) == 0)
		      || ((nb = my_strcmp_2(sep, tab[i][0], '=')) == 0)))
	*here = i;
      new[pos++] = tab[i++];
    }
  if (nb == 1)
    *here = i;
  new[pos] = NULL;
  new[pos + 1] = NULL;
  return (new);
}
