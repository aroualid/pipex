/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:34:36 by aroualid          #+#    #+#             */
/*   Updated: 2024/06/13 15:40:40 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_first(char *av, char **env, char *file)
{
	int		id;
	int		pip[2];
	char	*path;
	char	**cmd;
	int		infile;

	if (pipe(pip) == -1)
		perror("");
	id = fork();
	if (id == -1)
		perror("");
	if (id == 0)
	{
		infile = check_infile(file);
		if (infile == -1)
			exit_close(pip);
		close(infile);
		path = find_path(env, av);
		cmd = find_cmd(av);
		if (path != NULL && cmd != NULL)
			apply_exec_first(av, env, file, pip);
		free_all(path, cmd);
		exit_close(pip);
	}
	return (close(pip[1]), pip[0]);
}

void	apply_exec_first(char *av, char **env, char *file, int pip[2])
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

void	exec_last(char *av, char **env, char *file, int fd)
{
	int		id;
	char	*path;
	char	**cmd;
	int		outfile;

	outfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile == -1)
		perror("");
	id = fork();
	if (id == -1)
		perror("");
	if (id == 0)
	{
		path = find_path(env, av);
		cmd = find_cmd(av);
		if (path != NULL && cmd != NULL)
			apply_exec_last(av, env, outfile, fd);
		close (outfile);
		ft_free(cmd);
		free(path);
		close (fd);
		exit (-1);
	}
	close (fd);
	close (outfile);
}

void	apply_exec_last(char *av, char **env, int outfile, int fd)
{
	char	*path;
	char	**cmd;

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

int	main(int ac, char **av, char **env)
{
	int	i;
	int	pipeout;

	i = 2;
	pipeout = 42;
	if (ac != 5)
		return (write(2, "need 5 arguments\n", 17));
	while (i < ac - 1)
	{
		if (i == 2)
			pipeout = exec_first(av[2], env, av[1]);
		else
			exec_last(av[3], env, av[4], pipeout);
		i++;
	}
	while (wait(NULL) > 0)
		;
}
