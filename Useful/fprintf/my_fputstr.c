/*
** my_putstr.c for  in /home/armin.pc/delivery/CPool_Day04
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Oct  6 18:08:09 2016 Enguerrand Arminjon
** Last update Wed Mar 29 16:21:55 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include "my.h"

int	my_fputstr(char *str)
{
  if (str == NULL)
    return (0);
  write(2, str, my_strlen(str));
  return (0);
}
