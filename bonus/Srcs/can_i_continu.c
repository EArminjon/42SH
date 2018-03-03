/*
** can_i_continu.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Apr 15 18:37:58 2017 Enguerrand Arminjon
** Last update Wed May 17 16:10:48 2017 Enguerrand Arminjon
*/

#include "my.h"
#include "my_macro.h"

int	continu_pipe(int *i, int nb, int *stop)
{
  if (nb != 0)
    {
      *i = *i + 1;
      nb = 0;
      return (nb);
    }
  *stop = STOP;
  return (nb);
}

int	continu_esper(int *i, int nb, int *stop)
{
  if (nb == 0)
    {
      *i = *i + 1;
      return (nb);
    }
  *stop = STOP;
  return (nb);
}

int	can_i_continu_test(char ***my_tab, int *i, int nb, int *stop)
{
  if (my_tab[*i] != NULL)
    {
      if (my_strcmp(my_tab[*i][0], "||") == 0)
	return (continu_pipe(i, nb, stop));
      else if (my_strcmp(my_tab[*i][0], "&&") == 0)
	return (continu_esper(i, nb, stop));
    }
  return (nb);
}

int	can_i_continu(char ***my_tab, int *i, int nb, int *stop)
{
  int	sep;

  nb = can_i_continu_test(my_tab, i, nb, stop);
  sep = 0;
  if (*stop == STOP)
    {
      while (sep < 2 && my_tab[*i] != NULL)
	{
	  while (my_tab[*i] != NULL && sep < 2)
	    {
	      if ((my_strcmp(my_tab[*i][0], "||") == 0) ||
		  (my_strcmp(my_tab[*i][0], "&&") == 0))
		++sep;
	      *i = *i + 1;
	    }
	}
      if (sep >= 2)
	{
	  *stop = 0;
	  nb = 0;
	}
    }
  return (nb);
}
