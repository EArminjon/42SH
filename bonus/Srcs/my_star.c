/*
** my_star.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Apr 14 10:49:12 2017 Enguerrand Arminjon
** Last update Mon May 15 13:14:35 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include <dirent.h>
#include "my.h"

char		*find_path_my_tab(char *str)
{
  int		i;

  i = 0;
  while (str != NULL && str[i] != '\0' && str[i] != '*')
    i++;
  str[i] = '\0';
  return (str);
}

char	**my_put_in_my_tab_star(char *str, char **t, char *path, int *size)
{
  char		**new;
  int		str_len;
  int		j;

  j = 0;
  if ((new = malloc(sizeof(char *) * (*size + 2))) == NULL)
    return (NULL);
  while (j < *size)
    {
      new[j] = t[j];
      j++;
    }
  str_len = my_strlen(str) + my_strlen(path) + 1;
  if ((new[j] = malloc(sizeof(char) * (str_len))) == NULL)
    return (NULL);
  new[j][0] = '\0';
  new[j] = my_strcat(new[j], path);
  new[j] = my_strcat(new[j], str);
  new[j + 1] = NULL;
  *size = *size + 1;
  free(t);
  return (new);
}

char		**my_fusion(char **my_tab, char **tmp, int size, int pos)
{
  int		i;
  int		j;
  int		a;
  char		**new;

  i = 0;
  a = 0;
  j = 0;
  size = size + count_row(my_tab);
  if ((new = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  while (my_tab[i] != NULL && a < pos)
    new[a++] = my_tab[i++];
  while (tmp[j] != NULL)
    new[a++] = tmp[j++];
  if (my_tab[i] != NULL)
    {
      i = i + 1;
      while (my_tab[i] != NULL)
	new[a++] = my_tab[i++];
    }
  new[a] = NULL;
  return (new);
}

DIR		*my_dir(char *path, char **my_tab)
{
  DIR		*dir;

  dir = NULL;
  if (path != NULL && path[0] != '\0')
    dir = opendir(path);
  else
    dir = opendir(".");
  if (dir == NULL)
    {
      my_fprintf("%s: No match.\n", my_tab[0]);
      return (NULL);
    }
  return (dir);
}

char		**my_star(char **tb, int i, int size, char **t)
{
  DIR		*dir;
  struct dirent	*entry;
  char		*path;
  char		**new;
  char		*copy;

  copy = malloc(sizeof(char) * (my_strlen(tb[i]) + 1));
  copy[0] = '\0';
  copy = my_strcat(copy, tb[i]);
  path = find_path_my_tab(tb[i]);
  if ((dir = my_dir(path, tb)) == NULL)
    return (NULL);
  while ((entry = readdir(dir)) != NULL)
    if (entry != NULL && entry->d_name[0] != '.')
      t = my_put_in_my_tab_star(entry->d_name, t, path, &size);
  closedir(dir);
  t = remove_bad_line(t, copy);
  if (t == NULL || t[0] == NULL)
    my_fprintf("%s: No match.\n", tb[0]);
  if (t == NULL || t[0] == NULL || (new = my_fusion(tb, t, size, i)) == NULL)
    return (NULL);
  free(tb);
  free(t);
  return (new);
}
