/*
** info_envp.c for  in /home/armin.pc/delivery/PSU_2016_minishell1
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Jan 17 17:09:43 2017 Enguerrand Arminjon
** Last update Wed May 17 14:19:35 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	*my_getenv(char **ev, char *find)
{
  int	i;
  int	j;
  int	a;
  int	b;
  char	*path;

  i = -1;
  while (ev[++i] != NULL)
    {
      a = 0;
      j = 0;
      while (ev[i][j++] == find[a++])
	if (find[a] == '\0')
	  {
	    b = 0;
	    if ((path = malloc(sizeof(char) * (my_strlen(ev[i]) + 1))) == NULL)
	      return (NULL);
	    path[0] = '\0';
	    while (ev[i][j] != '\0')
	      path[b++] = ev[i][j++];
	    path[b] = '\0';
	    return (path);
	  }
    }
  return (NULL);
}

char	**my_malloc_my_tab(char **my_tab, int row, int col)
{
  int	i;

  i = 0;
  if ((my_tab = malloc(sizeof(char *) * (row + 1))) == NULL)
    return (NULL);
  while (i < row)
    {
      if ((my_tab[i] = malloc(sizeof(char) * (col + 2))) == NULL)
	return (NULL);
      my_tab[i][0] = '\0';
      ++i;
    }
  my_tab[i] = NULL;
  return (my_tab);
}

char	**bin_path_my_tab(char *str, char **my_tab)
{
  int	i;
  int	a;
  int	b;

  a = 1;
  b = -1;
  while (str != NULL && str[++b] != '\0')
    if (str[b] == ':' || str[b] == '\0')
      a++;
  if (str == NULL ||
      ((my_tab = my_malloc_my_tab(my_tab, a, my_strlen(str))) == NULL))
    return (NULL);
  a = 0;
  i = -1;
  while (++i < my_strlen(str))
    {
      b = 0;
      while (str[i] != ':' && str[i] != '\0')
	my_tab[a][b++] = str[i++];
      my_tab[a][b] = '/';
      my_tab[a++][b + 1] = '\0';
    }
  my_tab[a] = NULL;
  return (my_tab);
}
