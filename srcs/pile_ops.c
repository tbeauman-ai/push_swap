/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:22:48 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/25 22:47:36 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_list **a, t_list **b)
{
    t_list  *tmp;

    if (!*a)
        return ;
    tmp = (*a)->next;
    (*a)->next = *b;
    *b = *a;
    *a = tmp;
}

void    swap(t_list **a)
{
    t_list *tmp;

    if (!*a || !(*a)->next)
        return ;
    tmp = (*a)->next;
    (*a)->next = (*a)->next->next;
    ft_lstadd_front(a, tmp);
}

void    rotate(t_list **a)
{
    t_list  *first;

    if (!*a || !(*a)->next)
        return ;
    first = *a;
    *a = (*a)->next;
    first->next = 0;
    ft_lstadd_back(a, first);
}

void    reverse_rotate(t_list **a)
{
    t_list  *head;
    t_list  *before_last;

    if (!*a || !(*a)->next)
        return ;
    head = *a;
    while ((*a)->next->next)
        *a = (*a)->next;
    before_last = *a;
    *a = (*a)->next;
    (*a)->next = head;
    before_last->next = 0;

}