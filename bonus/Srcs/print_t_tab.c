/*
** print_t_my_tab.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Apr 15 11:48:58 2017 Enguerrand Arminjon
** Last update Fri May 19 10:30:45 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

int	print_t_my_tab(char ***my_tab)
{
  int	i;

  i = 0;
  while (my_tab != NULL && my_tab[i] != NULL)
    {
      my_printf("TAB[%i] : \n", i);
      print_my_tab(my_tab[i]);
      my_putchar('\n');
      i++;
    }
  return (0);
}
