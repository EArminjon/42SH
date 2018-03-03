/*
** my_pipe.c for  in /home/armin.pc/delivery/PSU_2016_minishell2
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Mar 29 16:08:36 2017 Enguerrand Arminjon
** Last update Mon May 15 13:12:12 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my_macro.h"
#include "shell.h"
#include "my.h"

int	my_pipe2(int fdpipe[2], int i)
{
  if ((dup2(fdpipe[i], i)) == -1)
    return (-1);
  close(fdpipe[0]);
  close(fdpipe[1]);
  return (SUCCESS);
}

int	my_pipe_son(t_shell *shell, char **my_tab, int fdpipe[2], int f)
{
  while (my_strcmp(my_tab[f], "|") != SUCCESS)
    f++;
  my_tab[f] = NULL;
  if ((my_pipe2(fdpipe, 1)) == -1)
    return (-1);
  if ((f = my_builtin(shell, &my_tab)) == -2)
    if ((f = my_execve(shell, my_tab)) == 1)
      my_fprintf("%s: Command not found.\n", my_tab[0]);
  if (f == -2)
    f = 1;
  return (f);
}

int	my_pipe(t_shell *shell, char **my_tab)
{
  int	fdpipe[2];
  int	f;

  if ((pipe(fdpipe)) == -1)
    return (-1);
  if ((f = fork()) == -1)
    return (-1);
  if (f == 0)
    exit(my_pipe_son(shell, my_tab, fdpipe, f));
  else
    {
      usleep(5000);
      if ((my_pipe2(fdpipe, 0)) == -1)
	return (-1);
      my_tab = modif_av(my_tab);
    }
  return (SUCCESS);
}

int	pipe_exist(char **av)
{
  int	i;

  i = 0;
  while (av[i])
    {
      if (my_strcmp(av[i], "|") == SUCCESS)
	return (FAIL);
      ++i;
    }
  return (SUCCESS);
}

char	**prepair_pipe(t_shell *shell, char **my_tab, int *nb)
{
  int	ret;
  char	**new;

  new = NULL;
  if ((pipe_exist(my_tab)) != 0)
    {
      new = my_tab;
      while ((pipe_exist(new)) != 0)
	{
	  if ((ret = my_pipe(shell, new)) == -1)
	    return (NULL);
	  if (ret > 0)
	    *nb = ret;
	}
      my_tab = new;
    }
  return (my_tab);
}
