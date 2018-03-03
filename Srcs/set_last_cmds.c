/*
** set_last_cmds.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri May 19 11:24:52 2017 Enguerrand Arminjon
** Last update Sun May 21 10:42:18 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

int	set_last_cmds(t_shell *shell, t_chained *c, int i)
{
  shell->waits = my_count_pipes(c->my_tab[i]);
  return (0);
}
