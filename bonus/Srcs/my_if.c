/*
** my_if.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue May 16 10:08:27 2017 Enguerrand Arminjon
** Last update Wed May 17 14:46:48 2017 Enguerrand Arminjon
*/

#include "my.h"
#include "shell.h"

int	my_if_strcmp(char **tab, int nb)
{
  if (tab[4] == NULL)
    return (my_puterror("if: Empty if.\n", 2, 1));
  if (nb == 0 && (my_strcmp(tab[1], tab[3]) == 0))
    return (4);
  else if (nb == 1 && (my_strcmp(tab[1], tab[3]) != 0))
    return (4);
  return (-3);
}

int	my_if_center_of_control(char **tab)
{
  int	nb;

  if (tab[1] == NULL)
    return (my_puterror("if: Too few arguments.\n", 2, 1));
  nb = my_str_isnum(tab[1]);
  if (nb == 0 && tab[2] == NULL)
    return (my_puterror("if: Empty if.\n", 2, 1));
  else if ((nb == 1 && tab[2] == NULL) || (tab[3] == NULL))
    return (my_puterror("if: Expression Syntax.\n", 2, 1));
  else if (my_strcmp(tab[2], "==") == 0)
    nb = my_if_strcmp(tab, 0);
  else if (my_strcmp(tab[2], "!=") == 0)
    nb = my_if_strcmp(tab, 1);
  else
    return (2);
  return (nb);
}

int	my_if(t_shell *shell, char **tab)
{
  char	*s;
  int	nb;

  nb = my_if_center_of_control(tab);
  if (nb == 2 || nb == 4)
    {
      s = my_tab_to_str(&tab[nb]);
      nb = 0;
      nb = start_shell(shell, s, nb);
    }
  return (nb == -3 ? 0 : nb);
}
