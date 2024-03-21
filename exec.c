/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:54:50 by aroualid          #+#    #+#             */
/*   Updated: 2024/03/21 14:14:42 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *find_path(char **env, char *av)
{
	char **folders = NULL;
	char *path = NULL;
	char *endfile = NULL;
	
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_strlen(env[i]) <= 5 || ft_strncmp(env[i], "PATH", 5) != 0)
		i++;
	folders = ft_split(env[i], ':');
	endfile = ft_strjoin("/", av);
	while (folders[j])
	{
		path = ft_strjoin(folders[j], endfile);
		if (access(path, F_OK | X_OK))
			return (path);
		else
			i++;
	}
	return (write (1, "command not found : ", 21), 
		write(1, av, ft_strlen(av)), NULL);
}
