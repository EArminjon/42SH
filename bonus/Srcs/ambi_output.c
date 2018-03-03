/*
** ambi_output.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Apr 19 15:46:24 2017 Enguerrand Arminjon
** Last update Mon May 15 15:02:11 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

int	ambi_direct(char **t, int i)
{
  if (my_strcmp(t[i], ">") == 0)
    while (t != NULL && t[i] != NULL && t[i] != NULL && t[i][0] != ';')
      {
	if (my_strcmp(t[i], "|") == 0)
	  return (my_puterror("Ambiguous output redirect.\n", 2, 1));
	i++;
      }
  else if (my_strcmp(t[i], "<") == 0)
    while (t != NULL && t[i] != NULL && t[i] != NULL && i > 0)
      {
	if (my_strcmp(t[i], "|") == 0)
	  return (my_puterror("Ambiguous input redirect.\n", 2, 1));
	--i;
      }
  return (0);
}
