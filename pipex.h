/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:17:52 by aroualid          #+#    #+#             */
/*   Updated: 2024/06/13 11:58:33 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_strncmp(const char *first, const char *second, size_t length);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*find_path(char **env, char *av);
char		**find_cmd(char *av);
int			exec_first(char *av, char **env, char *file);
void		exec_last(char *av, char **env, char *file, int fd);
void		ft_free(char **tav);
void		ft_close(int pip[2], int infile);
void		apply_exec_first(char *av, char **env, char *file, int pip[2]);
void		apply_exec_last(char *av, char **env, char *file, int fd);
char		*return_path(char **cmd, char *endfile, char *path);
void		apply_exec_first_bns(char *av, char **env, char *file, int pip[2]);
void		apply_exec_middle_bonus(int fd, int pip[2], char **env, char *av);
void		apply_exec_last_bns(char *av, char **env, char *file, int fd);
char		*ft_strchr(const char *s, int c);
int			check_infile(char *file);
#endif
