/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:48:40 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/21 20:59:18 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_error(char *msg)
{
    ft_putstr_fd(msg, 2);
    exit(1);
}

void    check_args(int ac, char **av)
{
    int     i;
    int     j;

    if (ac == 1)
        ft_error("");
    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] != '-' && (av[i][j] < '0' || av[i][j] > '9'))
                ft_error("Error\n");
            j++;
        }
    }
}
