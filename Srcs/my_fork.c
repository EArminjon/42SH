/*
** fork.c for  in /home/armin.pc/delivery/PSU_2016_minishell2
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Mar 24 11:13:30 2017 Enguerrand Arminjon
** Last update Tue May 16 15:16:26 2017 Enguerrand Arminjon
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_macro.h"
#include "shell.h"
#include "my.h"

int	manage_return(int status)
{
  int	nb;

  nb = WEXITSTATUS(status);
  if (WIFSIGNALED(status))
    {
      if (status == SEGFAULT || status == 11)
	nb = my_puterror("Segmentation fault", 2, SEGFAULT);
      else if (status == ABORT || status == 8)
	nb = my_puterror("Floating exception", 2, ABORT);
      else if (status == FLOAT || status == 9)
	nb = my_puterror("Abort", 2, FLOAT);
      if (WCOREDUMP(status))
	my_fputstr(" (core dumped)");
      my_fputchar('\n');
      return (nb);
    }
  return (nb == FAIL ? -2 : nb);
}

int	my_dad()
{
  int	nb;
  int	status;

  wait(&status);
  nb = manage_return(status);
  return (nb);
}

void	my_son(char **my_tab, char **my_envp, char *str)
{
  execve(str, my_tab, my_envp);
  my_fprintf("%s: Exec format error. Binary file not executable.\n", str);
  exit(FAIL);
}

int	my_fork(t_shell *shell, char **my_tab, char *str)
{
  int	f;
  int	nb;

  nb = 1;
  f = fork();
  if (f == -1)
    return (ERROR);
  else if (f != 0)
    {
      nb = my_dad();
    }
  else if (f == 0)
    {
      my_son(my_tab, shell->envp, str);
    }
  return (nb);
}
