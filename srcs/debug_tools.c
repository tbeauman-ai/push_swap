/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:16:20 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/26 17:06:27 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_pile(t_list *a)
{
    ft_putstr_fd("TOP:", 1);
    while (a)
    {
        ft_printf("%d ", *(int*)a->content);
        a = a->next;
    }
    ft_putstr_fd(":BOT\n", 1);
}