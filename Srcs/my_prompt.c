/*
** my_prompt.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sun Apr 30 20:52:56 2017 Enguerrand Arminjon
** Last update Wed May 10 09:59:09 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "my.h"

char	*malloc_this(char *str)
{
  char	*tmp;

  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 3))) == NULL)
    return (NULL);
  tmp[0] = '\0';
  tmp = my_strcat(tmp, str);
  tmp = my_strcat(tmp, "> ");
  return (tmp);
}

void	my_prompt()
{
  int	i;
  char	sep;
  char	*pwd;

  pwd = getcwd(NULL, 0);
  i = my_strlen(pwd);
  sep = 0;
  while (i > 0 && sep != 2)
    {
      if (pwd[i] == '/')
	++sep;
      if (sep != 2)
	--i;
    }
  if (sep == 2)
    ++i;
  my_putstr(&pwd[i]);
  free(g_prompt);
  g_prompt = malloc_this(&pwd[i]);
  my_putstr("> ");
  free(pwd);
}
