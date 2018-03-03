/*
** useful_history.c for  in /home/robin/delivery/PSU_2016_42sh
**
** Made by Robin Pronnier
** Login   <robin@epitech.net>
**
** Started on  Sat Apr 22 11:59:06 2017 Robin Pronnier
** Last update Mon May 15 12:43:34 2017 Enguerrand Arminjon
*/

#include "my.h"
#include "my_macro.h"

int	my_strcmspace(char *str, char *bis)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && bis[i] != '\0'
	 && bis[i] != ' ' && str[i] == bis[i])
    ++i;
  if (str[i] == '\0')
    return (ON);
  return (OFF);
}

int	check_hist(char *s)
{
  int	i;

  i = -1;
  while (s[++i] != '\0')
    if (s[i] == '!' && s[i + 1] != '\0' && s[i + 1] != ' ')
      return (OFF);
  return (ON);
}

void	find_history_line_loop(char *find, char *str, char **path)
{
  if (my_strcmspace(find, str) == ON)
    {
      if (*path != NULL)
	free(*path);
      *path = str;
    }
  else
    free(str);
}
