/*
** modify_history.c for  in /home/robin/delivery/PSU_2016_42sh
**
** Made by Robin Pronnier
** Login   <robin@epitech.net>
**
** Started on  Sat Apr 22 11:53:34 2017 Robin Pronnier
** Last update Tue Apr 25 10:42:06 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	*mallocat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*new;

  new = NULL;
  i = my_strlen(dest) + my_strlen(src) + 1;
  j = 0;
  if ((new = malloc(sizeof(char *) * (i))) == NULL)
    return (NULL);
  i = 0;
  new[j] = '\0';
  while (dest[j] != '\0')
    {
      new[j] = dest[j];
      ++j;
    }
  while (src[i] != '\0')
    new[j++] = src[i++];
  new[j] = '\0';
  free(dest);
  return (new);
}

char	*modify_with_double(char *s, char *path)
{
  char	*new_s;
  int	i;
  int	j;
  int	c;

  i = -1;
  c = -1;
  j = my_strlen(s) + my_strlen(path) + 1;
  new_s = NULL;
  if ((new_s = malloc(sizeof(char *) * j)) == NULL)
    return (NULL);
  j = -1;
  while (s[++i] != '!')
    new_s[++j] = s[i];
  ++i;
  while (path[++c] != '\0')
    new_s[++j] = path[c];
  while (s[++i] != '\0')
    new_s[++j] = s[i];
  new_s[++j] = '\0';
  free(s);
  free(path);
  return (new_s);
}

char	*modify_with_simple(char *s, char *path)
{
  char	*new_s;
  int	i;
  int	j;
  int	c;

  i = -1;
  c = -1;
  j = my_strlen(s) + my_strlen(path) + 1;
  new_s = NULL;
  if ((new_s = malloc(sizeof(char *) * j)) == NULL)
    return (NULL);
  j = -1;
  while (s[++i] != '!')
    new_s[++j] = s[i];
  while (path[++c] != '\0')
    new_s[++j] = path[c];
  while (s[++i] != '\0' && s[i] != ' ');
  --i;
  while (s[++i] != '\0')
    new_s[++j] = s[i];
  new_s[++j] = '\0';
  free(s);
  free(path);
  return (new_s);
}

char	*last_history_line(char *s, int fd, int *i)
{
  char	*path;
  char	*str;

  path = NULL;
  str = NULL;
  while ((str = get_next_line(fd)) != NULL)
    {
      if (path != NULL)
	free(path);
      path = str;
    }
  if (path == NULL)
    return (NULL);
  *i = *i + my_strlen(path) - 1;
  s = modify_with_double(s, path);
  return (s);
}

char	*take_following(char *s)
{
  int	i;
  int	j;
  char	*following;

  i = -1;
  j = -1;
  following = NULL;
  if ((following = malloc(sizeof(char *) * (my_strlen(s) + 1))) == NULL)
    return (NULL);
  while (s[++i] != '!');
  while (s[++i] != '\0' && s[i] != ' ')
    following[++j] = s[i];
  following[++j] = '\0';
  return (following);
}
