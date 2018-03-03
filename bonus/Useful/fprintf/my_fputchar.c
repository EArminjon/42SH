/*
** my_putchar.c for  in /home/armin.pc/delivery/CPool_Day07
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Tue Oct 11 10:31:47 2016 Enguerrand Arminjon
** Last update Wed Mar 29 16:23:49 2017 Enguerrand Arminjon
*/

#include <unistd.h>

void	my_fputchar(char c)
{
  write(2, &c, 1);
}
