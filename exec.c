/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:54:50 by aroualid          #+#    #+#             */
/*   Updated: 2024/03/22 19:04:08 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env, char *av)
{
	char **folders = NULL;
	char *path = NULL;
	char *endfile = NULL;
	
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_strlen(env[i]) <= 4 || ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	if (env[i] == NULL)
		return NULL;
	folders = ft_split(env[i], ':');
	endfile = ft_strjoin("/", *find_cmd(av));
	while (folders[j])
	{
		path = ft_strjoin(folders[j], endfile);
		if (access(path, F_OK | X_OK) == 0)
			return (free(endfile), ft_free(folders), path);
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

int	apply_exec(char *path, char **cmd, char **env)
{
	return(execve(path, cmd, env));
}
