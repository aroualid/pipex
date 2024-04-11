/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:54:50 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/11 14:51:14 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env, char *av)
{
	char	**folders;
	char	*path;
	char	*endfile;
	char	**cmd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	folders = NULL;
	path = NULL;
	endfile = NULL;
	cmd = NULL;
	while (ft_strlen(env[i]) <= 4 || ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	if (env[i] == NULL)
		return NULL;
	folders = ft_split(env[i], ':');
	cmd = find_cmd(av);
	if (cmd != NULL)
	{
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
	}
	return (free(endfile), ft_free(folders), ft_free(cmd), write (1, "command not found : ", 21), write(1, av, ft_strlen(av)), write (1, "\n", 1), NULL);
}

/*char	**get_path_folders(char **env)
{
	int		i;

	i = 0;
	while (ft_strlen(env[i]) <= 4 || ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	if (env[i] == NULL)
		return NULL;
	return ft_split(env[i], ':');
}

char	*get_command_path(char **folders, char *av)
{
	char	*endfile;
	char	**cmd;
	int		j;
	char	*path;

	j = 0;
	cmd = find_cmd(av);
	endfile = ft_strjoin("/", *cmd);
	while (folders[j])
	{
		path = ft_strjoin(folders[j], endfile);
		if (access(path, F_OK | X_OK) == 0)
			return path;
		else
		{
			free(path);
			j++;
		}
	}
	return NULL;
}

char	*find_path(char **env, char *av)
{
	char	**folders;
	char	*path;

	folders = get_path_folders(env);
	if (folders == NULL)
		return (write(1, "command not found : ", 21), 
			write(1, av, ft_strlen(av)), NULL);
	path = get_command_path(folders, av);
	ft_free(folders);
	if (path == NULL)
		return (write(1, "command not found : ", 21), 
			write(1, av, ft_strlen(av)), NULL);
	return path;
}*/

char	**find_cmd(char *av)
{
	char **cmd;

	if (av != NULL)
	{	
		cmd = ft_split(av, ' ');
			if (cmd)
				return (cmd);
			else 
				return (ft_free(cmd), NULL);	
	}
	return (NULL);
}
