/*
** my_where.c for  in /home/BlueLemon/delivery/PSU_2016_42sh
**
** Made by Porcheret Thomas
** Login   <BlueLemon@epitech.net>
**
** Started on  Fri May 12 15:38:35 2017 Porcheret Thomas
** Last update Wed May 17 15:52:32 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include "my_macro.h"
#include "shell.h"
#include "my.h"
#include "ptr.h"

void	my_putstr_alias(char *ligne_alias, char *alias)
{
  int	i;

  i = my_strlen(alias) + 1;
  my_printf("%s is aliased to ", alias);
  my_printf("%s\n", &ligne_alias[i]);
}

int	my_where_alias(t_shell *shell, char **my_tab, int pos)
{
  int	nb;
  int	i;

  i = 0;
  nb = 1;
  if (shell->alias != NULL)
    {
      while (shell->alias[i] != NULL && my_tab[pos] != NULL)
	{
	  if (my_strcmp_2(shell->alias[i], my_tab[pos], ' ') == SUCCESS &&
	      my_tab[pos] != NULL)
	    {
	      my_putstr_alias(shell->alias[i], my_tab[pos]);
	      nb = 0;
	    }
	  ++i;
	}
    }
  return (nb);
}

int	my_where_path(t_shell *shell, char **my_tab, int pos)
{
  char	**new_path;
  char	*str;
  int	nb;
  int	i;

  new_path = NULL;
  new_path = my_copy_my_tab(new_path, shell->bin_path);
  nb = 1;
  i = 0;
  while (shell->bin_path[i])
    {
      if (access(str = my_strcat_malloc(new_path[i], my_tab[pos]), F_OK) == 0)
	{
	  my_printf("%s\n", str);
	  nb = 0;
	}
      free(str);
      ++i;
    }
  free_my_tab(new_path);
  return (nb);
}

int	my_where_builtin(char **my_tab, int pos)
{
  int	nb;
  int	i;

  i = 0;
  nb = 1;
  while (i < BUILTIN)
    {
      if (my_strcmp(ptrf_builtin[i].name, my_tab[pos]) == SUCCESS)
	{
	  my_printf("%s is a shell built-in\n", my_tab[pos]);
	  nb = 0;
	}
      ++i;
    }
  return (nb);
}

int	my_where(t_shell *shell, char **my_tab)
{
  int	nb;
  int	pos;

  nb = 0;
  pos = 1;
  if (my_tab[pos] == NULL)
    my_printf("where: Too few arguments.\n");
  while (my_tab[pos] != NULL)
    {
      nb = nb + my_where_alias(shell, my_tab, pos);
      nb = nb + my_where_path(shell, my_tab, pos);
      nb = nb + my_where_builtin(my_tab, pos);
      ++pos;
    }
  return (nb == 3 ? FAIL : 0);
}
