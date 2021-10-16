/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 00:15:25 by jna               #+#    #+#             */
/*   Updated: 2021/10/17 02:52:34 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**get_fds(int size)
{
	int	**fds;
	int	i;

	fds = (int **)malloc(sizeof(int *) * size);
	if (!fds)
		exit (0);
	i = 0;
	while (i < size)
	{
		fds[i] = (int *)malloc(sizeof(int) * 2);
		if (!fds[i])
			exit (0);
		i++;
	}
	return (fds);
}

int	get_size_char_arr2(char **arr2)
{
	int	size;

	size = 0;
	while (arr2[size])
		size++;
	return (size);
}
