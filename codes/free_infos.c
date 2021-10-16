/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 22:32:11 by jna               #+#    #+#             */
/*   Updated: 2021/10/16 22:32:11 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void free_char_arr2(char **char_arr2)
{
    int i;

    i = 0;
    while (char_arr2[i])
    {
        free(char_arr2[i]);
        char_arr2[i] = NULL;
        i++;
    }
    free(char_arr2);
    char_arr2 = NULL;
}

static void free_fds(int **int_arr2, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        free(int_arr2[i]);
        int_arr2[i] = NULL;
        i++;
    }
    free(int_arr2);
    int_arr2 = NULL;
}

void    free_infos(t_info *infos)
{
    int cmds_row;

    cmds_row = get_size_char_arr2(infos->cmds);
    free_char_arr2(infos->paths);
    free_char_arr2(infos->cmds);
    free_fds(infos->fds, cmds_row);
}
