/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:01:47 by aroualid          #+#    #+#             */
/*   Updated: 2024/03/23 17:45:08 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		t1;
	int		t2;
	char	*ptr;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = 0;
	i = 0;
	t1 = ft_strlen(s1);
	t2 = ft_strlen(s2);
	ptr = ft_calloc(t1 + t2 + 1, 1);
	if (!ptr)
		return (free (ptr), NULL);
	while (i < (t1 + t2))
	{
		while (i < t1)
			if (i++ >= 0)
				ptr[i - 1] = s1[i - 1];
		while (j < t2)
			ptr[i++] = s2[j++];
	}
	return (ptr);
}
