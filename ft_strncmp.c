/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:32:00 by aroualid          #+#    #+#             */
/*   Updated: 2024/03/21 13:58:14 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp( const char *first, const char *second, size_t length)
{
	unsigned int	i;

	i = 0;
	if (length == 0)
		return (0);
	while (first[i] == second[i] && i < length - 1 && first[i])
	{
		i++;
	}
	return (((unsigned char *)first)[i] - ((unsigned char *)second)[i]);
}
