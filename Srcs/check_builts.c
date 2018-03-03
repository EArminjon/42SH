/*
** check_builts.c for  in /home/robin/delivery/PSU_2016_42sh
**
** Made by Robin Pronnier
** Login   <robin@epitech.net>
**
** Started on  Fri May 12 16:33:26 2017 Robin Pronnier
** Last update Tue May 16 16:59:17 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my_macro.h"
#include "shell.h"
#include "ptr.h"
#include "my.h"

int	check_builts(char *s)
{
  int	i;

  i = 0;
  while (i < BUILTIN)
    {
      if (my_strcmp(s, ptrf_builtin[i].name) == 0)
	return (ON);
      ++i;
    }
  return (OFF);
}
