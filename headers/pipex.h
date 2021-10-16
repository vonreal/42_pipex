/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:53:58 by jna               #+#    #+#             */
/*   Updated: 2021/10/17 02:03:15 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

# define READ 0
# define WRITE 1

typedef struct s_info
{
	int		fd_infile;
	int		fd_outfile;
	char	**paths;
	char	**cmds;
	int		**fds;
}				t_info;

void	check_argc(int argc, int min, int max);

t_info	set_infos(int argc, char *argv[], char *envp[]);
void	set_fd(t_info *infos, char *infile, char *outfile);
char	**get_paths(char *envp[]);
char	**get_cmds(int end, char *argv[]);
int		**get_fds(int size);
int		get_size_char_arr2(char **arr2);

void	pipex(t_info infos, char *envp[]);
void	read_input_from_infile(int fd_infile);
void	send_output_as_input(t_info *infos, int idx, char *envp[]);
void	execve_cmd(char *cmd, char **paths, char *envp[]);
void	save_output_to_outfile(int *fd, int fd_outfile);

void	free_infos(t_info *infos);

#endif
