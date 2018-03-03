/*
** my_put_in_super_my_tab.c for  in /home/armin.pc/delivery/PSU_2016_minishell2
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu Mar 23 09:44:28 2017 Enguerrand Arminjon
** Last update Mon May 15 12:45:40 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my.h"
#include "shell.h"

int		my_count_argu_my_tab(char *str)
{
  int		i;
  int		size;

  i = 0;
  size = 1;
  while (str[i] != '\0' && str[i] != ';')
    {
      if ((str[i] == '&' && str[i + 1] == '&')
	  || (str[i] == '|' && str[i + 1] == '|'))
	size++;
      i++;
    }
  return (size);
}

char		*put_in_str(char *str, int *i)
{
  char		*copy;

  if ((copy = malloc(sizeof(char) * (2 * (my_strlen(str) + 1)))) == NULL)
    return (NULL);
  copy[0] = '\0';
  copy = my_parser(str, copy, i);
  return (copy);
}

char		***my_put_my_tab(char ***my_tab, char *str, int *i, int a)
{
  int		pos;
  char		*copy;

  pos = 0;
  if (((copy = put_in_str(str, i)) == NULL) ||
      ((my_tab = malloc(sizeof(char *) * (my_strlen(copy) + 1))) == NULL))
    return (NULL);
  while (copy != NULL && copy[pos] != '\0')
    {
      while (copy[pos] != '\0' && copy[pos] != '&' && copy[pos] != '|')
	{
	  if (((my_tab[a] = my_put_in_my_tab(copy, my_tab[a], &pos)) == NULL))
	    return (NULL);
	  a++;
	}
      if (copy[pos] == '|' || copy[pos] == '&')
	{
	  if (((my_tab[a] = my_put_in_my_tab_2(copy, my_tab[a], &pos)) == NULL))
	    return (NULL);
	  ++a;
	}
    }
  my_tab[a] = NULL;
  free(copy);
  return (my_tab);
}

int		create_list(t_chained *chain)
{
  t_chained	*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (ERROR);
  tmp->my_tab = NULL;
  tmp->next = NULL;
  chain->next = tmp;
  return (SUCCESS);
}

int		my_put_in_list(char *str, t_chained *chain,
			       int size)
{
  t_chained	*tmp;
  char		***my_tab;
  int		i;

  i = 0;
  tmp = chain;
  my_tab = NULL;
  chain->my_tab = NULL;
  chain->next = NULL;
  while (i < size)
    {
      if (((tmp->my_tab = my_put_my_tab(my_tab, str, &i, 0)) == NULL)
	  || ((create_list(tmp)) == ERROR))
	return (ERROR);
      tmp = tmp->next;
    }
  free(str);
  if ((delete_false_row(chain)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
