/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 01:12:51 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/28 09:22:37 by tbeauman         ###   ########.fr       */
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

void    radix_sort(t_env *e)
{
    unsigned int     max;
    unsigned int     max_bits;
    unsigned int     i;
    unsigned int     j;
    unsigned int     size;
    unsigned int value;
    unsigned int bit_a;
    unsigned int bit_b;

    max = get_umax(e->a);
    max_bits = 0;
    while ((unsigned int)(max >> max_bits) > 0 && max_bits < 32)
    {
        max_bits++;
    }
    i = 0;
    int prout = 0;
    while (i <= max_bits)
    {
        j = 0;
        size = e->size_a - prout;
        // if (!has_one(e, i))
        // {
            // ft_printf("prout\n");
            //i++;
            // continue ;
        // }


        while (j < size)
        {
            value = *(unsigned int *)e->a->content;
            bit_a = (value >> i) & 1;
            if (bit_a)
                ra(e);
            else
                pb(e);
            j++;
        }
        j = 0;
        prout = 0;
        size = e->size_b;
        if (is_sorted(e->a) && is_reverse_sorted(e->b) && *(int*)e->a->content > *(int*)e->b->content)
            break ;
        while (j < size)
        {
            value = *(unsigned int *)e->b->content;
            bit_b = (value >> (i + 1)) & 1;
            if (bit_b)
                pa(e);
            else
            {
                value = *(unsigned int *)e->a->content;
                bit_a = (value >> (i + 1)) & 1;
                // if (bit_a)
                // {
                //     rr(e);
                //     prout += 1;
                // }
                // else
                    rb(e);
            }
            j++;
        }
        i++;
    }
    while (e->size_b)
        pa(e);
}

void    radix_sort_opti(t_env *e)
{
    unsigned int     max;
    unsigned int     max_bits;
    unsigned int     i;
    unsigned int     j;
    unsigned int     size;
    unsigned int value;
    unsigned int bit_a;
    unsigned int bit_b;

    max = get_umax(e->a);
    max_bits = 0;
    while ((unsigned int)(max >> max_bits) > 0 && max_bits < 32)
    {
        max_bits++;
    }
    i = 0;
    int prout = 0;
    while (i <= max_bits)
    {
        j = 0;
        size = e->size_a - prout;
        // if (!has_one(e, i))
        // {
            // ft_printf("prout\n");
            //i++;
            // continue ;
        // }


        while (j < size)
        {
            value = *(unsigned int *)e->a->content;
            bit_a = (value >> i) & 1;
            if (bit_a)
            {
                ra(e);
            }
            else
                pb(e);
            j++;
        }
        j = 0;
        prout = 0;
        size = e->size_b;
        if (is_sorted(e->a) && is_reverse_sorted(e->b) && *(int*)e->a->content > *(int*)e->b->content)
            break ;
        while (j < size)
        {
            value = *(unsigned int *)e->b->content;
            bit_b = (value >> (i + 1)) & 1;
            if (bit_b)
            {
                pa(e);
            }
            else
            {
                // value = *(unsigned int *)e->a->content;
                // bit_a = (value >> (i + 1)) & 1;
                // if (bit_a)
                // {
                //     rr(e);
                //     prout += 1;
                // }
                // else
                rb(e);
            }
            j++;
        }
        
        i++;
    }
    while (e->size_b)
        pa(e);
}