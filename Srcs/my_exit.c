/*
** my_exit.c for  in /home/armin.pc/delivery/PSU_2016_minishell2
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Mar 25 10:03:36 2017 Enguerrand Arminjon
** Last update Mon May 15 13:07:44 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include "my_macro.h"
#include "shell.h"
#include "my.h"

int	my_exit(t_shell *shell, char **t)
{
  if (t[1] == NULL)
    {
      if ((isatty(0)) == 1)
	my_putstr("exit\n");
    }
  else
    {
      if (((my_str_isnum(t[1])) == 0) || ((my_str_isnum(&t[1][1])) == 0))
	{
	  shell->exit = 1;
	  if ((isatty(0)) == 1)
	    my_putstr("exit\n");
	  return (my_getnbr(t[1]) % 256);
	}
      else if ((t[1][0] >= '0' && t[1][0] <= '9')
	       || t[1][0] == '-' || t[1][0] == '+')
	my_fprintf("%s: Badly formed number.\n", t[0]);
      else
	my_fprintf("%s: Expression Syntax.\n", t[0]);
      return (2);
    }
  shell->exit = 1;
  return (SUCCESS);
}
