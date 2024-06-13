/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:30:04 by aroualid          #+#    #+#             */
/*   Updated: 2024/06/13 14:30:25 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_close(int pip[2])
{
	close(pip[1]);
	close(pip[0]);
	exit (-1);
}

void	free_all(char *path, char **cmd)
{
	ft_free(cmd);
	free(path);
}

char	*free_return(char **cmd, char *endfile)
{	
	ft_free(cmd);
	free(endfile);
	return (NULL);
}
