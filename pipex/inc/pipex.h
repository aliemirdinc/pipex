/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:56:05 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/20 21:14:05 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libs/libft/libft.h"
# include "sys/wait.h"
# include "fcntl.h"

void	execute(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);
void	error(char *err_msg, int status);

#endif
