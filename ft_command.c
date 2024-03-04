/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:43:25 by mgaldino          #+#    #+#             */
/*   Updated: 2022/08/04 14:43:29 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_command(int argc, char *argv[], int first)
{
	int	fd[2];
	int	wstatus;
	int	pid;

	while (++first < (argc - 1))
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			ft_bash(argv[first]);
		}
		else
		{
			waitpid(pid, &wstatus, 0);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			close(fd[1]);
		}
	}
	return (WEXITSTATUS(wstatus));
}
