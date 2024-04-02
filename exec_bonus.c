/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:34:50 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/02 17:02:12 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int apply_exec(char *av, int pipe[2], char **env)
{
	char	*path;
	char	**cmd;
	int		pid;
	
	wait (NULL);
	pid = fork();
	if (pid == -1)
		printf("PID ERROR 1");
	if (pid == 0)
	{
		path = find_path(env, av);
		cmd = find_cmd(av);
		if(dup2(pipe[0],  STDIN_FILENO) == -1)
			printf("DUP 2 error 1.1");
		if(dup2(pipe[1], STDOUT_FILENO) == -1)
			printf("DUP 2 error 1.2");
		close (pipe[0]);
		close (pipe[1]);
		if (execve(path, cmd, env) == -1)
			printf("exec error 1");
	}
	return (0);
}


int	apply_exec_first(char *av[], int fd[2], char **env)
{
	char	*path;
	char	**cmd;
	int		infile;
	int		pid;

	pid = fork();
	if (pid == -1)
		printf("PID ERROR 2");
	if (pid == 0)
	{
		infile = open(av[1], O_RDONLY);
		if (infile == -1)
			printf("ERROR INFILE");
		path = find_path(env, av[2]);
		cmd = find_cmd(av[2]);
		if (dup2(infile,  STDIN_FILENO) == -1)
			printf("DUP 2 error 2.1");
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			printf("DUP 2 error 2.2");
		close (infile);
		close (fd[0]);
		close (fd[1]);
		if (execve(path, cmd, env) == -1)
			printf("exec error 2");
	}
	return (0);
}

int	apply_exec_end(char *av[], int fd[2], char **env, int ac)
{	
	char	*path;
	char	**cmd;
	int		outfile;
	int		pid;

	wait (NULL);
	pid = fork();
	if (pid == -1)
		printf("PID ERROR 3");
	if (pid == 0)
	{
		outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (outfile == -1)
			printf("outfile error");
		path = find_path(env, av[ac - 2]);
		cmd = find_cmd(av[ac - 2]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			printf("DUP 2 error 3.1");
		if (dup2(outfile, STDOUT_FILENO) == -1)
			printf("DUP 2 error 3.2");
		close (outfile);
		close (fd[0]);
		close (fd[1]);
		if (execve(path, cmd, env) == -1)
			printf("exec error 3");
	}
	return(0);
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int fd[2];
	
	i = 2;
	if(pipe(fd) == -1)
		printf("PIPEERROR");
	while (i < ac - 1)
	{
		if (i == 2)
		{
			printf("1");
			printf(" %s\n", av[i]);
			apply_exec_first(av, fd, env);
		}
		else if (i == ac - 2)
		{
			printf("3");
			printf(" %s\n", av[i]);
			apply_exec_end(av, fd, env, ac);
		}
		else
		{
			printf("2");
			printf(" %s\n", av[i]);
			apply_exec(av[i], fd, env);
		}

		i++;
	}
	while (wait(NULL))
		;

}
