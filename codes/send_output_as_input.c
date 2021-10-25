/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stdout_from_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:40:36 by jna               #+#    #+#             */
/*   Updated: 2021/10/18 19:54:41 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_input_from_infile(int fd_infile)
{	
	if (fd_infile >= 0)
	{
		if (dup2(fd_infile, STDIN_FILENO) < 0)
			exit(0);
	}
}

void	save_output_to_outfile(int *fd, int fd_outfile)
{
	fd[READ] = 0;
	fd[WRITE] = fd_outfile;
}

void	send_output_as_input(t_info *infos, int idx, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(-1);
	if (pid == 0)
	{
		close(STDERR_FILENO);
		dup2(infos->fds[idx][WRITE], STDOUT_FILENO);
		execve_cmd(infos->cmds[idx], infos->paths, envp);
		exit(0);
	}
	else
	{
		close(infos->fds[idx][WRITE]);
		dup2(infos->fds[idx][READ], STDIN_FILENO);
		close(infos->fds[idx][READ]);
	}
}

void	execve_cmd(char *cmd, char **paths, char *envp[])
{
	char	**cmds;
	char	*path;
	int		i;

	if (!ft_strchr(cmd, ' '))
		cmd = ft_strjoin(cmd, " ");
	cmds = ft_split(cmd, ' ');
	free(cmd);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, cmds[0]);
		execve(path, cmds, envp);
		i++;
	}
}
