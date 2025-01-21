/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:56:08 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/21 01:55:14 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c);
size_t	ft_strlen2(const char *str);
void	ft_putstr(char *s);
int		print_c(va_list *ap);
int		print_s(va_list *ap);
int		custom_putnbr_base(long p, int b);
int		print_p(va_list *ap);
int		print_d(va_list *ap);
int		print_u(va_list *ap);
int		print_x(va_list *ap);
int		puthexa_big(unsigned int bx);
int		print_bx(va_list *ap);
int		print_prc(va_list *ap);

int		ft_printf(const char *frm, ...);

#endif
