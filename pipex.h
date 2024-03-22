/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:17:52 by aroualid          #+#    #+#             */
/*   Updated: 2024/03/22 19:00:19 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <fcntl.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char	**ft_split(char const *s, char c);
void	 *ft_calloc(size_t nmemb, size_t size);
void	 ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *first, const char *second, size_t length);
char	 *ft_strjoin(char const *s1, char const *s2);
size_t	 ft_strlen(const char *s);
char	*find_path(char **env, char *av);
char	**find_cmd(char *av);
int		apply_exec(char *path, char **cmd, char **env);
void	ft_free(char **tav);

#endif
