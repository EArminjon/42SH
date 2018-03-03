/*
** my_42shrc.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh/bonus
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu Jun  8 21:04:17 2017 Enguerrand Arminjon
** Last update Thu Jun  8 21:04:25 2017 Enguerrand Arminjon
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "shell.h"

char	*clear_str(char *str)
{
  int	i;
  int	a;
  char	*new;

  if (str == NULL
      || (new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  new[0] = '\0';
  i = -1;
  a = 0;
  while (str[++i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while (str[i] == ' ' || str[i] == '\t')
	    ++i;
	  if (a > 0)
	    new[a++] = ' ';
	}
      new[a++] = str[i];
    }
  new[a] = '\0';
  free(str);
  return (new);
}

int	my_42shrc(t_shell *shell, char *name)
{
  char	*s;
  int	nb;
  int	fd;

  nb = 0;
  g_error = 0;
  if ((fd = open(name, O_RDONLY, 0644)) == -1)
    return (1);
  while ((s = get_next_line(fd)) != NULL)
    {
      if ((s = my_clear_str(s)) == NULL)
	return (1);
      if (s != NULL && s[0] != '\0' && s[0] != '/' && s[1] != '/')
	nb = start_shell(shell, s, nb);
      else if (s != NULL)
	free(s);
    }
  if (g_error != 0)
    my_puterror("Please check the .42shrc !\n", 2, 0);
  return (nb);
}
