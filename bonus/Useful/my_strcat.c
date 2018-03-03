/*
** my_strcat.c for  in /home/armin.pc/delivery/PSU_2016_minishell1/srcs
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Jan 10 09:27:04 2017 Enguerrand Arminjon
** Last update Wed May 10 09:13:04 2017 Enguerrand Arminjon
*/

#include <stdlib.h>

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (dest[i] != '\0')
    i = i + 1;
  while (src[n] != '\0')
    {
      dest[i] = src[n];
      n = n + 1;
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
