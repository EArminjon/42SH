/*
** my_printf2.c for  in /home/armin.pc/delivery/PSU_2016_my_printf
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Wed Nov 16 08:46:07 2016 Enguerrand Arminjon
** Last update Wed Mar 29 16:28:56 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

int		my_fsize(int nb)
{
  int		size;

  size = 0;
  while (nb > 0)
    {
      nb = nb / 10;
      size++;
    }
  return (size);
}

void		my_fbinari(int nb)
{
  char		*array;
  int		res;
  int		i;

  i = 0;
  res = 0;
  array = malloc(sizeof(char) * my_fsize(nb) + 2);
  while (nb != 0)
    {
      res = nb % 2;
      if (res <= 2)
	res = res + '0';
      array[i] = res;
      nb = nb / 2;
      i++;
    }
  my_fputstr(my_revstr(array));
}

void		my_fhexadecimal(long int nb)
{
  char		*array;
  int		res;
  int		i;

  i = 0;
  res = 0;
  array = malloc(sizeof(char) * my_fsize(nb) + 2);
  if (nb == 0)
    my_fputchar('0');
  while (nb != 0)
    {
      res = nb % 16;
      if (res <= 9)
	res = res + '0';
      else
	res = res + 55;
      array[i] = res;
      nb = nb / 16;
      i++;
    }
  my_fputstr(my_revstr(array));
}

void		my_fhexadecimal_2(long int nb)
{
  char		*array;
  int		res;
  int		i;

  i = 0;
  res = 0;
  array = malloc(sizeof(char) * my_fsize(nb) + 2);
  if (nb == 0)
    my_fputchar('0');
  while (nb != 0)
    {
      res = nb % 16;
      if (res <= 9)
	res = res + '0';
      else
	res = res + 87;
      array[i] = res;
      nb = nb / 16;
      i = i + 1;
    }
  my_fputstr(my_revstr(array));
}

void		fthe_else_print(int *a)
{
  my_fputchar('%');
  *a = *a - 1;
}
