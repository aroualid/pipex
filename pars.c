/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:54:50 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/12 13:57:30 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*char	*find_path(char **env, char *av)
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
}*/

char	**get_folders_from_path(char **env)
{
	int		i;
	char	**folders;

	i = 0;
	folders = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			folders = ft_split(env[i] + 5, ':');
			break ;
		}
		i++;
	}
	return (folders);
}

char	*find_path_in_folders(char **folders, char *av)
{
	char	*path;
	char	*endfile;
	char	**cmd;
	int		j;

	path = NULL;
	endfile = NULL;
	cmd = find_cmd(av);
	j = 0;
	if (cmd == NULL)
		return (NULL);
	endfile = ft_strjoin("/", *cmd);
	while (folders[j])
	{
		path = ft_strjoin(folders[j], endfile);
		if (access(path, F_OK | X_OK) == 0)
			return_path (cmd, endfile, path);
		free(path);
		j++;
	}
	ft_free(cmd);
	free(endfile);
	return (NULL);
}

char	*find_path(char **env, char *av)
{
	char	**folders;
	char	*path;

	folders = get_folders_from_path(env);
	if (folders == NULL)
	{
		write(1, "PATH environment variable not found\n", 36);
		return (NULL);
	}
	path = find_path_in_folders(folders, av);
	ft_free(folders);
	if (path == NULL)
	{
		write(1, "command not found : ", 21);
		write(1, av, ft_strlen(av));
		write(1, "\n", 1);
	}
	return (path);
}

char	**find_cmd(char *av)
{
	char	**cmd;

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
