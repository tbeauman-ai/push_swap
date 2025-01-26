/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:28:58 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/26 18:54:41 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     is_sorted(t_list *a)
{
    while (a && a->next)
    {
        if (*(int*)a->content > *(int*)a->next->content)
            return (0);
        a = a->next;
    }
    return (1);
}

t_list  *pile_dup(t_list *p)
{
    t_list  *ret;
    t_list  *new_node;

    ret = 0;
    while(p)
    {
        new_node = ft_lstnew(p->content);
        if (!new_node)
            return (ft_lstclear(&ret, &free), NULL);
        ft_lstadd_back(&ret, new_node);
        p = p->next;
    }
    return (ret);
}

int ft_swap(void **a, void **b)
{
    void    *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
    return (1);
}

t_list  *bubble_sort(t_list *p)
{
    int unsorted;
    t_list  *head;
    t_list  *ret;
    
    ret = pile_dup(p);
    if (!ret)
        return (NULL);
    head = ret;
    unsorted = 1;
    while (unsorted)
    {
        unsorted = 0;
        while (ret->next)
        {
            if ((*(int*)ret->content > *(int*)ret->next->content)
            && ft_swap(&ret->content, &ret->next->content))
                unsorted = 1;
            ret = ret->next;
        }
        ret = head;
    }
    return (ret);
}

int     pile_quantile(t_list *p, int iq)
{
    int     len;
    int     i;
    t_list  *sorted;
    t_list  *head;
    
    i = 0;
    len = ft_lstsize(p);
    sorted = bubble_sort(p);
    head = sorted;
    while(i < iq * len / 5)
    {
        i++;
        sorted = sorted->next;
    }
    len = sorted->content;
    ft_lstclear(&head, &free);
    return (len);
}
