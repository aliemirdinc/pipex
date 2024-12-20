/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:56:10 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/20 19:17:53 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	error(char *err_message)
{
	ft_putendl_fd(err_message, 1);
	exit(EXIT_FAILURE);
}

void	input_error(void)
{
	ft_putendl_fd("------------------ ERROR ------------------", 1);
	ft_putendl_fd("$ ./pipex infile cmd1 cmd2 ... cmdn outfile", 1);
	ft_putendl_fd("$ ./pipex here_doc LIMITER cmd1 cmd2 file", 1);
	exit(EXIT_FAILURE);
}
