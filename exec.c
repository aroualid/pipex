/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:54:50 by aroualid          #+#    #+#             */
/*   Updated: 2024/03/24 03:17:33 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env, char *av)
{
	char **folders = NULL;
	char *path = NULL;
	char *endfile = NULL;
	char **cmd = NULL;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_strlen(env[i]) <= 4 || ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	if (env[i] == NULL)
		return NULL;
	folders = ft_split(env[i], ':');
	cmd = find_cmd(av);
	endfile = ft_strjoin("/", *cmd);
	while (folders[j])
	{
		path = ft_strjoin(folders[j], endfile);
		if (access(path, F_OK | X_OK) == 0)
			return (free(endfile), ft_free(folders), ft_free(cmd), path);
		else
		{
			free(path);
			j++;
		}
	}
	return (free(endfile), ft_free(folders),
		write (1, "command not found : ", 21), 
		write(1, av, ft_strlen(av)), NULL);
}


char	**find_cmd(char *av)
{
	char **cmd;

	cmd = ft_split(av, ' ');
	if (cmd)
		return (cmd);
	return (ft_free(cmd), NULL);	
}

int	apply_exec2(char *av[], int fd[2], char **env)
{
	char	*path;
	char	**cmd;
	int		infile;
	int		outfile;

	infile = open(av[1], O_RDONLY);
	outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);

	path = find_path(env, av[2]);
	cmd = find_cmd(av[2]);
	dup2(infile,  STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close (infile);
	close (outfile);
	close (fd[0]);
	close (fd[1]);
	return(execve(path, cmd, env));
}


int	apply_exec3(char *av[], int fd[2], char **env)
{	
	char	*path;
	char	**cmd;
	int		infile;
	int		outfile;

	infile = open(av[1], O_RDONLY);
	outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	path = find_path(env, av[3]);
	cmd = find_cmd(av[3]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close (infile);
	close (outfile);
	close (fd[0]);
	close (fd[1]);
	return(execve(path, cmd, env));
}
