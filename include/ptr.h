/*
** ptr.h for  in /home/armin.pc/delivery/CPE_2016_getnextline/include
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Jan  2 08:58:54 2017 Enguerrand Arminjon
** Last update Thu May 18 13:12:39 2017 Enguerrand Arminjon
*/

#ifndef PTR_H_
# define PTR_H_

# include "my.h"

typedef struct		s_pointer
{
  char			*name;
  int			(*ptr_function)(t_shell *shell, char **my_tab);
}			t_pointer;

# define BUILTIN 14

static			t_pointer ptrf_builtin[BUILTIN] =
  {
    {"alias", add_or_display_alias},
    {"exit", my_exit},
    {"env", print_env},
    {"setenv", my_setenv},
    {"unsetenv", my_unsetenv},
    {"cd", my_cd},
    {"echo", my_echo},
    {"where", my_where},
    {"which", my_which},
    {"if", my_if},
    {"repeat", my_repeat},
    {"foreach", my_foreach},
    {"set", my_set},
    {"unset", my_unset},
  };

#endif /* PTR_H_ */
