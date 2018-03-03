/*
** destroy_music.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh/bonus
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri May 19 13:50:12 2017 Enguerrand Arminjon
** Last update Sat May 20 10:57:04 2017 Enguerrand Arminjon
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "shell.h"

int	destroy_music(t_shell *shell)
{
  int	i;

  i = 0;
  while (shell != NULL && shell->music != NULL && shell->music[i] != NULL)
    {
      sfMusic_destroy(shell->music[i]);
      i = i + 1;
    }
  return (0);
}
