/*
** my_key.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri May 12 12:08:18 2017 Enguerrand Arminjon
** Last update Wed May 17 12:18:27 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include <term.h>
#include "my_macro.h"
#include "shell.h"
#include "my.h"

char		*get_the_name(char **envp)
{
  char		*name;

  name = NULL;
  if (envp == NULL || ((name = my_getenv(envp, "TERM=")) == NULL))
    name = my_strcat_malloc(NULL, "xterm");
  return (name);
}

t_keys		*my_keys(char **envp)
{
  t_keys	*keys;
  char		*name;
  int		err;
  int		error;

  error = 0;
  if (((name = get_the_name(envp)) == NULL) ||
      (((keys = malloc(sizeof(*keys))) == NULL) ||
       ((setupterm(name, 1, &err)) == -1)))
    error = FAIL;
  else if (((keys->left = tigetstr("kcub1")) == NULL) ||
	   ((keys->right = tigetstr("kcuf1")) == NULL) ||
	   ((keys->up = tigetstr("kcuu1")) == NULL) ||
	   ((keys->down = tigetstr("kcud1")) == NULL))
    error = 1;
  if (error != SUCCESS)
    my_puterror("ERROR: my_key.c\n", 2, ERROR);
  free(name);
  return (error == SUCCESS ? keys : NULL);
}
