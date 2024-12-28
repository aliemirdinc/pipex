/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:09:50 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/23 20:08:57 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	error(char *err_message)
{
	ft_putendl_fd(err_message, 2);
	exit(EXIT_FAILURE);
}

void	input_error(void)
{
	ft_putendl_fd("------------------ ERROR ------------------", 1);
	ft_putendl_fd("$ ./pipex infile cmd1 cmd2 ... cmdn outfile", 1);
	ft_putendl_fd("$ ./pipex here_doc LIMITER cmd1 cmd2 file", 1);
	exit(EXIT_FAILURE);
}
