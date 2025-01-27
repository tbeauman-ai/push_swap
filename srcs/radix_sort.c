/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 01:12:51 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/27 12:47:04 by tbeauman         ###   ########.fr       */
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
    unsigned int     size_a;

    max = get_max(e->a);
    max_bits = 0;
    if (max < 0)
        ft_printf("ntm la pute\n");
    while ((unsigned int)(max >> max_bits) > 0 && max_bits < 32)
    {
        ft_printf("max:%u max_bits:%u shift: %u\n", max, max_bits, (unsigned int)(max >> max_bits));
        max_bits++;
    }
    i = 0;
    ft_printf("%d:max_bits\n", max_bits);
    while (i < max_bits)
    {
        j = 0;
        size_a = e->size_a;
        if (!has_one(e, i))
        {
            i++;
            continue ;
        }


        while (j < size_a)
        {
            unsigned int value = *(unsigned int *)e->a->content;
            unsigned int bit_a = (value >> i) & 1;
            unsigned int bit_b = e->b && e->size_b > 0 ? (*(unsigned int*)e->b->content >> i) & 1 : 0;

            if (bit_a == 1 && bit_b == 1)
                rr(e);
            else if (bit_a == 1)
                ra(e);
            else if (bit_b == 1)
                rb(e);
            else
                pb(e);
            // if (get_ubit(*(unsigned int*)e->a->content, i) == 0)
            //     pb(e);
            // else
            //     ra(e);
            j++;
        }
        while (e->size_b)
        {
            // if (e->size_a > 1 && *(unsigned int*)e->a->content > *(unsigned int*)e->b->content)
            //     rrr(e);
            // else
                pa(e);
        }
        i++;
    }
    // while (!is_sorted(e->a))
    //     ra(e);
}