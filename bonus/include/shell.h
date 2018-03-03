/*
** shell.h for  in /home/armin.pc/delivery/CPE_2016_getnextline/include
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Jan  2 08:58:54 2017 Enguerrand Arminjon
** Last update Fri May 19 15:38:13 2017 Enguerrand Arminjon
*/

#ifndef SHELL_H_
# define SHELL_H_

#include <SFML/Audio.h>

typedef struct		s_chained
{
  char			***my_tab;

  struct s_chained	*next;
}			t_chained;

typedef struct		s_cd
{
  char			*last_cd;
  char			*my_cd;
  char			*home;
}			t_cd;

typedef struct		s_keys
{
  char			*up;
  char			*left;
  char			*down;
  char			*right;
}			t_keys;

typedef struct		s_shell
{
  sfMusic		**music;
  int			waits;
  int			exit;
  int			size_history;
  int			nb_cmds;
  char			*history;
  char			*default_path;
  char			**last_cmds;
  int			nb_music;
  int			music_play;
  int			music_pause;
  char			**music_name;
  char			***my_set;
  char			**alias;
  char			**envp;
  char			**bin_path;
  t_keys		*keys;
  t_cd			*cd;
}			t_shell;

#endif /* SHELL_H_ */
