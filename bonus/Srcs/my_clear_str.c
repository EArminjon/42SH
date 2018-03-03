/*
** my_clear_str.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Apr 19 14:29:08 2017 Enguerrand Arminjon
** Last update Tue May 16 14:22:18 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my.h"

int	count_sep(char *str, char sep, int nb)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (str[i] == sep)
	count = count + 1;
      ++i;
    }
  if (count % 2 != 0 && nb == 0)
    my_fprintf("Unmatched '%c'.\n", sep);
  else if (nb == 0)
    return (0);
  if (nb == 0)
    g_error = 1;
  return (count);
}

char	*count_inibit(char *str)
{
  int	one;
  int	two;

  if (((count_sep(str, '\"', 0)) != 0)
      || ((count_sep(str, '\'', 0)) != 0))
    {
      str[0] = '\0';
      return (str);
    }
  one = count_sep(str, '(', 1);
  two = count_sep(str, ')', 1);
  if (one > two)
    my_fprintf("Too many ('s.\n");
  else if (two > one)
    my_fprintf("Too many )'s.\n");
  else
    return (str);
  g_error = 1;
  str[0] = '\0';
  return (str);
}

int	i_disagre_this(char *str, int *i, char sep)
{
  while (str[*i] == sep)
    {
      if (str[*i] == sep && str[*i + 1] == sep)
	*i = *i + 2;
      else
	return (SUCCESS);
    }
  return (SUCCESS);
}

char	*my_clear_str(char *str)
{
  int	i;
  int	a;
  char *new;
  int	size;

  i = -1;
  a = 0;
  if (str == NULL ||
      (new = malloc(sizeof(char) * ((my_strlen(str) + 1)))) == NULL)
    return (NULL);
  new[0] = '\0';
  size = my_strlen(str);
  while (++i < size)
    {
      if ((str[i] == ' ' || str[i] == '\t')
	  && (str[i] == ' ' || str[i] == '\t'))
	while (str[i + 1] == ' ' || str[i + 1] == '\t')
	  i++;
      i_disagre_this(str, &i, '\"');
      i_disagre_this(str, &i, '\'');
      new[a++] = str[i];
    }
  new[a] = '\0';
  free(str);
  return (new = count_inibit(new));
}
