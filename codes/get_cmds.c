/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 23:26:29 by jna               #+#    #+#             */
/*   Updated: 2021/10/17 02:52:22 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*strdup_and_inc(char *s1, int *idx)
{
	char	*src;

	src = ft_strdup(s1);
	*idx += 1;
	return (src);
}

static char	*ft_strjoins(char *src, char *append1, char *append2)
{
	char	*temp;

	temp = src;
	src = ft_strjoin(src, append1);
	free(temp);
	temp = src;
	src = ft_strjoin(src, append2);
	free(temp);
	return (src);
}

char	**get_cmds(int end, char *argv[])
{
	char	*cmd;
	char	*cmd_line;
	char	**cmds;
	int		i;

	i = 2;
	cmd_line = ft_strdup("");
	while (i < end)
	{
		if (argv[i][0] != '-')
		{	
			cmd = strdup_and_inc(argv[i], &i);
			while (argv[i][0] == '-' && i < end)
			{
				cmd = ft_strjoins(cmd, " ", argv[i]);
				i++;
			}
		}
		else
			cmd = strdup_and_inc(argv[i], &i);
		cmd_line = ft_strjoins(cmd_line, cmd, ",");
		free(cmd);
	}
	cmds = ft_split(cmd_line, ',');
	free(cmd_line);
	return (cmds);
}
