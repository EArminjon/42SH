/*
** debug_shell.c for  in /home/armin.pc/delivery/PSU_2016_minishell2
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Mar 27 15:24:55 2017 Enguerrand Arminjon
** Last update Mon May 15 15:23:21 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "shell.h"
#include "my_macro.h"
#include "my.h"

int		missing_invalid(char **my_tab, int i)
{
  int		nb;

  nb = 0;
  if ((i == 0 && my_tab[i + 1] == NULL && my_tab[i][0] == '|')
      || (i > 0 && my_tab[i][0] == '|' && my_tab[i + 1] == NULL))
    return (my_puterror("Invalid null command.\n", 2, FAIL));
  else if (i == 0 && (my_tab[i + 1] == NULL || my_tab[i + 1][0] == '>' ||
		      my_tab[i + 1][0] == '<' || my_tab[i + 1][0] == '&'))
    return (my_puterror("Missing name for redirect.\n", 2, FAIL));
  else if (i == 0 && my_tab[i + 1] != NULL && my_tab[i + 2 ] == NULL)
    return (my_puterror("Invalid null command.\n", 2, FAIL));
  nb = ambi_direct(my_tab, i);
  return (nb);
}

int		debug_redir(char **my_tab)
{
  int		i;

  i = 0;
  while (my_tab[i] != NULL)
    {
      if ((my_tab[i][0] == '>' || my_tab[i][0] == '<' || my_tab[i][0] == '|')
	  && missing_invalid(my_tab, i) == FAIL)
	return (FAIL);
      if (count_redir(my_tab[i], 0) == FAIL)
	return (FAIL);
      i++;
    }
  return (SUCCESS);
}

int		debug_pipe_esper(char ***my_tab, int i)
{
  if (my_tab[i][0][0] == '|' && (i == 0 || my_tab[i - 1] == NULL
				 || my_tab[i + 1] == NULL))
    return (my_puterror("Invalid null command.\n", 2, FAIL));
  else if (my_tab[i][0][0] == '&' && i != 0 && my_tab[i + 1] == NULL)
    return (my_puterror("Invalid null command.\n", 2, FAIL));
  else if (i > 0 && (my_tab[i][0][0] == '&' || my_tab[i][0][0] == '|')
	   && (my_tab[i - 1][0][0] == '&' || my_tab[i - 1][0][0] == '|'))
    return (my_puterror("Invalid null command.\n", 2, FAIL));
  return (SUCCESS);
}

int		debug_my_tab(char ***my_tab)
{
  int		i;

  i = 0;
  while (my_tab[i] != NULL)
    {
      count_redir(NULL, 1);
      if ((my_strcmp(my_tab[i][0], "&&") == SUCCESS)
	  || (my_strcmp(my_tab[i][0], "||") == SUCCESS))
	{
	  if ((debug_pipe_esper(my_tab, i)) == FAIL)
	    return (FAIL);
	}
      else if (my_tab[i] != NULL && my_tab[i][0] != NULL
	       && (debug_redir(my_tab[i])) == FAIL)
	return (FAIL);
      i++;
    }
  return (0);
}

int		debug_chain_my_tab_before(t_chained *chain)
{
  while (chain != NULL)
    {
      if ((chain->my_tab != NULL) && (debug_my_tab(chain->my_tab)) == 1)
	return (FAIL);
      chain = chain->next;
    }
  return (SUCCESS);
}
