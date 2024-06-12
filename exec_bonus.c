/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:09:47 by aroualid          #+#    #+#             */
/*   Updated: 2024/06/12 14:53:26 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_first(char *av, char **env, char *file)
{
	char	*path;
	char	**cmd;
	int		infile;
	int		id;
	int		pip[2];

	if (pipe(pip) == -1)
		perror("pip error");
	id = fork();
	if (id == -1)
		perror("fork error");
	if (id == 0)
	{
		infile = open(file, O_RDONLY);
		if (infile == -1)
			perror("infile error");
		path = find_path(env, av);
		cmd = find_cmd(av);
		apply_exec_first_bonus(infile, pip);
		if (execve(path, cmd, env) == -1)
			perror("exec error 1");
	}
	close(pip[1]);
	return (pip[0]);
}

int	exec_midle(char *av, char **env, int fd)
{
	char	*path;
	char	**cmd;
	int		id;
	int		pip[2];

	if (pipe(pip) == -1)
		exit(EXIT_FAILURE);
	id = fork();
	if (id == -1)
		perror("fork error");
	if (id == 0)
	{
		close(pip[0]);
		path = find_path(env, av);
		cmd = find_cmd(av);
		apply_exec_middle_bonus(fd, pip);
		if (execve(path, cmd, env) == -1)
			perror("exec error");
	}
	close(pip[1]);
	close(fd);
	return (pip[0]);
}

void	exec_last(char *av, char **env, char *file, int fd)
{
	char	*path;
	char	**cmd;
	int		outfile;
	int		id;

	id = fork();
	if (id == -1)
		perror("id error");
	outfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile == -1)
		perror("outfile error");
	if (id == 0)
	{
		path = find_path(env, av);
		cmd = find_cmd(av);
		apply_exec_last_bonus(fd, outfile);
		if (execve(path, cmd, env) == -1)
			perror("exec error");
	}
	close(outfile);
	close(fd);
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	pipout;

	i = 2;
	pipout = 42;
	while (i < ac - 1)
	{
		if (i == 2)
			pipout = exec_first(av[2], env, av[1]);
		else if (i == ac - 2)
			exec_last(av[ac - 2], env, av[ac - 1], pipout);
		else if (i > 2 && i < ac - 2)
			pipout = exec_midle(av[i], env, pipout);
		i++;
	}
	while (wait(NULL) > 0)
		;
	close (pipout);
}
