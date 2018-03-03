/*
** add_an_alias.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sun Apr 30 15:04:01 2017 Enguerrand Arminjon
** Last update Sat May 13 09:19:25 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"

char	*build_an_alias(char **my_tab)
{
  int	i;
  int	j;
  int	a;
  int	size;
  char	*alias;

  a = 0;
  i = 0;
  size = 0;
  while (my_tab != NULL && my_tab[++i] != NULL)
    size = size + my_strlen(my_tab[i]);
  if ((alias = malloc(sizeof(char) * (2 * size + 1))) == NULL)
    return (NULL);
  alias[0] = '\0';
  i = 0;
  while (my_tab != NULL && my_tab[++i])
    {
      j = 0;
      while (my_tab[i][j] != '\0')
	alias[a++] = my_tab[i][j++];
      if (my_tab[i + 1] != NULL)
	alias[a++] = ' ';
    }
  alias[a] = '\0';
  return (alias);
}

char	**add_an_alias(t_shell *shell, char **my_tab)
{
  int	i;
  int	j;
  int	nb;
  int	size;
  char	**new;
  char	*alias;

  i = 0;
  j = 0;
  nb = 1;
  size = count_row(shell->alias);
  if (((alias = build_an_alias(my_tab)) == NULL)
      || (new = malloc(sizeof(char *) * (size + 2))) == NULL)
    return (NULL);
  while (shell->alias != NULL && shell->alias[i] != NULL
	 && ((nb = my_strcmp_2(shell->alias[i], my_tab[1], ' ') != 0)))
    new[j++] = shell->alias[i++];
  new[j++] = alias;
  if (nb == 0)
    while (shell->alias != NULL && shell->alias[++i] != NULL)
      new[j++] = shell->alias[i];
  new[j] = NULL;
  free(shell->alias);
  return (new);
}

int	add_or_display_alias(t_shell *shell, char **t)
{
  int	nb;

  nb = 0;
  if (t[1] == NULL)
    print_my_tab(shell->alias);
  else if (t[1] != NULL && t[2] == NULL)
    return (my_where_alias(shell, t, 1));
  else
    {
      if ((t[1] != NULL && my_strcmp(t[1], "alias") == 0) && t[2] != NULL)
	return (my_puterror("alias: Too dangerous to alias that.\n", 2, 1));
      if ((shell->alias = add_an_alias(shell, t)) == NULL)
	return (84);
    }
  return (nb);
}
