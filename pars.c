/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:54:50 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/03 16:52:58 by aroualid         ###   ########.fr       */
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


