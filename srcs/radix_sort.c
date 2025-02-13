/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 01:12:51 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/29 08:57:42 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     get_bit(int x, int pos)
{
    return ((x >> pos) & 1);
}

int     get_ubit(unsigned int x, int pos)
{
    return ((x >> pos) & 1);
}

unsigned int     get_umax(t_list *p)
{
    unsigned int     max;

    if (!p)
        return (0);
    max = *(unsigned int*)p->content;
    while(p)
    {
        if (*(unsigned int*)p->content > max)
            max = *(unsigned int*)p->content;
        p = p->next;
    }
    return (max);
}

int     has_one(t_env *e, unsigned int i)
{
    t_list  *head;
    
    head = e->a;
    while(head)
    {
        if ((*(unsigned int *)head->content >> i) & 1)
            return (1);
        head = head->next;
    }
    return (0);
}

void    push_zeroes_to_b(t_env *e, unsigned int i)
{
    unsigned int value;
    unsigned int bit;
    unsigned int size;
    unsigned int j;

    j = 0;
    size = e->size_a;
    while (j < size)
    {
        value = *(unsigned int *)e->a->content;
        bit = (value >> i) & 1;
        if (bit)
            ra(e);
        else
            pb(e);
        j++;
    }
}

void    push_them_back_to_a_or_not(t_env *e, unsigned int i)
{
    unsigned int    j;
    unsigned int    size;
    unsigned int    value;
    unsigned int    bit;

    j = 0;
    size = e->size_b;
    while (j < size)
    {
        value = *(unsigned int *)e->b->content;
        bit = (value >> (i + 1)) & 1;
        if (bit)
            pa(e);
        else
            rb(e);
        j++;
    }
}

void    radix_sort(t_env *e)
{
    unsigned int     max;
    unsigned int     max_bits;
    unsigned int     i;

    max = get_umax(e->a);
    max_bits = 0;
    while ((unsigned int)(max >> max_bits) > 0)
        max_bits++;
    i = 0;
    while (i <= max_bits)
    {
        push_zeroes_to_b(e, i);
        if (is_sorted(e->a) && is_reverse_sorted(e->b) && *(int*)e->a->content > *(int*)e->b->content)
            break ;
        push_them_back_to_a_or_not(e, i);
        i++;
    }
    while (e->size_b)
        pa(e);
}