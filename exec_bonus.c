/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:34:50 by aroualid          #+#    #+#             */
/*   Updated: 2024/03/25 16:52:53 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	apply_bonus(int i, int ac, char *av[], char **env)
{
	int		fd[ac-3];
	int		id;
	while (i <= ac -1)
	{
		id = fork();
		if (id == 0)
		{
			apply_exec(av, i, ac, env);
		}
	}

}

int	apply_exec(char *av[], int i, int ac, char **env)
{
	char	*path;
	char	**cmd;
	int		infile;
	int		outfile;
	int		fd[i];
	
	outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	infile = open(av[1], O_RDONLY);
	path = find_path(env, av[2]);
	cmd = find_cmd(av[2]);

}
