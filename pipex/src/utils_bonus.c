/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:56:35 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/23 20:09:09 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}

char	*find_pathc(char *cmd)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*path_part;

	if (find_pathc(cmd))
		return (find_pathc(cmd));
	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_part = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(path, F_OK) == 0)
			return (free_cmd(paths), path);
		free(path);
		i++;
	}
	return (free_cmd(paths), NULL);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		result;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	if (!cmd)
		error("command splitting failed");
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd);
		error("command not found in PATH");
	}
	result = execve(path, cmd, envp);
	free(path);
	i = -1;
	while (cmd[++i])
		free(cmd);
	if (result == -1)
		error("execve failed");
}
