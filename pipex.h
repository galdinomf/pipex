/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:44:02 by mgaldino          #+#    #+#             */
/*   Updated: 2022/08/04 14:44:38 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		ft_bash(char *cmd);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_command(int argc, char *argv[], int first);
char	*get_next_line(int fd);
int		ft_char_in_buffer(char c, char *buf);
char	*ft_accumulate_buffer(char *acc, char *buf, int bytes_read);
char	*ft_extract_remainder_bytes_from_line(char *acc);
int		ft_initialize_and_get_line(int fd, char *buf, char **acc);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
