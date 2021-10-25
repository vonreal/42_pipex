/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_outfile_from_stdout.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 02:28:29 by jna               #+#    #+#             */
/*   Updated: 2021/10/16 16:12:01 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_fd(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return (0);
	return (fd);
}