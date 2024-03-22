/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:18:21 by aroualid          #+#    #+#             */
/*   Updated: 2024/03/22 13:52:56 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **env)
{
	int id;
	int id2;

	id = 0;
	id2 = 0;
	if (ac != 5)
		return (0);
	else
	{	
		char *path2 = find_path(env, av[2]);
		char *path3 = find_path(env, av[3]);
		char **cmd2 = find_cmd(av[2]);
		char **cmd3 = find_cmd(av[3]);
		id = fork ();
		if (id == 0)
		{
			apply_exec(path2, cmd2, env);
		}
		id2 = fork();
		if (id2 == 0)
		{
			apply_exec(path3, cmd3, env);
		}
	}
}
