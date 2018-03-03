/*
** my_env.c for  in /home/armin.pc/delivery/PSU_2016_minishell2
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Mar 24 13:44:25 2017 Enguerrand Arminjon
** Last update Mon May 15 13:06:07 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "shell.h"
#include "my_macro.h"
#include "my.h"

int	unsetenv_arg(t_shell *shell, char **my_tab)
{
  int	i;
  char	*tmp;

  i = 0;
  while (shell->envp[i] != '\0'
	 && (my_strcmp_2(shell->envp[i], my_tab[1], '=')) != 0)
    i++;
  while (shell->envp[i] != NULL && shell->envp[i + 1] != NULL)
    {
      tmp = shell->envp[i];
      shell->envp[i] = shell->envp[i + 1];
      shell->envp[i + 1] = tmp;
      i++;
    }
  if (my_strcmp(my_tab[1], "PATH") == 0)
    {
      free(shell->default_path);
      shell->default_path =
	my_strcat_malloc(NULL, my_getenv(&shell->envp[i], "PATH="));
      free(shell->envp[i]);
      shell->envp[i] = NULL;
    }
  return (SUCCESS);
}

int	my_unsetenv(t_shell *shell, char **my_tab)
{
  if ((my_strcmp("unsetenv", my_tab[0])) == 0 && my_tab[1] == NULL)
    {
      my_fputstr("unsetenv: Too few arguments.\n");
      return (2);
    }
  else if ((my_strcmp("unsetenv", my_tab[0])) == 0 && my_tab[1] != NULL)
    {
      unsetenv_arg(shell, my_tab);
      return (SUCCESS);
    }
  return (FAIL);
}

int	check_setenv(char **my_tab)
{
  if (my_tab[1] != NULL && my_tab[2] != NULL && my_tab[3] != NULL)
    my_fputstr("setenv: Too many arguments.\n");
  else if ((my_tab[1][0] < 'A') || (my_tab[1][0] > 'Z' && my_tab[1][0] < 'a')
	   || (my_tab[1][0] > 'z'))
    my_fputstr("setenv: Variable name must begin with a letter.\n");
  else if ((my_str_isalpha(my_tab[1]) == FAIL))
    {
      my_fputstr("setenv: Variable name must contain alphanumeric charac");
      my_fputstr("ters.\n");
    }
  else
    return (SUCCESS);
  return (2);
}

char	**my_new_envp(t_shell *shell, char *new_row)
{
  char	**new;
  int	size;
  int	a;

  a = 0;
  size = count_row(shell->envp);
  if ((new = malloc(sizeof(char *) * (size + 2))) == NULL)
    return (NULL);
  while (shell->envp[a] != NULL)
    {
      new[a] = shell->envp[a];
      a++;
    }
  new[a] = new_row;
  new[a + 1] = NULL;
  free(shell->envp);
  return (new);
}

int	my_setenv(t_shell *shell, char **my_tab)
{
  char	*new_row;
  int	nb;
  int	i;

  i = 0;
  nb = 1;
  if (my_tab[1] == NULL)
    return (print_env(shell, my_tab));
  if ((check_setenv(my_tab)) == 2)
    return (2);
  new_row = my_new_row_env(my_tab);
  while (shell->envp[i] != NULL
	 && (nb = my_strcmp_2(shell->envp[i], my_tab[1], '=') == FAIL))
    i++;
  if (nb != 1)
    {
      free(shell->envp[i]);
      shell->envp[i] = new_row;
      return (SUCCESS);
    }
  else
    if ((shell->envp = my_new_envp(shell, new_row)) == NULL)
      return (ERROR);
  return (SUCCESS);
}
