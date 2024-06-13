/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_exec_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:51:02 by aroualid          #+#    #+#             */
/*   Updated: 2024/06/13 12:02:39 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	apply_exec_first_bns(char *av, char **env, char *file, int pip[2])
{
	char	*path;
	char	**cmd;
	int		infile;
	
	infile = open(file, O_RDONLY);
	if (infile == -1)
		perror("");
	path = find_path(env, av);
	cmd = find_cmd(av);
	if (dup2(infile, STDIN_FILENO) == -1)
		perror("");
	if (dup2(pip[1], STDOUT_FILENO) == -1)
		perror("");
	ft_close(pip, infile);
	if (execve(path, cmd, env) == -1)
	{
		free (path);
		ft_free (cmd);
		exit(-1);
	}
	free (path);
	ft_free (cmd);
}

void	apply_exec_middle_bonus(int fd, int pip[2], char **env, char *av)
{
	char	*path;
	char	**cmd;
	if (dup2(fd, STDIN_FILENO) == -1)
		perror("");
	if (dup2(pip[1], STDOUT_FILENO) == -1)
		perror("");
	close(fd);
	close(pip[1]);
	path = find_path(env, av);
	cmd = find_cmd(av);
	if (execve(path, cmd, env) == -1)
	{
		close (pip[0]);
		free (path);
		ft_free (cmd);
		exit(-1);
	}
	ft_free(cmd);
	free(path);
}

void	apply_exec_last_bns(char *av, char **env, char *file, int fd)
{
	char	*path;
	char	**cmd;
	int		outfile;

	outfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile == -1)
		perror("");
	path = find_path(env, av);
	cmd = find_cmd(av);
	if (dup2(fd, STDIN_FILENO) == -1)
		perror("");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		perror("");
	close (fd);
	close (outfile);
	if (execve(path, cmd, env) == -1)
	{
		free (path);
		ft_free (cmd);
		exit(-1);
	}
	free (path);
	ft_free (cmd);
}
