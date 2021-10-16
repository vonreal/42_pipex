#include "pipex.h"

int	pipex(t_info infos, char *envp[])
{
	int	i;

	i = 0;
	dup2(infos.fd_infile, STDIN_FILENO);
	while (infos.cmds[i])
	{
		if (infos.cmds[i + 1] == NULL)
		{
			infos.fds[i][0] = 0;
			infos.fds[i][1] = infos.fd_outfile;
		}
		else
		{
			if (pipe(infos.fds[i]) < 0)
			return (-1);
		}
		if(set_stdout_from_cmd(infos.cmds[i], &infos, i, envp) < 0)
			return (-1);
		i++;
	}
	return (0);
}

int main(int argc, char *argv[], char *envp[])
{
	t_info	infos;

	infos = set_infos(argc, argv, envp);
	if (pipex(infos, envp) < 0)
	 	return (0);
	return (0);
}

