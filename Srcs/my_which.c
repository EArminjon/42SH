/*
** my_which.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri May 12 11:06:30 2017 Enguerrand Arminjon
** Last update Tue May 16 16:54:57 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_macro.h"
#include "shell.h"
#include "my.h"

static int	whichpaths(char **paths, char *s)
{
  char		**new_paths;
  char		*str;
  int		i;

  new_paths = NULL;
  new_paths = my_copy_my_tab(new_paths, paths);
  i = 0;
  while (paths[i])
    {
      if (access(str = my_strcat_malloc(new_paths[i], s), F_OK) == 0)
	{
	  my_printf("%s\n", str);
	  free(str);
	  free_my_tab(new_paths);
	  return (SUCCESS);
	}
      free(str);
      ++i;
    }
  free_my_tab(new_paths);
  my_printf("%s: Command not found.\n", s);
  return (FAIL);
}

static int	my_which_null(t_shell *shell, char **my_tab)
{
  int		ret;
  int		nb;
  int		c;

  ret = 0;
  nb = 0;
  c = 0;
  while (my_tab != NULL && my_tab[++c])
    {
      if (check_builts(my_tab[c]) == SUCCESS)
	my_printf("%s: shell built-in command.\n", my_tab[c]);
      else
	nb = whichpaths(shell->bin_path, my_tab[c]);
      if (ret != 1)
	ret = nb;
    }
  return (ret);
}

static int	get_alias(t_shell *shell, char **my_tab, int c)
{
  int		i;
  int		a;
  int		nb;

  i = -1;
  while (shell->alias[++i])
    {
      if ((nb = my_strcmp_3(shell->alias[i], my_tab[c], ' ')) != -1)
	{
	  a = -1;
	  while (shell->alias[i][++a] != ' ')
	    my_putchar(shell->alias[i][a]);
	  my_printf(": \t aliased to%s\n", &shell->alias[i][nb]);
	  return (i);
	}
    }
  return (i);
}

static int	my_which_alias(t_shell *shell, char **my_tab)
{
  int		c;
  int		i;
  int		nb;
  int		ret;

  ret = 0;
  nb = 0;
  c = 0;
  while (my_tab[++c])
    {
      i = get_alias(shell, my_tab, c);
      if (shell->alias[i] == NULL &&
	  check_builts(my_tab[c]) == SUCCESS)
	my_printf("%s: shell built-in command.\n", my_tab[c]);
      else if (shell->alias[i] == NULL)
	nb = whichpaths(shell->bin_path, my_tab[c]);
      if (ret != 1 && nb == 1)
	ret = 1;
    }
  return (ret);
}

int	my_which(t_shell *shell, char **my_tab)
{
  if (my_tab[1] == NULL)
    {
      my_fprintf("which: Too few arguments.\n");
      return (FAIL);
    }
  if (shell->alias == NULL)
    return (my_which_null(shell, my_tab));
  return (my_which_alias(shell, my_tab));
}
