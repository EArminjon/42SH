/*
** cd.h for  in /home/armin.pc/delivery/CPE_2016_getnextline/include
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Mon Jan  2 08:58:54 2017 Enguerrand Arminjon
** Last update Wed Jan 18 11:06:37 2017 Enguerrand Arminjon
*/

#ifndef CD_H_
# define CD_H_

typedef struct	s_cd
{
  char		*mycd;
  char		*lastcd;
  char		*path_user;
  char		**envp;
  char		*p;
  int		thend;
}		t_cd;

#endif /* CD_H_ */
