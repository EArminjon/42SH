/*
** my_foreach_next.c for  in /home/armin.pc/delivery/PSU/PSU_2016_42sh
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed May 17 11:18:06 2017 Enguerrand Arminjon
** Last update Wed May 17 16:20:37 2017 Enguerrand Arminjon
*/

#include "shell.h"
#include "my.h"

char	*my_getenv_str(char *str, char **envp)
{
  char	*s;
  char	*env;
  int	i;
  int	a;

  a = 0;
  i = 0;
  if ((env = malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
    return (NULL);
  env[0] = '\0';
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    env[a++] = str[i++];
  env[a] = '=';
  env[a + 1] = '\0';
  s = my_getenv(envp, env);
  free(env);
  return (s);
}

char	*my_var_next(char *str, char *new, int *j, int *a)
{
  *a = 0;
  *j = 0;
  while (str != NULL && str[*j] != '$' && str[*j] != '\0')
    {
      new[*a] = str[*j];
      *j = *j + 1;
      *a = *a + 1;
    }
  *j = 0;
  return (new);
}

char	*my_var(char *str, char **envp, int i)
{
  char	*new;
  char	*s;
  int	a;
  int	j;

  while (str != NULL && str[++i] != '\0')
    {
      if (str[i] == '$')
	{
	  s = my_getenv_str(&str[i + 1], envp);
	  if ((new = malloc(sizeof(char) * (my_strlen(str)
					    + my_strlen(s) + 1))) == NULL)
	    return (NULL);
	  a = 0;
	  j = 0;
	  new = my_var_next(str, new, &j, &a);
	  while (s != NULL && s[j] != '\0')
	    new[a++] = s[j++];
	  new[a] = '\0';
	  free(str);
	  str = new;
	  i = -1;
	}
    }
  return (str);
}

char	*replace_var_by_argu_next(char *cmds_s, char *argu, t_shell *shell)
{
  char	*new;
  int	pos;
  int	a;
  int	b;

  pos = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(cmds_s) *
				    (my_strlen(argu) + 1)))) == NULL)
    return (NULL);
  a = 0;
  while (cmds_s[a] != '\0')
    {
      while (cmds_s[a] != '$' && cmds_s[a] != '\0')
	new[pos++] = cmds_s[a++];
      b = 0;
      while (cmds_s[a] == '$' && argu != NULL && argu[b] != '\0')
	new[pos++] = argu[b++];
      if (cmds_s[a] == '$')
	while (cmds_s[a] != ' ' && cmds_s[a] != '\t' && cmds_s[a] != '\0')
	  ++a;
    }
  new[pos] = '\0';
  new = my_var(new, shell->envp, -1);
  free(cmds_s);
  return (new);
}
