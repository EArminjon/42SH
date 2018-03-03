/*
** my_echo.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Apr 12 09:29:58 2017 Enguerrand Arminjon
** Last update Mon May 15 13:05:12 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my_macro.h"
#include "shell.h"
#include "my.h"

void	print_the_echo(char **my_tab, int *i)
{
  if (my_tab[*i + 1] != NULL)
    {
      my_printf("%s ", my_tab[*i]);
      *i = *i + 1;
    }
  else
    {
      my_printf("%s", my_tab[*i]);
      *i = *i + 1;
    }
}

int	my_echo(t_shell *shell, char **my_tab)
{
  int	i;

  i = 1;
  (void) shell;
  if (my_tab[1] == NULL)
    my_putchar('\n');
  else if (my_strcmp(my_tab[1], "-n") != SUCCESS)
    {
      while (my_tab[i] != NULL)
	print_the_echo(my_tab, &i);
      my_putchar('\n');
    }
  else
    {
      i = 2;
      while (my_tab[i] != NULL)
	print_the_echo(my_tab, &i);
    }
  return (SUCCESS);
}
