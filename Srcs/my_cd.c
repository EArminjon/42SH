/*
** my_cd.c for  in /home/armin.pc/delivery/PSU_2016_minishell2
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Mar 24 15:31:57 2017 Enguerrand Arminjon
** Last update Tue May 16 14:31:20 2017 Enguerrand Arminjon
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include "my_macro.h"
#include "shell.h"
#include "my.h"

int	check_perm_cd(char *path)
{
  if ((access(path, F_OK)) == 0 && ((access(path, R_OK)) == -1))
    {
      my_fprintf("%s: Permission denied.\n", path);
      return (FAIL);
    }
  return (SUCCESS);
}

int	my_cd_home(t_shell *shell)
{
  DIR	*dir;
  int	nb;

  nb = 0;
  if (shell != NULL && shell->cd != NULL &&
      shell->cd->home != NULL && (dir = opendir(shell->cd->home)) != NULL
      && (nb = check_perm_cd(shell->cd->home)) == 0)
    {
      closedir(dir);
      free(shell->cd->last_cd);
      shell->cd->last_cd = getcwd(NULL, 0);
      chdir(shell->cd->home);
      free(shell->cd->my_cd);
      shell->cd->my_cd = getcwd(NULL, 0);
      if (isatty(0) == 1)
	my_fprintf("Directory: %s\n", shell->cd->my_cd);
    }
  else if (dir == NULL)
    return (my_puterror("cd: Can't change to home directory.\n", 1, 2));
  else
    return (my_puterror("cd: No home directory.\n", 1, 2));
  return (SUCCESS);
}

int	my_cd_back(t_shell *shell, int nb)
{
  free(shell->cd->last_cd);
  shell->cd->last_cd = getcwd(NULL, 0);
  chdir("..");
  if (nb == 1)
    chdir("..");
  free(shell->cd->my_cd);
  shell->cd->my_cd = getcwd(NULL, 0);
  if (isatty(0) == 1)
    my_fprintf("Directory: %s\n", shell->cd->my_cd);
  return (0);
}

int	my_cd_safe_back(t_shell *shell)
{
  char	*copy;

  copy = NULL;
  if (shell->cd->last_cd == NULL)
    {
      my_fputstr(": No such file or directory.\n");
      return (FAIL);
    }
  chdir(shell->cd->last_cd);
  copy = shell->cd->last_cd;
  shell->cd->last_cd = shell->cd->my_cd;
  shell->cd->my_cd = copy;
  if (isatty(0) == 1)
    my_fprintf("Directory: %s\n", shell->cd->my_cd);
  return (SUCCESS);
}

int	my_cd_path(t_shell *shell, char **my_tab)
{
  DIR	*my_dir;

  if (check_perm_cd(my_tab[1]) == FAIL)
    return (FAIL);
  if ((access(my_tab[1], F_OK)) == -1)
    {
      my_fprintf("%s: No such file or directory.\n", my_tab[1]);
      return (FAIL);
    }
  else if ((my_dir = opendir(my_tab[1])) == NULL)
    {
      my_fprintf("%s: Not a directory.\n", my_tab[1]);
      closedir(my_dir);
      return (FAIL);
    }
  closedir(my_dir);
  free(shell->cd->last_cd);
  shell->cd->last_cd = getcwd(NULL, 0);
  if ((chdir(my_tab[1])) == -1)
    return (FAIL);
  free(shell->cd->my_cd);
  shell->cd->my_cd = getcwd(NULL, 0);
  if (isatty(0) == 1)
    my_fprintf("Directory: %s\n", shell->cd->my_cd);
  return (SUCCESS);
}
