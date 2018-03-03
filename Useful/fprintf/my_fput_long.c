/*
** my_put_long.c for  in /home/armin.pc/delivery/CPool_Day03
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Wed Oct  5 22:22:36 2016 Enguerrand Arminjon
** Last update Wed Mar 29 16:24:11 2017 Enguerrand Arminjon
*/

#include "my.h"

int	my_fput_long(long int x)
{
  if (x < 0)
    {
      my_fputchar('-');
      x = x * (-1);
    }
  if (x >= 0 && x <= 9)
    {
      my_fputchar(x + 48);
    }
  if (x > 9)
    {
      my_fput_long(x / 10);
      my_fput_long(x % 10);
    }
  return (0);
}
