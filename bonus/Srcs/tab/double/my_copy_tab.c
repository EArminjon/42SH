/*
** my_copy_my_tab.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu Feb 23 13:33:10 2017 Enguerrand Arminjon
** Last update Mon May 15 13:39:20 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

int	count_row(char **my_tab)
{
  int	row;

  row = 0;
  if (my_tab == NULL)
    return (0);
  while (my_tab[row] != NULL)
    row++;
  return (row);
}

int	count_col(char **my_tab)
{
  int	max;
  int	i;
  int	j;

  i = 0;
  max = 0;
  while (my_tab[i] != NULL)
    {
      j = 0;
      while (my_tab[i][j] != '\0')
	j++;
      if (j > max)
	max = j;
      i++;
    }
  return (max);
}

char	**my_malloc_copy_my_tab(char **copy, char **my_tab)
{
  int	col;
  int	row;
  int	i;

  row = count_row(my_tab);
  col = count_col(my_tab);
  i = 0;
  if ((copy = malloc(sizeof(char *) * (row + 1))) == NULL)
    return (NULL);
  copy[0] = '\0';
  while (i < row)
    {
      if ((copy[i] = malloc(sizeof(char) * (col + 1))) == NULL)
	return (NULL);
      copy[i][0] = '\0';
      ++i;
    }
  copy[i] = NULL;
  return (copy);
}

char	**my_copy_my_tab(char **copy, char **my_tab)
{
  int	i;

  if (my_tab == NULL || (copy = my_malloc_copy_my_tab(copy, my_tab)) == NULL)
    return (NULL);
  i = 0;
  while (my_tab != NULL && my_tab[i] != NULL)
    {
      copy[i] = my_strcat(copy[i], my_tab[i]);
      ++i;
    }
  copy[i] = NULL;
  return (copy);
}
