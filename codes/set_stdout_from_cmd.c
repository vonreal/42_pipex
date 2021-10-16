/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stdout_from_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:40:36 by jna               #+#    #+#             */
/*   Updated: 2021/10/16 16:15:25 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	set_stdout_from_cmd(char *cmd, t_info *infos, int idx, char *envp[])
{
	pid_t	pid;
	int		i;
	char	**cmds;
	char	*path;

	if ((pid = fork()) < 0)
		return (error_msg("[ERROR] Fail to fork()\n"));
	if (pid == 0)
	{
		dup2(infos->fds[idx][1], STDOUT_FILENO);
		if (!ft_strchr(cmd, ' '))
			cmd = ft_strjoin(cmd, " ");
		cmds = ft_split(cmd, ' ');
		
		i = 0;
		while (infos->paths[i])
		{
			path = ft_strjoin(infos->paths[i], "/");
			path = ft_strjoin(path, cmds[0]);
			execve(path, cmds, envp);
			i++;
		}
		return (-1);
	}
	else
	{
		close(infos->fds[idx][1]);
		dup2(infos->fds[idx][0], STDIN_FILENO);
		close(infos->fds[idx][0]);
	}
	return (1);
}
