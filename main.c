/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:18:21 by aroualid          #+#    #+#             */
/*   Updated: 2024/03/22 18:15:12 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include <unistd.h>

int main(int ac, char **av, char **env)
{
	int id;
	int id2;

	id = 0;
	id2 = 0;
	int fd[2];
	int infile;
	int outfile;
	if (ac != 5)
		return (0);
	else
	{
		infile = open(av[1], O_RDONLY);
		outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		char *path2 = find_path(env, av[2]);
		char **cmd2 = find_cmd(av[2]);
		char *path3 = find_path(env, av[3]);
		char **cmd3 = find_cmd(av[3]);
		if (pipe(fd) == -1)
			printf ("ERROR");
		id = fork ();
		if (id == 0)
		{
			dup2(infile,  STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			close (infile);
			close (fd[0]);
			close (fd[1]);
			apply_exec(path2, cmd2, env);
		}
		id2 = fork();
		if (id2 == 0)
		{
			printf("TEST");
			dup2(fd[0], STDIN_FILENO);
			dup2(outfile, STDOUT_FILENO);
			close (infile);
			close (outfile);
			close (fd[0]);
			close (fd[1]);
			apply_exec(path3, cmd3, env);
		}

		wait(NULL);
	}
}
