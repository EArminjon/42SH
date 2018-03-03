/*
** my_music.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh/bonus
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri May 19 11:48:25 2017 Enguerrand Arminjon
** Last update Fri May 19 15:27:33 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include "my_macro.h"
#include "music.h"
#include "my.h"

int		my_main_music(t_shell *shell, char **my_tab)
{
  int		nb;
  int		i;

  i = 0;
  nb = 1;
  while (i < MUSIC &&
         ((nb = my_strcmp(my_tab[1], ptrf_music[i].name)) != SUCCESS))
    ++i;
  if (nb == 0)
    nb = ptrf_music[i].ptr_function(shell, my_tab);
  else
    {
      my_fprintf("music : '%s' command not found.\n", my_tab[1]);
      return (2);
    }
  return (nb);
}

int		print_my_music(char **my_tab)
{
  int		i;

  i = -1;
  if (my_tab == NULL)
    return (SUCCESS);
  while (my_tab[++i] != NULL)
    my_printf("%i: %s\n", i, my_tab[i]);
  return (SUCCESS);
}

int		my_music(t_shell *shell, char **my_tab)
{
  if (my_tab[1] == NULL && shell->music_name != NULL)
    return (print_my_music(shell->music_name));
  else if (shell->music == NULL || shell->music_name == NULL)
    {
      my_fprintf("music: No music in the folder : %s\n", FOLDER);
      return (2);
    }
  else
    return (my_main_music(shell, my_tab));
  return (0);
}
