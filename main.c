/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:18:21 by aroualid          #+#    #+#             */
/*   Updated: 2024/03/24 22:36:24 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include <unistd.h>

int	main(int ac, char **av, char **env)
{
	int	id;
	int	id2;

	id = 0;
	id2 = 0;
	if (ac != 5)
		return (0);
	else
		apply_func(id, id2, av, env);
}
