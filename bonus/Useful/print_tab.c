/*
** print_my_tab.c for  in /home/armin.pc/delivery/PSU_2016_minishell1
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Jan 10 09:11:33 2017 Enguerrand Arminjon
** Last update Mon May 15 13:21:59 2017 Enguerrand Arminjon
*/

#include "my_macro.h"
#include "my.h"

int	print_my_tab(char **my_tab)
{
  int	i;

  i = -1;
  if (my_tab == NULL)
    return (SUCCESS);
  while (my_tab[++i] != NULL)
    {
      my_putstr(my_tab[i]);
      my_putchar('\n');
    }
  return (SUCCESS);
}
