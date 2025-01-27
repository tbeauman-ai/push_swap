/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:16:20 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/27 12:18:20 by tbeauman         ###   ########.fr       */
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

void    print_bits(int num)
{
    int     i = 31;

    while(i >= 0)
    {
        ft_printf("%d", (num >> i) & 1);
        i--;
    }
}

void    print_pile_bits(t_list *a)
{
    ft_putstr_fd("TOP:\n", 1);
    while (a)
    {
        print_bits(*(int*)a->content);
        ft_printf(":%d\n", *(unsigned int*)a->content);
        a = a->next;
    }
    ft_putstr_fd(":BOT\n", 1);
}

void    print_pile_unsigned_bits(t_list *a)
{
    ft_putstr_fd("TOP:\n", 1);
    while (a)
    {
        print_bits(*(int*)a->content);
        ft_printf(":%u\n", *(unsigned int*)a->content);
        a = a->next;
    }
    ft_putstr_fd(":BOT\n", 1);
}