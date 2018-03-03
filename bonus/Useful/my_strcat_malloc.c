/*
** my_strcat.c for  in /home/armin.pc/delivery/PSU_2016_minishell1/srcs
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Jan 10 09:27:04 2017 Enguerrand Arminjon
** Last update Thu May 18 10:29:33 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	*the_malloc(char *dest, char *str)
{
  int	size;
  char	*new;

  size = my_strlen(dest) + my_strlen(str) + 1;
  if (str == NULL ||
      ((new = malloc(sizeof(char) * (size))) == NULL))
    return (NULL);
  new[0] = '\0';
  return (new);
}

char	*my_strcat_malloc_free(char *dest, char *src)
{
  char	*new;
  int	i;
  int	a;

  i = 0;
  a = 0;
  if (src != NULL && (new = the_malloc(dest, src)) == NULL)
    return (NULL);
  while (dest != NULL && dest[i] != '\0')
    new[a++] = dest[i++];
  i = 0;
  while (src[i] != '\0')
    new[a++] = src[i++];
  new[a] = '\0';
  free(dest);
  return (new);
}

char	*my_strcat_malloc(char *dest, char *src)
{
  char	*new;
  int	i;
  int	a;

  i = 0;
  a = 0;
  if ((new = the_malloc(dest, src)) == NULL)
    return (NULL);
  while (dest != NULL && dest[i] != '\0')
    new[a++] = dest[i++];
  i = 0;
  while (src != NULL && src[i] != '\0')
    new[a++] = src[i++];
  new[a] = '\0';
  return (new);
}
