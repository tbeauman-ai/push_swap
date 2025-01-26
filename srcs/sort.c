/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:55:46 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/26 19:12:19 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     seek_min_index(t_list *p)
{
    int     min;
    int     pindex;
    int     ret;
    int     psize;

    psize = ft_lstsize(p);
    min = *(int*)p->content;
    ret = 0;
    pindex = 0;
    while (p)
    {
        if (*(int*)p->content < min)
        {
            min = p->content;
            ret = pindex;
        }
        p = p->next;
        pindex++;
    }
    return (ret);
}

int     sort(t_env *e)
{
    int     i;
    int     i_min;
    
    i = 0;
    while (i < 5)
    {

        i++;
    }
}