/*
** my_nb_argu.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Wed Apr 12 14:37:38 2017 Enguerrand Arminjon
** Last update Wed Apr 12 14:39:45 2017 Enguerrand Arminjon
*/

#include "my.h"

int	my_nb_argu(char *str)
{
  int	i;
  int	argu;
  int	max;

  i = -1;
  argu = 1;
  max = my_strlen(str);
  while (++i < max)
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
	    i++;
	  argu++;
	}
    }
  return (argu);
}
