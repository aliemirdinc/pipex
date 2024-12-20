/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:56:27 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/20 20:52:14 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	input_file;

	input_file = open(argv[1], O_RDONLY, 0444);
	if (input_file == -1)
		error("Unable to open input_file", 1);
	dup2(input_file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	out_file;

	out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_file == -1)
		error("Unable to open outFile", 1);
	dup2(fd[0], STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putendl_fd("------------- ERROR ------------", 1);
		ft_putendl_fd("$./pipex infile cmd1 cmd2 outfile", 1);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		error("Pipe creation failed", 1);
	pid = fork();
	if (pid == -1)
		error("Fork failed!", 1);
	if (pid == 0)
		child_process(argv, envp, fd);
	waitpid(-1, NULL, 0);
	if (pid != 0)
		parent_process(argv, envp, fd);
	return (0);
}
