/*
** my_exec.c for  in /home/BlueLemon/delivery/PSU_2016_42sh
**
** Made by Porcheret Thomas
** Login   <BlueLemon@epitech.net>
**
** Started on  Fri May 12 15:52:01 2017 Porcheret Thomas
** Last update Fri May 19 11:25:15 2017 Enguerrand Arminjon
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include "my.h"
#include "my_macro.h"

int	my_execve_before(t_shell *shell, char **t, char *str)
{
  int	i;
  int	nb;

  i = 0;
  if ((my_strncmp(t[0], "./", 2) != SUCCESS)
      && my_strncmp(t[0], "../", 1) != 0  && my_strncmp(t[0], "/", 1) != 0)
    {
      while (shell != NULL && shell->bin_path != NULL
	     && shell->bin_path[i] != NULL)
	{
	  if ((my_strcmp(shell->bin_path[i], "//") != 0)
	      && (str = fix_path(str, t[0], shell->bin_path[i])) == NULL)
	    return (ERROR);
	  if (str != NULL && access(str, F_OK) == 0)
	    {
	      nb = check_cmds_perms(str, shell, t);
	      free(str);
	      return (nb);
	    }
	  i++;
	  free(str);
	}
    }
  return (check_cmds_perms(t[0], shell, t));
}

int	my_execve(t_shell *shell, char **my_tab)
{
  char	*str;
  int	nb;

  str = NULL;
  nb = my_execve_before(shell, my_tab, str);
  return (nb);
}

int	the_tests(t_shell *shell, t_chained *chain, int *tmp, int *i)
{
  int	status;
  int	ret;

  if ((*tmp = my_builtin(shell, &chain->my_tab[*i])) == -2)
    if ((*tmp = my_execve(shell, chain->my_tab[*i])) == FAIL)
      my_fprintf("%s: Command not found.\n", chain->my_tab[*i][0]);
  if (*tmp == -2)
    *tmp = 1;
  status = 0;
  ret = 0;
  while (--shell->waits + 1 > 0)
    {
      wait(&status);
      if (WEXITSTATUS(status) > 0)
	ret = WEXITSTATUS(status);
    }
  return (*tmp != 0 ? *tmp : ret);
}

int	series_of_test(t_shell *shell, t_chained *c, int *fd, int stop)
{
  int	tmp;
  int	nb;
  int	i;

  i = 0;
  nb = 0;
  tmp = 0;
  while (stop != STOP && c != NULL && c->my_tab != NULL
	 && c->my_tab[i] != NULL)
    {
      set_last_cmds(shell, c, i);
      if (((c->my_tab[i] = my_item_my_tab(c->my_tab[i], shell)) == NULL)
	  || ((*fd = do_redirection(c->my_tab[i])) == -3) ||
	  ((c->my_tab[i] = prepair_pipe(shell, c->my_tab[i], &tmp)) == NULL))
	return (FAIL);
      if (tmp > nb)
	nb = tmp;
      tmp = the_tests(shell, c, &tmp, &i);
      ++i;
      if (tmp != 0 || tmp > nb)
	nb = tmp;
      nb = can_i_continu(c->my_tab, &i, nb, &stop);
      tmp = nb;
    }
  return (nb);
}

int	exec_the_prompt(t_shell *shell, t_chained *chain, int nb)
{
  int	fd_zero_origin;
  int	fd_one_origin;
  int	fd;

  fd = -1;
  g_dollard = 0;
  if ((debug_chain_my_tab_before(chain)) == FAIL)
    return (FAIL);
  while (g_dollard == 0 && chain != NULL &&
	 chain->my_tab != NULL && chain->my_tab[0] != NULL)
    {
      if (shell->bin_path != NULL)
	free_my_tab(shell->bin_path);
      fd_one_origin = dup(1);
      fd_zero_origin = dup(0);
      if ((stock_bin_path(shell)) == ERROR)
	return (ERROR);
      nb = series_of_test(shell, chain, &fd, 0);
      chain = chain->next;
      if (fd > -1)
	close(fd);
      dup2(fd_one_origin, 1);
      dup2(fd_zero_origin, 0);
    }
  return (nb);
}
