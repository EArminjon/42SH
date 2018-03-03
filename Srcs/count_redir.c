/*
** count_redir.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Apr 15 18:34:32 2017 Enguerrand Arminjon
** Last update Tue May 16 14:32:17 2017 Enguerrand Arminjon
*/

#include "my_macro.h"
#include "my.h"

int		my_reset(int *left, int *right, int *d_left, int *d_right)
{
  *left = 0;
  *right = 0;
  *d_left = 0;
  *d_right = 0;
  return (SUCCESS);
}

int		count_redir(char *str, int reset)
{
  static int	left = 0;
  static int	right = 0;
  static int	d_left = 0;
  static int	d_right = 0;

  if (reset == 1)
    return (my_reset(&left, &right, &d_left, &d_right));
  if (my_strcmp(str, "<") == 0)
    ++left;
  else if (my_strcmp(str, ">") == 0)
    ++right;
  else if (my_strcmp(str, "<<") == 0)
    ++d_left;
  else if (my_strcmp(str, ">>") == 0)
    ++d_right;
  if (left > 1 || d_left > 1)
    return (my_puterror("Ambiguous input redirect\n", 2, FAIL));
  else if (right > 1 || d_right > 1)
    return (my_puterror("Ambiguous output redirect\n", 2, FAIL));
  return (SUCCESS);
}
