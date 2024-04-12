/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:38:21 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/12 15:19:56 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **tav)
{
	int	i;

	i = 0;
	if (tav != NULL)
	{
		while (tav[i] != NULL)
		{
			free(tav[i]);
			i++;
		}
		free(tav);
	}
}

void	ft_close(int pip[2], int infile)
{
	close (pip[1]);
	close (pip[0]);
	close (infile);
}

char	*return_path(char **cmd, char *endfile, char *path)
{
	ft_free(cmd);
	free(endfile);
	return (path);
}
