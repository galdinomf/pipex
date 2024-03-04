/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:42:18 by mgaldino          #+#    #+#             */
/*   Updated: 2022/05/13 04:14:37 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*buf;
	static char	*acc;
	int			i;
	char		*result;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buf = (char *) malloc(BUFFER_SIZE + 1);
	bytes_read = ft_initialize_and_get_line(fd, buf, &acc);
	if ((bytes_read < 0) || (!acc[0]))
	{
		free (acc);
		acc = NULL;
		return (NULL);
	}
	else
	{
		i = -1;
		while ((acc[++i] != '\n') && (acc[i]))
			;
		result = ft_substr(acc, 0, i + 1);
		acc = ft_extract_remainder_bytes_from_line(acc);
		return (result);
	}
}
