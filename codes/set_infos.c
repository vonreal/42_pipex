/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:47:35 by jna               #+#    #+#             */
/*   Updated: 2021/10/16 16:17:46 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**set_paths(char *envp[])
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	paths = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			path = ft_strchr(envp[i], '=') + 1;
			paths = ft_split(path, ':');
			break ;
		}
		i++;
	}
	return (paths);
}

int	set_cmd(char *cmd, char *argv[], int i)
{
	char	*temp;

	if (argv[i][0] != '-')
	{
		temp = cmd;
		cmd = ft_strdup(argv[i]);
		free(temp);
		i++;
		while (argv[i][0] == '-')
		{
			temp = cmd;
			cmd = ft_strjoin(cmd, " ");
			free(temp);
			temp = cmd;
			cmd = ft_strjoin(cmd, argv[i]);
			free(temp);
			i++;
		}
	}
	return (i);
}

static char	**set_cmds(int argc, char *argv[])
{
	int		i;
	char	*cmd;
	char	*cmds;
	char	*temp;
	char	**result;

	if (argc < 4)
		return (0);
	i = 2;
	cmds = ft_strdup("");
	while (i < argc - 1)
	{
		if (argv[i][0] != '-')
		{
			cmd = ft_strdup(argv[i]);
			i++;
			while (argv[i][0] == '-' && i < argc - 1)
			{
				temp = cmd;
				cmd = ft_strjoin(cmd, " ");
				free(temp);
				
				temp = cmd;
				cmd = ft_strjoin(cmd, argv[i]);
				free(temp);
				i++;
			}
		}
		temp = cmds;
		cmds = ft_strjoin(cmds, cmd);
		free(temp);

		temp = cmds;
		cmds = ft_strjoin(cmds, ",");
		free(temp);
	}
	result = ft_split(cmds, ',');
	free(cmds);
	return (result);
}

int	set_fd(t_info *infos, char *infile, char *outfile)
{
	int fd_infile;
	int fd_outfile;

	if (access(infile, R_OK) < 0)
		return (-1);
	if ((fd_infile = open(infile, O_RDONLY)) < 0)
		return (-1);
	if ((fd_outfile = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
		return (-1);
	infos->fd_infile = fd_infile;
	infos->fd_outfile = fd_outfile;
	return (0);
}

t_info	set_infos(int argc, char *argv[], char *envp[])
{
	t_info	infos;

	if (argc < 4)
	{
		exit(0);
		printf("ARG ERROR\n");
	}
	if (set_fd(&infos, argv[1], argv[argc -1]) < 0)
	{
		printf("FILE ERROR\n");
		exit (0);
	}
	infos.paths = set_paths(envp);
	infos.cmds = set_cmds(argc, argv);
	infos.fds = set_fds(infos.cmds);
	return (infos);
}
