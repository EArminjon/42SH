/*
** 42shrc.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Apr 29 13:53:45 2017 Enguerrand Arminjon
** Last update Mon May  1 10:59:48 2017 Enguerrand Arminjon
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
  char	**my_tab;
  char	*s;
  int	fd;
  int	i;

  g_error = 0;
  if ((fd = open(name, O_RDONLY, 0644)) == -1)
    return (1);
  while ((s = get_next_line(fd)) != NULL)
    {
      i = 0;
      my_tab = NULL;
      if (((s = my_clear_str(s)) == NULL)
	  || ((my_tab = my_put_in_my_tab(s, my_tab, &i)) == NULL))
	return (1);
      edit_my_shell(shell, my_tab);
      free_my_tab(my_tab);
      free(s);
    }
  if (g_error != 0)
    my_puterror("Please check the .42shrc !\n", 2, 0);
  return (0);
}
