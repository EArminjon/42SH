/*
** history.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu May 11 12:41:51 2017 Enguerrand Arminjon
** Last update Mon May 15 13:00:47 2017 Enguerrand Arminjon
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_macro.h"
#include "my.h"

char		*find_history_line(char *s, int fd, int *i)
{
  char		*path;
  char		*str;
  char		*find;

  path = NULL;
  str = NULL;
  if ((find = take_following(s)) == NULL)
    return (NULL);
  while ((str = get_next_line(fd)) != NULL)
    find_history_line_loop(find, str, &path);
  if (path == NULL)
    {
      my_fprintf("%s: Event not found.\n", find);
      s[0] = '\0';
      return (s);
    }
  *i = *i + my_strlen(path) - 1;
  s = modify_with_simple(s, path);
  free(find);
  return (s);
}

char		*modif_str(char *s, char *pwd)
{
  int		i;
  int		fd;

  i = -1;
  while (s[++i] != '\0')
    {
      if (s[i] == '!' && s[i + 1] != '\0' && s[i + 1] != ' ')
	{
	  if ((fd = open(pwd, O_CREAT | O_RDWR, 0644)) == -1)
	    return (NULL);
	  if (s[i + 1] == '!')
	    {
	      if ((s = last_history_line(s, fd, &i)) == NULL)
		return (NULL);
	    }
	  else
	    if ((s = find_history_line(s, fd, &i)) == NULL)
	      return (NULL);
	  if (close(fd) == -1)
	    return (NULL);
	}
    }
  return (s);
}

int		write_into_file(char *pwd, char **s, int *nb, t_shell *shell)
{
  int		fd;

  if (*nb != 0 && *nb < shell->size_history)
    {
      if (((fd = open(pwd, O_CREAT | O_RDWR | O_APPEND, 0644)) == OPEN_FAIL))
	return (OPEN_FAIL);
    }
  else if (*nb == 0 || *nb > shell->size_history)
    {
      if ((fd = open(pwd, O_CREAT | O_RDWR | O_TRUNC, 0644)) == OPEN_FAIL)
	return (OPEN_FAIL);
      *nb = 0;
    }
  if (((write(fd, *s, my_strlen(*s)) == -1))
      || (write(fd, "\n", 1) == -1)
      || (close(fd) == -1))
    return (OPEN_FAIL);
  ++*nb;
  return (SUCCESS);
}

int		history_line(t_shell *shell, int *nb)
{
  int		fd;

  fd = 0;
  if ((fd = open(shell->history, O_CREAT | O_RDWR | O_APPEND, 0644)) == -1)
    return (*nb = -1);
  while (get_next_line(fd) != NULL)
    ++*nb;
  if (close(fd) == -1)
    *nb = -1;
  return (*nb);
}

int		put_history(char **s, t_shell *shell)
{
  static int	history_lines = 0;

  if (check_hist(*s) == 1)
    {
      if ((*s = modif_str(*s, shell->history)) == NULL)
	return (my_puterror("OPEN FAIL: 2\n", 2, ERROR));
      if (*s[0] == '\0')
	return (FAIL);
      my_printf("%s\n", *s);
    }
  if (write_into_file(shell->history, s, &history_lines, shell) == -1)
    return (my_puterror("OPEN FAIL: 3\n", 2, ERROR));
  return (SUCCESS);
}
