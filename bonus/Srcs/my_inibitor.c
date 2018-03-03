/*
** my_inibitor.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Apr 18 17:04:13 2017 Enguerrand Arminjon
** Last update Tue May  9 09:06:22 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	*my_copy_nstr(char *str, int n)
{
  int	i;
  char	*new;

  i = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  new[0] = '\0';
  while (i < n)
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}

char	*the_tricks(char *new, char *s, char *str, int j)
{
  int	a;
  int	i;

  a = 0;
  i = 0;
  while (i < j)
    new[a++] = str[i++];
  i = 0;
  new[a++] = ' ';
  while (s[i] != '\0')
    new[a++] = s[i++];
  i = j + 1;
  while (str[i] != '\0')
    new[a++] = str[i++];
  new[a] = '\0';
  free(str);
  free(s);
  return (new);
}

char	*the_inibitor_prompt(char *str, int j)
{
  char	*s;
  char	*new;
  int	size;

  my_putstr("? ");
  if ((s = get_next_line(0)) == NULL)
    {
      str[j] = '\0';
      return (str);
    }
  size = my_strlen(str) + my_strlen(s) + 1;
  if ((new = malloc(sizeof(char) * (size))) == NULL)
    return (NULL);
  new[0] = '\0';
  return (the_tricks(new, s, str, j));
}

char	*my_inibitor(char *str, int pos)
{
  char	*new;

  if (pos == (my_strlen(str) - 1))
    return (str = the_inibitor_prompt(str, pos));
  else
    {
      if ((new = my_copy_nstr(str, pos)) == NULL)
	return (NULL);
      new = my_strcat(new, &str[pos + 1]);
      free(str);
    }
  return (new);
}

char	*check_inibitor(char *str)
{
  int	i;

  if (str == NULL || ((str = my_clear_str(str)) == NULL))
    return (str);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\\')
	{
	  if ((str = my_inibitor(str, i)) == NULL)
	    return (NULL);
	  i = -1;
	}
      i++;
    }
  return (str);
}
