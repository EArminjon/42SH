/*
** my_put_short.c for  in /home/armin.pc/delivery/CPool_Day03
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Wed Oct  5 22:22:36 2016 Enguerrand Arminjon
** Last update Wed Mar 29 16:23:25 2017 Enguerrand Arminjon
*/

#include "my.h"

int	my_fput_short(short x)
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
      my_fput_short(x / 10);
      my_fput_short(x % 10);
    }
  return (0);
}
