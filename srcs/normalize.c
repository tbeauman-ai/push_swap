/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:54 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/29 08:28:08 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>



void    normalize(t_env *e)
{
    t_list  *sorted;
    unsigned int     i;


    sorted = bubble_sort(e->a);
    i = 0;
    while (sorted)
    {
        *(unsigned int*)sorted->content = i;
        i++;
        sorted = sorted->next;
    }
}