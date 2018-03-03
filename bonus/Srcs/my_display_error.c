/*
** my_display_error.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Apr 12 14:40:08 2017 Enguerrand Arminjon
** Last update Fri Apr 28 13:17:44 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "my.h"

int	my_display_error(int *fd, char *file)
{
  DIR	*dir;

  if (*fd == -1 && (access(file, F_OK)) == -1)
    my_fprintf("%s: No such file or directory.\n", file);
  else if (*fd == -1 && ((dir = opendir(file)) == NULL))
    my_fprintf("%s: Permission denied.\n", file);
  else if (*fd == -1 && dir != NULL)
    {
      closedir(dir);
      my_fprintf("%s: Is a directory.\n", file);
    }
  else
    return (0);
  *fd = -3;
  return (-3);
}
