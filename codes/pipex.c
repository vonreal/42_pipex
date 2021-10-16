/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:18:00 by jna               #+#    #+#             */
/*   Updated: 2021/10/16 20:18:00 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	t_info	infos;

	check_argc(argc, 5, 0);
	infos = set_infos(argc, argv, envp);
	pipex(infos, envp);
	free_infos(&infos);
	return (0);
}

int	pipex(t_info infos, char *envp[])
{
	int	i;
	int	size;

	i = 0;
	size = get_size_char_arr2(infos.cmds);
	read_input_from_infile(infos.fd_infile);
	while (i < size - 1)
	{
		if (pipe(infos.fds[i]) < 0)
		{
			perror("Fail to pipe().\n");
			exit(-1);
		}
		send_output_as_input(&infos, i, envp);
		i++;
	}
	save_output_to_outfile(infos.fds[i], infos.fd_outfile);
	set_stdout_from_cmd(&infos, i, envp);
}
