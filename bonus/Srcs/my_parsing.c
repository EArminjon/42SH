/*
** my_parsing.c for  in /home/armin.pc/delivery/PSU_2016_minishell2
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Mar 27 15:17:57 2017 Enguerrand Arminjon
** Last update Tue May 16 14:07:40 2017 Enguerrand Arminjon
*/

#include "my.h"

void	if_parser(char *str, int *i, char *copy, int *a)
{
  copy[*a] = str[*i];
  copy[*a + 1] = ' ';
  *i = *i + 1;
  *a = *a + 2;
}

void	boost_parser(char *str, int *i, char *copy, int *a)
{
  char	sep;
  int	size;

  size = my_strlen(str);
  if (*i > 0 && (str[*i - 1] != ' ' && str[*i - 1] != '\t'))
    {
      copy[*a] = ' ';
      *a = *a + 1;
    }
  sep = str[*i];
  while (*i < size && (str[*i] == sep))
    {
      copy[*a] = str[*i];
      *i = *i + 1;
      *a = *a + 1;
      if (str[*i] == sep)
	if_parser(str, i, copy, a);
      else if (str[*i] != ' ' && str[*i] != '\t')
	{
	  copy[*a] = ' ';
	  *a = *a + 1;
	}
    }
}

char	*my_parser(char *str, char *copy, int *i)
{
  int	a;

  a = 0;
  while (str[*i] == ';' || str[*i] == ' ' || str[*i] == '\t')
    *i = *i + 1;
  while (str[*i] != ';' && str[*i] != '\0')
    {
      if (str[*i] == '|' || str[*i] == '<' || str[*i] == '>' || str[*i] == '&'
	  || str[*i] == '(' || str[*i] == ')')
	boost_parser(str, i, copy, &a);
      else
	{
	  copy[a] = str[*i];
	  a = a + 1;
	  *i = *i + 1;
	}
    }
  copy[a] = '\0';
  return (copy);
}
