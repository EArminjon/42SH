/*
** list.h for  in /home/armin.pc
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Mon Nov  7 11:32:08 2016 Enguerrand Arminjon
** Last update Tue Jan 17 09:11:09 2017 Enguerrand Arminjon
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_list
{
  char		*l_envp;

  struct s_list *next;
}		t_list;

#endif /* !LIST_H_ */
