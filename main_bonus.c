/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:43:50 by mgaldino          #+#    #+#             */
/*   Updated: 2022/08/04 16:09:58 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_here_doc(char *limiter)
{
	char	*s;
	int		fd;

	fd = open("myfile", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd == -1)
		fd = open("myfile", O_WRONLY | O_TRUNC);
	if (fd != -1)
	{
		s = get_next_line(STDIN_FILENO);
		while (ft_strcmp(s, limiter))
		{
			write(fd, s, ft_strlen(s));
			free(s);
			s = get_next_line(STDIN_FILENO);
		}
		close(fd);
		fd = open("myfile", O_RDONLY);
	}
	else
		write(1, "Problem creating/opening buffer input file!\n", 44);
	return (fd);
}

int	ft_write_outfile(void)
{
	char	*s;

	s = get_next_line(STDIN_FILENO);
	while (s)
	{
		write(STDOUT_FILENO, s, ft_strlen(s));
		free(s);
		s = get_next_line(STDIN_FILENO);
	}
	return (0);
}

void	ft_get_fd1(int *fd1, int *first_cmd, char *argv[], int argc)
{
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		if (argc < 6)
		{
			write(1, "Too few arguments!\n", 19);
			*fd1 = -2;
			return ;
		}
		*fd1 = ft_here_doc(ft_strjoin(argv[2], "\n"));
		*first_cmd = 2;
	}
	else
	{
		*fd1 = -1;
		if (!access(argv[1], F_OK))
		{
			if (!access(argv[1], R_OK))
				*fd1 = open(argv[1], O_RDONLY);
			else
				write(1, "Input file cannot be read!\n", 27);
		}
		else
			write(1, "Input file not found!\n", 22);
		*first_cmd = 1;
	}
}

int	ft_get_fd2(int argc, char *argv[])
{
	int	fd2;

	fd2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd2 == -1)
	{	
		if (access(argv[argc - 1], F_OK) == -1)
			write(1, "Problem creating outfile!\n", 26);
		else
			write(1, "Outfile cannot be written!\n", 27);
	}
	return (fd2);
}

int	main(int argc, char *argv[])
{
	int	fd1;
	int	fd2;
	int	first_cmd;
	int	cmd_status;

	if (argc < 5)
	{
		write(1, "You must enter at least 4 arguments.\n", 37);
		return (1);
	}
	fd2 = ft_get_fd2(argc, argv);
	ft_get_fd1(&fd1, &first_cmd, argv, argc);
	if ((fd1 == -2) || (fd2 == -1))
		return (1);
	if (fd1 == -1)
		fd1 = open("/dev/null", O_RDONLY);
	dup2(fd2, STDOUT_FILENO);
	close(fd2);
	dup2(fd1, STDIN_FILENO);
	close(fd1);
	cmd_status = ft_command(argc, argv, first_cmd);
	ft_write_outfile();
	return (cmd_status);
}
