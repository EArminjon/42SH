/*
** my_set.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed May 17 16:38:18 2017 Enguerrand Arminjon
** Last update Fri May 19 10:36:55 2017 Enguerrand Arminjon
*/

#include "shell.h"
#include "my.h"

int	print_my_set(char ***tab)
{
  int	j;
  int	i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      j = 0;
      while (tab[i] != NULL && tab[i][j] != NULL)
	{
	  my_putstr(tab[i][j++]);
	  if (tab[i][j] != NULL)
	    my_putchar('\t');
	}
      my_putchar('\n');
      ++i;
    }
  return (0);
}

char	**set_to_tab(char *str)
{
  int	a;
  int	i;
  char	**new;

  if (str == NULL || ((new = malloc(sizeof(char *) * 3)) == NULL)
      || ((new[0] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
      || ((new[1] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL))
    return (NULL);
  a = 0;
  i = 0;
  while (str != NULL && str[a] != '=' && str[a] != '\0')
    new[0][i++] = str[a++];
  new[0][i] = '\0';
  i = 0;
  if (str[a] != '\0')
    {
      ++a;
      while (str[a] != '\0')
	new[1][i++] = str[a++];
    }
  new[1][i] = '\0';
  new[2] = NULL;
  return (new);
}

int	my_set_argu(t_shell *s, char *str)
{
  int	here;
  char	***new_t_tb;
  char	**new_tab;

  here = 0;
  if (((new_t_tb = my_copy_t_my_tab_custom(s->my_set, 1, &here, str)) == NULL)
      || ((new_tab = set_to_tab(str)) == NULL))
    return (84);
  new_t_tb[here] = new_tab;
  free(s->my_set);
  s->my_set = new_t_tb;
  return (0);
}

int	my_set(t_shell *shell, char **my_tab)
{
  int	i;

  i = 1;
  if (my_tab[1] == NULL && shell->my_set != NULL)
    return (print_my_set(shell->my_set));
  while (my_tab[i] != NULL)
    {
      if ((my_set_argu(shell, my_tab[i])) == 84)
	return (84);
      ++i;
    }
  return (0);
}
