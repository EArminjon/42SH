/*
** center_of_control.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Apr 26 15:27:20 2017 Enguerrand Arminjon
** Last update Tue May 16 13:48:23 2017 Enguerrand Arminjon
*/

#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "shell.h"
#include "my.h"

int	check_not_a_dir(char *cmds, char tmp)
{
  DIR	*dir;
  int	i;

  dir = NULL;
  if (cmds != NULL)
    {
      i = my_strlen(cmds);
      while (i > 0 && cmds[i] != '/')
	--i;
      if (cmds[i] == '/')
	{
	  tmp = cmds[i];
	  cmds[i] = '\0';
	  if (((access(cmds, F_OK)) == 0) && ((dir = opendir(cmds)) == NULL))
	    {
	      cmds[i] = tmp;
	      my_fprintf("%s: Not a directory\n", cmds);
	      return (1);
	    }
	  cmds[i] = tmp;
	  if (dir != NULL)
	    closedir(dir);
	}
    }
  return (0);
}

int	is_it_a_cmds(char *str)
{
  int	i;
  int	sep;

  i= 0;
  sep = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	++sep;
      ++i;
    }
  return (sep == 0 ? 1 : 0);
}

int	check_cmds_perms_next(char *cmds, t_shell *shell, char **my_tab)
{
  if ((check_not_a_dir(cmds, 0)) == 1)
    return (-2);
  else if ((access(cmds, F_OK)) == -1 || ((is_it_a_cmds(cmds)) == 1))
    return (1);
  return (my_fork(shell, my_tab, cmds));
}

int	check_cmds_perms(char *cmds, t_shell *shell, char **my_tab)
{
  DIR	*dir;
  char	*s;

  s = NULL;
  dir = NULL;
  if ((access(cmds, F_OK)) == 0
      && (((access(cmds, X_OK)) == -1) || (dir = opendir(cmds)) != NULL))
    {
      if (dir != NULL)
	closedir(dir);
      if (*cmds == '.' || ((s = my_getenv(shell->envp, "PATH=")) == NULL)
	  || (s != NULL && s[0] == '\0') || *cmds == '/')
	{
	  if (s != NULL)
	    free(s);
	  my_fprintf("%s: Permission denied.\n", cmds);
	  return (-2);
	}
      if (s != NULL)
	free(s);
      return (1);
    }
  return (check_cmds_perms_next(cmds, shell, my_tab));
}
