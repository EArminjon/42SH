/*
** fix_path.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Apr 26 08:57:33 2017 Enguerrand Arminjon
** Last update Wed Apr 26 08:58:06 2017 Enguerrand Arminjon
*/

#include "my.h"

char	*fix_path(char *new, char *cmds, char *path)
{
  int	size;

  size = (my_strlen(cmds) + my_strlen(path) + 1);
  if ((new = malloc(sizeof(char) * (size))) == NULL)
    return (NULL);
  new[0] = '\0';
  new = my_strcat(new, path);
  new = my_strcat(new, cmds);
  return (new);
}
