/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:54:55 by aroualid          #+#    #+#             */
/*   Updated: 2024/03/25 15:29:07 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **tav)
{
	int	i;

	i = 0;
	if (tav != NULL)
	{
		while (tav[i] != NULL)
		{
			free(tav[i]);
			i++;
		}
		free(tav);
	}
}

void	free_pipe_fd(int fd[2], char *av[], char **env)
{
	int		i;
	char	*path;
	char	**cmd;

	i = 2;
	close (fd[0]);
	close (fd[1]);
	while (i <= 3)
	{
		path = find_path(env, av[i]);
		cmd = find_cmd(av[i]);
		free (path);
		ft_free (cmd);
		i++;
	}
}

void	apply_func(int id, int id2, char *av[], char **env)
{
	int	fd[2];

	if (pipe(fd) == -1)
		free_pipe_fd(fd, av, env);
	id = fork ();
	if (id == 0)
		apply_exec2(av, fd, env);
	id2 = fork();
	if (id2 == 0)
		apply_exec3(av, fd, env);
	wait(NULL);
	close (fd[0]);
	close (fd[1]);
}
