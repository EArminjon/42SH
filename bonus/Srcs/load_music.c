/*
** music.c for  in /home/Guillaume/delivery/PSU_2016_42sh/Srcs
**
** Made by Guillaume Millet
** Login   <Guillaume@epitech.net>
**
** Started on  Fri May 19 09:14:01 2017 Guillaume Millet
** Last update Sat May 20 10:55:42 2017 Enguerrand Arminjon
*/

#include <sys/types.h>
#include <dirent.h>
#include <dirent.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include "my.h"
#include "my_macro.h"

int		check_wav(char *str)
{
  int		pos;

  pos = my_strlen(str);
  while (str!= NULL && str[pos] != '.' && pos > 0)
    pos = pos -1;
  if (my_strcmp(&str[pos], EXTENSION) == 0)
    return (0);
  return (1);
}

char		**music_to_tab()
{
  DIR		*rep;
  struct dirent	*entry;
  char		**tab;

  tab = NULL;
  if ((rep = opendir(FOLDER)) == NULL)
    return (NULL);
  while ((entry = readdir(rep)) != NULL)
    {
      if (check_wav(entry->d_name) == 0)
	tab = add_line_my_tab(tab, entry->d_name, count_row(tab));
    }
  closedir(rep);
  return (tab);
}

int		load_music(t_shell *shell)
{
  int		j;
  int		size;
  char		*tmp;
  char		*tmp2;

  j = 0;
  shell->music_name = music_to_tab();
  size = count_row(shell->music_name);
  if ((shell->music = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (84);
  while (j < size)
    {
      if (((tmp = my_strcat_malloc(FOLDER, "/")) == NULL)
	  || ((tmp2 = my_strcat_malloc(tmp, shell->music_name[j])) == NULL))
	return (my_puterror("music: Preload fail\n", 2, 84));
      shell->music[j] = sfMusic_createFromFile(tmp2);
      free(tmp);
      free(tmp2);
      j = j + 1;
    }
  shell->music[j] = NULL;
  return (0);
}
