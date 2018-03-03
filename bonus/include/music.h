/*
** ptr.h for  in /home/armin.pc/delivery/CPE_2016_getnextline/include
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Jan  2 08:58:54 2017 Enguerrand Arminjon
** Last update Fri May 19 13:20:15 2017 Enguerrand Arminjon
*/

#ifndef MUSIC_H_
# define MUSIC_H_

# include "my.h"

typedef struct		s_pointer
{
  char			*name;
  int			(*ptr_function)(t_shell *shell, char **my_tab);
}			t_pointer;

# define MUSIC 4

static			t_pointer ptrf_music[MUSIC] =
  {
    {"play", my_music_play},
    {"pause", my_music_pause},
    {"random", my_music_random},
    {"stop", my_music_stop},
  };

#endif /* MUSIC_H_ */
