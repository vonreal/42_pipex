/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:33:01 by jna               #+#    #+#             */
/*   Updated: 2021/10/16 21:33:01 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    check_argc(int argc, int min, int max)
{
    if (min != 0)
    {
        if (argc < min)
        {
            write(STDERR_FILENO, "Arguments too few.\n", 20);
            exit(-1);
        }
    }
    if (max != 0)
    {
        if (argc > max)
        {
            write(STDERR_FILENO, "Arguments too many.\n", 20);
            exit(-1);
        }
    }
}