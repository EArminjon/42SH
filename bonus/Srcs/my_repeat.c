/*
** my_repeat.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue May 16 12:00:19 2017 Enguerrand Arminjon
** Last update Tue May 16 12:07:41 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"

int	my_repeat_center_of_control(t_shell *shell, char **tab)
{
  char	*s;
  int	nb;
  int	ret;

  ret = 0;
  nb = 0;
  if (tab[1] == NULL || tab[2] == NULL)
    return (my_puterror("repeat: Too few arguments.\n", 2, 1));
  else if (my_str_isnum(tab[1]) == 1)
    return (my_puterror("repeat: Badly formed number.\n", 2, 1));
  else
    {
      nb = my_getnbr(tab[1]);
      while (nb > 0)
	{
	  s = my_tab_to_str(&tab[2]);
	  ret = start_shell(shell, s, nb);
	  --nb;
	}
    }
  return (ret);
}

int	my_repeat(t_shell *shell, char **tab)
{
  int	nb;

  nb = my_repeat_center_of_control(shell, tab);
  return (nb);
}
