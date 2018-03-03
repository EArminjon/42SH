/*
** my_redirection.c for $ in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Apr 15 19:23:42 2017 Enguerrand Arminjon
** Last update Mon May 15 13:13:48 2017 Enguerrand Arminjon
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_macro.h"
#include "my.h"

int	while_double(char **my_tab, int *i, int pipefd[2])
{
  char	*s;

  while (42)
    {
      if (isatty(0) == 1)
	my_putstr("? ");
      if (((s = get_next_line(0)) == NULL)
	  || ((my_strcmp(s, my_tab[*i + 1])) == SUCCESS))
	{
	  free(s);
	  return (SUCCESS);
	}
      my_puterror(s, pipefd[1], 0);
      my_puterror("\n", pipefd[1], 0);
      free(s);
    }
  return (SUCCESS);
}

int	my_double_redir(char **my_tab, int *fd, int i)
{
  int	pipefd[2];

  pipe(pipefd);
  while_double(my_tab, &i, pipefd);
  *fd = -2;
  close(pipefd[1]);
  if ((dup2(pipefd[0], 0)) == -1)
    return (-1);
  close(pipefd[0]);
  return (SUCCESS);
}

int	do_sep_redir(char **my_tab, char *file, int i, int *fd)
{
  if ((my_strcmp(my_tab[i], ">")) == SUCCESS)
    {
      if ((my_redir(file, fd, (O_CREAT | O_TRUNC | O_RDWR), 1)) == -1)
	return (my_display_error(fd, file));
    }
  else if ((my_strcmp(my_tab[i], ">>")) == SUCCESS)
    {
      if ((my_redir(file, fd, (O_CREAT | O_APPEND | O_RDWR), 1)) == -1)
	return (my_display_error(fd, file));
    }
  else if ((my_strcmp(my_tab[i], "<")) == SUCCESS)
    {
      if ((my_redir(file, fd, (O_RDONLY), 0)) == -1)
	return (my_display_error(fd, file));
    }
  else if ((my_strcmp(my_tab[i], "<<")) == SUCCESS)
    my_double_redir(my_tab, fd, i);
  return (SUCCESS);
}

int	check_no_such_file(char **my_tab)
{
  int	i;
  int	fd;

  i = 0;
  fd = -1;
  while (my_tab[i] != NULL)
    {
      if (my_strcmp(my_tab[i], "<") == 0 && my_tab[i + 1] != NULL)
	{
	  if (access(my_tab[i + 1], F_OK) == -1)
	    {
	      my_fprintf("%s: No such file or directory.\n", my_tab[i + 1]);
	      return (-3);
	    }
	}
      i++;
    }
  if (fd != -1)
    close(fd);
  return (SUCCESS);
}

int	do_redirection(char **t)
{
  int	i;
  int	fd;
  int	tmp;

  i = -1;
  fd = -1;
  if ((tmp = check_no_such_file(t)) != SUCCESS)
    return (tmp);
  while (t[++i] != NULL)
    {
      if (t[i + 1] != NULL && (t[i][0] == '<' || t[i][0] == '>'))
	{
	  do_sep_redir(t, t[i + 1], i, &fd);
	  t = delete_two_lines(t, i);
	  i = -1;
	}
    }
  return (fd);
}
