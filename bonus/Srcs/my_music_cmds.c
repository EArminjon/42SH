/*
** my_music_cmds.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri May 19 15:26:39 2017 Enguerrand Arminjon
** Last update Mon May 22 12:02:01 2017 Enguerrand Arminjon
*/

#include <time.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include "my_macro.h"
#include "my.h"

int		check_cmds_number(char *str)
{
  if (my_str_isnum(str) != 0)
    return (-1);
  return (my_getnbr(str));
}

int		my_music_play(t_shell *shell, char **my_tab)
{
  int		nb;

  nb = -1;
  if (shell->music_pause < 0 && (my_tab[2] == NULL || shell->music == NULL ||
				 ((nb = check_cmds_number(my_tab[2])) < 0)))
    return (my_puterror("music: music play [nb >= 0].\n", 2, 2));
  if (nb >= 0 && nb <= shell->nb_music && shell->music != NULL
      && shell->music[nb] != NULL && shell->music_pause < 0)
    {
      my_printf("music: %s.\n", shell->music_name[nb]);
      if (shell->music_play >= 0)
	sfMusic_stop(shell->music[shell->music_play]);
      sfMusic_play(shell->music[nb]);
      shell->music_play = nb;
    }
  else if (shell->music_pause >= 0)
    {
      my_printf("music: %s.\n", shell->music_name[shell->music_pause]);
      sfMusic_play(shell->music[shell->music_pause]);
      shell->music_play = shell->music_pause;
      shell->music_pause = -1;
    }
  else
    return (my_fprintf("music: Error with the folder : %s.\n", FOLDER) + 2);
  return (0);
}

int		my_music_random(t_shell *shell, char **my_tab)
{
  static int	i;
  int		nb;

  if (i == 0)
    {
      srand(time(NULL));
      i = 1;
    }
  nb = rand() % (shell->nb_music - 1 + 1) + 0;
  if (nb <= shell->nb_music && shell->music != NULL
      && shell->music[nb] != NULL && my_tab != NULL && shell->music_pause < 0)
    {
      my_printf("music: %s.\n", shell->music_name[nb]);
      if (shell->music_play >= 0)
	sfMusic_stop(shell->music[shell->music_play]);
      sfMusic_play(shell->music[nb]);
      shell->music_play = nb;
    }
  else
    {
      my_fprintf("music: Error with the folder : %s.\n", FOLDER);
      return (2);
    }
  return (0);
}

int		my_music_pause(t_shell *shell, char **my_tab)
{
  if (shell->music_pause < 0 && shell->music_play >= 0 && my_tab != NULL)
    {
      my_printf("music: '%s' is in pause.\n",
		shell->music_name[shell->music_play]);
      sfMusic_pause(shell->music[shell->music_play]);
      shell->music_pause = shell->music_play;
      shell->music_play = -1;
    }
  else if (shell->music_pause >= 0)
    {
      my_printf("music: %s.\n", shell->music_name[shell->music_pause]);
      sfMusic_play(shell->music[shell->music_pause]);
      shell->music_play = shell->music_pause;
      shell->music_pause = -1;
    }
  else
    {
      my_fprintf("music: No music is playing or in pause.\n");
      return (2);
    }
  return (0);
}

int		my_music_stop(t_shell *shell, char **my_tab)
{
  if (shell->music_play >= 0 && my_tab != NULL)
    {
      my_printf("music: '%s' is stop.\n",
		shell->music_name[shell->music_play]);
      sfMusic_stop(shell->music[shell->music_play]);
      shell->music_play = -1;
    }
  else if (shell->music_pause >= 0)
    {
      my_printf("music: '%s' is stop.\n",
		shell->music_name[shell->music_pause]);
      sfMusic_stop(shell->music[shell->music_pause]);
      shell->music_pause = -1;
    }
  else
    return (my_puterror("music : No music is running.\n", 2, 2));
  return (0);
}
