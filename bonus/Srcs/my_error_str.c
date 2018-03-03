/*
** my_error_str.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Fri Apr 14 09:58:46 2017 Enguerrand Arminjon
** Last update Fri Apr 14 10:02:18 2017 Enguerrand Arminjon
*/

#include <unistd.h>

int	my_error_str(char *str, char sep, int canal, int ret)
{
  int	i;

  i = 0;
  while (str != NULL && str[i] != '\0' && str[i] != sep)
    {
      write(canal, &str[i], 1);
      i++;
    }
  return (ret);
}
