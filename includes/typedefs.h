/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:45:47 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/27 18:59:35 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

# include "libft.h"

typedef struct s_env
{
    int     size_a;
    int     size_b;
    t_list  *a;
    t_list  *b;
    int     offset;
    int     *integers;
}               t_env;


#endif