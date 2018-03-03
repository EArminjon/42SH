/*
** main.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri May 12 16:58:44 2017 Enguerrand Arminjon
** Last update Fri May 19 15:24:47 2017 Enguerrand Arminjon
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_macro.h"
#include "my.h"
#include "shell.h"

int		fix_the_path(t_shell *shell)
{
  char		*path;
  size_t	n;

  n = confstr(_CS_PATH, NULL, (size_t) 0);
  if ((path = malloc(n)) == NULL)
    return (ERROR);
  confstr(_CS_PATH, path, n);
  shell->default_path = path;
  return (SUCCESS);
}

int		init_struct(t_shell *sh, t_cd *cd)
{
  if ((cd->my_cd = getcwd(NULL, 0)) == NULL)
    return (ERROR);
  cd->home = NULL;
  cd->last_cd = NULL;
  sh->exit = 0;
  sh->waits = 0;
  sh->envp = NULL;
  sh->alias = NULL;
  sh->my_set = NULL;
  sh->bin_path = NULL;
  sh->last_cmds = NULL;
  sh->nb_cmds = 0;
  sh->size_history = 1000;
  if (((sh->history = getcwd(NULL, 0)) == NULL) ||
      ((sh->history = mallocat(sh->history, "/History/.history")) == NULL))
    return (ERROR);
  return (SUCCESS);
}

void		free_shell(t_shell *shell)
{
  free_my_tab(shell->alias);
  free_my_tab(shell->envp);
  free_my_tab(shell->bin_path);
  free_my_tab(shell->last_cmds);
  free_t_my_tab(shell->my_set);
  free(shell->history);
  free(shell->cd->my_cd);
  free(shell->cd->last_cd);
  free(shell->cd->home);
  free(shell->default_path);
  free(shell->cd);
  free(g_prompt);
}

int		my_shell(char **envp)
{
  t_shell	shell;
  int		nb;

  if (((shell.cd = malloc(sizeof(*shell.cd))) == NULL)
      || ((init_struct(&shell, shell.cd)) == ERROR)
      || ((shell.envp = clone_my_tab(envp, shell.envp)) == NULL)
      || ((fix_the_path(&shell)) == ERROR))
    return (ERROR);
  nb = loop_shell(&shell, NULL);
  free_shell(&shell);
  return (nb);
}

int		main(int ac, char **av, char **envp)
{
  int		nb;

  if (ac != 1 && av[0] != NULL)
    {
      my_fprintf("Please %s\n", av[0]);
      return (ERROR);
    }
  nb = my_shell(envp);
  return (nb == 84 ? my_puterror("ERROR\n", 2, ERROR) : nb);
}
