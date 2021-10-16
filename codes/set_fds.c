/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 00:15:25 by jna               #+#    #+#             */
/*   Updated: 2021/10/16 16:12:52 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**set_fds(char **cmds)
{
	int	size;
	int	**fds;
	int	i;

	size = 0;
	while (cmds[size])
		size++;
	fds = (int **)malloc(sizeof(int *) * size);
	if (!fds)
		exit (0);
	i = 0;
	while (cmds[i])
	{
		fds[i] = (int *)malloc(sizeof(int) * 2);
		if (!fds[i])
			exit (0);
		i++;
	}
	return (fds);
}
