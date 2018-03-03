/*
** my_put_in_list_next.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Apr 15 15:32:18 2017 Enguerrand Arminjon
** Last update Mon May 15 14:00:18 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char		**malloc_my_my_tab(char **my_tab, char *str)
{
  int		i;
  int		size;

  i = 0;
  size = my_nb_argu(str);
  if ((my_tab = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  while (i < size)
    {
      my_tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
      my_tab[i][0] = '\0';
      ++i;
    }
  my_tab[i] = NULL;
  return (my_tab);
}

char		**my_char_to_str(char *str, char **my_tab, int *i, int *a)
{
  int		sep;
  int		b;

  b = 0;
  sep = 0;
  increment_i(str, i, &sep, '\"');
  while ((sep == 1 && str[*i] != '\0' && str[*i] != '\"')
	 || (sep == 0 && str[*i] != ' ' && str[*i] != '\t'
	     && str[*i] != '\0'))
    {
      my_tab[*a][b++] = str[*i];
      *i = *i + 1;
    }
  decrement_i(str, i, &sep, '\"');
  my_tab[*a][b] = '\0';
  *a = *a + 1;
  while (str[*i] == ' ' || str[*i] == '\t')
    *i = *i + 1;
  return (my_tab);
}

char		**my_put_in_my_tab(char *str, char **my_tab, int *i)
{
  int		a;

  a = 0;
  if ((my_tab = malloc_my_my_tab(my_tab, str)) == NULL)
    return (NULL);
  while (str[*i] != '\0' && my_limit(&str[*i]) == 0)
    if (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\0')
      my_char_to_str(str, my_tab, i, &a);
  my_tab = cut_last_line(my_tab, a);
  return (my_tab);
}

char		**my_put_in_my_tab_2(char *str, char **my_tab, int *i)
{
  char		sep;
  int		a;

  a = 0;
  if ((my_tab = malloc_my_my_tab(my_tab, str)) == NULL)
    return (NULL);
  sep = str[*i];
  while (str[*i] != '\0' && (str[*i] == sep))
    if (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\0')
      my_char_to_str(str, my_tab, i, &a);
  my_tab = cut_last_line(my_tab, a);
  return (my_tab);
}
