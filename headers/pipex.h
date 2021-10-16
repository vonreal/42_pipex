/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:53:58 by jna               #+#    #+#             */
/*   Updated: 2021/10/16 16:06:13 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define READ 0
# define WRITE 1

typedef struct s_info
{
	int		fd_infile;
	int		fd_outfile;
	char	**cmds;
	char	**paths;
	int		**fds;
}				t_info;

t_info	set_infos(int argc, char *argv[], char *envp[]);
int		set_stdin_from_infile(char *infile);
int		**set_fds(char **cmds);
int		set_stdout_from_cmd(char *cmd, t_info *infos, int i, char *envp[]);
int		get_fd(char *file);
int		error_msg(char *msg);

#endif
