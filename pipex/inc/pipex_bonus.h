/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:55:59 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/20 14:56:01 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libs/libft/libft.h"
# include "sys/wait.h"
# include "fcntl.h"

void	input_error(void);
void	error(char *error_message);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);

#endif