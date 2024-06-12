/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_exec_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:51:02 by aroualid          #+#    #+#             */
/*   Updated: 2024/06/12 14:52:25 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	apply_exec_first_bonus(int infile, int pip[2])
{
	if (dup2(infile, STDIN_FILENO) == -1)
		perror("DUP 2 error 1.1");
	if (dup2(pip[1], STDOUT_FILENO) == -1)
		perror("DUP 2 error 1.2");
	close (infile);
	close (pip[0]);
	close (pip[1]);
}

void	apply_exec_middle_bonus(int fd, int pip[2])
{
	if (dup2(fd, STDIN_FILENO) == -1)
		perror("DUP 2 error 1.1");
	if (dup2(pip[1], STDOUT_FILENO) == -1)
		perror("DUP 2 error 1.2");
	close(fd);
	close(pip[1]);
}

void	apply_exec_last_bonus(int fd, int outfile)
{
	if (dup2(fd, STDIN_FILENO) == -1)
		perror("DUP 2 error 1.1");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		perror("DUP 2 error 1.2");
	close (fd);
	close (outfile);
}
