/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:43:21 by mgaldino          #+#    #+#             */
/*   Updated: 2022/08/04 14:43:22 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_bash(char *cmd)
{
	char	**argv2;

	argv2 = (char **) malloc(4 * sizeof(char *));
	argv2[0] = "./pipex";
	argv2[1] = "-c";
	argv2[2] = cmd;
	argv2[3] = NULL;
	execve("/usr/bin/bash", argv2, NULL);
	return (0);
}
