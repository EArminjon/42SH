/*
** main.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri May 12 16:58:44 2017 Enguerrand Arminjon
** Last update Sun May 28 09:22:03 2017 Enguerrand Arminjon
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

int		init_struct(t_shell *s, t_cd *cd)
{
  if ((cd->my_cd = getcwd(NULL, 0)) == NULL)
    return (ERROR);
  cd->home = NULL;
  cd->last_cd = NULL;
  s->exit = 0;
  s->waits = 0;
  s->envp = NULL;
  s->alias = NULL;
  s->my_set = NULL;
  s->bin_path = NULL;
  s->last_cmds = NULL;
  s->nb_cmds = 0;
  s->music_name = NULL;
  s->music_play = -1;
  s->music_pause = -1;
  load_music(s);
  s->nb_music = count_row((char **) s->music);
  s->size_history = 1000;
  if (((s->history = getcwd(NULL, 0)) == NULL) ||
      ((s->history = mallocat(s->history, FILE_HISTORY)) == NULL))
    return (ERROR);
  return (SUCCESS);
}

void		free_my_shell(t_shell *shell)
{
  free_my_tab(shell->alias);
  free_my_tab(shell->envp);
  free_my_tab(shell->bin_path);
  free_my_tab(shell->last_cmds);
  free_my_tab(shell->music_name);
  if (shell->music_play >= 0)
    sfMusic_stop(shell->music[shell->music_play]);
  if (shell->music_pause >= 0)
    sfMusic_stop(shell->music[shell->music_pause]);
  free_t_my_tab(shell->my_set);
  free(shell->history);
  free(shell->cd->my_cd);
  free(shell->cd->last_cd);
  free(shell->cd->home);
  free(shell->default_path);
  free(shell->cd);
  destroy_music(shell);
  free(shell->music);
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
  if (shell.envp != NULL && shell.envp[0] != '\0')
    my_42shrc(&shell, FILE_OPTION);
  nb = loop_shell(&shell, NULL);
  free_my_shell(&shell);
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
