/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extremum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:07:08 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/27 21:01:35 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     get_max(t_list *p)
{
    int     max;

    if (!p)
        return (0);
    max = *(int*)p->content;
    while(p)
    {
        if (*(int*)p->content > max)
            max = *(int*)p->content;
        p = p->next;
    }
    return (max);
}

int     get_min(t_list *p)
{
    int     min;

    if (!p)
        return (0);
    min = *(int*)p->content;
    while(p)
    {
        if (*(int*)p->content < min)
            min = *(int*)p->content;
        p = p->next;
    }
    return (min);
}

int     seek_min_index(t_list *p)
{
    int     min;
    int     pindex;
    int     ret;

    min = *(int*)p->content;
    ret = 0;
    pindex = 0;
    while (p)
    {
        if (*(int*)p->content < min)
        {
            min = *(int*)p->content;
            ret = pindex;
        }
        p = p->next;
        pindex++;
    }
    return (ret);
}

int     seek_max_index(t_list *p)
{
    int     max;
    int     pindex;
    int     ret;

    max = *(int*)p->content;
    ret = 0;
    pindex = 0;
    while (p)
    {
        if (*(int*)p->content > max)
        {
            max = *(int*)p->content;
            ret = pindex;
        }
        p = p->next;
        pindex++;
    }
    return (ret);
}
