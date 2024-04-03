/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:09:47 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/03 19:13:25 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int exec_first(char *av, char **env, char *file)
{
	char	*path;
	char	**cmd;
	int		infile;
	int		id;
	int		pip[2];


	if (pipe(pip) == -1)
		perror("ta mere");
	id = fork();
	printf("in first child ID == %d\n", id);
	if (id == -1)
		perror("UwU");
	if (id == 0)
	{
		infile = open(file, O_RDONLY);
		printf("infile name is == %s and fd is %d\n", file, pip[1]);
		if (infile == -1)
			perror("okay okay");
		path = find_path(env, av);
		cmd = find_cmd(av);
		if(dup2(infile, STDIN_FILENO) == -1)
			printf("DUP 2 error 1.1");
		if(dup2(pip[1], STDOUT_FILENO) == -1)
			printf("DUP 2 error 1.2");
		close (infile);
		close (pip[0]);
		close (pip[1]);
		if (execve(path, cmd, env) == -1)
			printf("exec error 1");
	}
	close(pip[1]);
	return (pip[0]);
}


void	exec_last(char *av, char **env, char *file, int fd)
{
	char	*path;
	char	**cmd;
	int		outfile;
	int		id;


	id = fork();
	printf("in second child ID == %d\n", id);
	if (id == -1)
		perror("UwU");
	if (id == 0)
	{
		outfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		printf("outfile name is == %s and fd is %d\n", file, fd);
		if (outfile == -1)
			perror("okay okay");
		path = find_path(env, av);
		cmd = find_cmd(av);
		if(dup2(fd, STDIN_FILENO) == -1)
			printf("DUP 2 error 1.1");
		if(dup2(outfile, STDOUT_FILENO) == -1)
			printf("DUP 2 error 1.2");
		close (fd);
		close (outfile);
		if (execve(path, cmd, env) == -1)
			printf("exec error 1");
	}
	close(fd);
}

int main (int ac, char **av, char **env)
{
	int i = 2;
	int pipout = 42;
	if (ac != 5)
		return (printf("TA MERE"));
	while (i < ac - 1)
	{
		if (i == 2)
			pipout = exec_first(av[2], env, av[1]);
		else
			exec_last(av[3], env, av[4], pipout);
		i++;
	}
	while (wait(NULL) > 0)
		;
}
