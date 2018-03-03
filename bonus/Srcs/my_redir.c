/*
** my_redir.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Apr 26 08:59:39 2017 Enguerrand Arminjon
** Last update Mon May 15 13:12:56 2017 Enguerrand Arminjon
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_macro.h"
#include "unistd.h"

int	my_redir(char *file, int *fd, mode_t mode, int old)
{
  if (((*fd = open(file, mode, 0644)) == -1)
      || ((dup2(*fd, old)) == -1))
    return (OPEN_FAIL);
  return (SUCCESS);
}
