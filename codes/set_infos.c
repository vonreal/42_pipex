/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:47:35 by jna               #+#    #+#             */
/*   Updated: 2021/10/17 02:53:02 by jna              ###   ########.fr       */
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

	fd_infile = open(infile, O_RDONLY);
	fd_outfile = \
			open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd_infile < 0 || fd_outfile < 0)
		exit(0);
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
		exit(0);
	return (paths);
}
