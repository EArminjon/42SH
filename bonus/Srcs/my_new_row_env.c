/*
** my_new_row_env.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Apr 15 10:57:00 2017 Enguerrand Arminjon
** Last update Sat Apr 15 15:22:41 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"

char	*my_new_row_env(char **my_tab)
{
  int	size;
  char	*new_row;

  size = (my_strlen(my_tab[1]) + my_strlen(my_tab[2]) + 2);
  if ((new_row = malloc(sizeof(char) * (size))) == NULL)
    return (NULL);
  new_row[0] = '\0';
  new_row = my_strcat(new_row, my_tab[1]);
  new_row = my_strcat(new_row, "=");
  if (my_tab[2] != NULL)
    new_row = my_strcat(new_row, my_tab[2]);
  return (new_row);
}
