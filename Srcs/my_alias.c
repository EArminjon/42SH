/*
** my_alias.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Apr 29 11:09:19 2017 Enguerrand Arminjon
** Last update Mon May 15 14:01:41 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"

void	free_this_my_tab(char **my_tab, char **tmp)
{
  if (tmp[0] != NULL)
    free(tmp[0]);
  if (tmp != NULL)
    free(tmp);
  if (my_tab != NULL)
    free(my_tab);
}

char	**new_cmds_my_tab(char **my_tab, char *alias)
{
  int	i;
  int	a;
  int	size;
  char	**new;
  char	**tmp;

  tmp = NULL;
  size = count_row(my_tab) + my_nb_argu(alias);
  if (my_tab == NULL || alias == NULL
      || ((new = malloc(sizeof(char *) * (size + 1))) == NULL)
      || ((tmp = str_to_my_tab(alias)) == NULL))
    return (NULL);
  a = 0;
  i = 0;
  while (tmp[++i] != NULL)
    new[a++] = tmp[i];
  i = 0;
  while (my_tab[++i] != NULL)
    new[a++] = my_tab[i];
  new[a] = NULL;
  free_this_my_tab(tmp, my_tab);
  return (new);
}

char	**find_and_make_my_alias(char **ta_alias, char **my_tab)
{
  int	i;
  int	nb;
  char	*alias;

  i = 0;
  while (my_tab != NULL && ta_alias != NULL && ta_alias[i] != NULL)
    {
      nb = 1;
      while (ta_alias[i] != NULL
	     && (nb = my_strcmp_2(ta_alias[i], my_tab[0], ' ') != 0))
	++i;
      if (nb == 0 && ta_alias != NULL && ta_alias[i] != NULL)
	{
	  if (((alias = my_strcat_malloc(NULL, ta_alias[i])) == NULL) ||
	      ((my_tab = new_cmds_my_tab(my_tab, alias)) == NULL))
	    return (NULL);
	  free(alias);
	  ta_alias = delete_line_my_tab(ta_alias, i);
	  i = 0;
	}
    }
  return (my_tab);
}

char	**find_an_alias(t_shell *shell, char **my_tab)
{
  char	**copy;

  copy = NULL;
  copy = my_copy_my_tab(copy, shell->alias);
  my_tab = find_and_make_my_alias(copy, my_tab);
  free_my_tab(copy);
  return (my_tab);
}
