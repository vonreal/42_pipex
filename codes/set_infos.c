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

t_info	set_infos(int argc, char *argv[], char *envp[])
{
	t_info	infos;

	set_fd(&infos, argv[1], argv[argc - 1]);
	infos.paths = get_paths(envp);
	infos.cmds = get_cmds(argc - 1, argv);
	infos.fds = get_fds(get_size_char_arr2(infos.cmds));
	return (infos);
}

void	set_fd(t_info *infos, char *infile, char *outfile)
{
	int	fd_infile;
	int	fd_outfile;

	if ((fd_infile = open(infile, O_RDONLY)) < 0)
	{
		perror("File open error.\n");
		exit(-1);
	}
	if ((fd_outfile = \
			open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
	{
		perror("File open error.\n");
		exit(-1);
	}
	infos->fd_infile = fd_infile;
	infos->fd_outfile = fd_outfile;
}

char	**get_paths(char *envp[])
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
	if (paths == NULL)
	{
		write(STDERR_FILENO, "No 'PATH' in environment.\n", 27);
		exit(-1);
	}
	return (paths);
}
