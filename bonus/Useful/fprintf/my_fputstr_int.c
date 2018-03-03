/*
** my_putstr_int.c for  in /home/armin.pc/delivery/CPool_Day04
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Oct  6 18:08:09 2016 Enguerrand Arminjon
** Last update Wed Mar 29 16:22:20 2017 Enguerrand Arminjon
*/

#include "my.h"

int	my_fputstr_int(int *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_fput_nbr(str[i]);
      i++;
      if (str[i] != '\0')
	my_fputchar(' ');
    }
  return (0);
}
