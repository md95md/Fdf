/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:17:38 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/07 14:13:05 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

size_t	ft_strlen(const char *str);
int		ft_printf(const char *format, ...);
int		ft_putptr(unsigned long long n);
int		ft_putptr_helper(unsigned long long n, int *prefix_printed);
int		ft_putchar(char c);
int		ft_puthex(unsigned int n, int flag);
int		ft_printstr(char *s);
int		ft_putunsgnint(unsigned int n);
int		ft_printdigit(long n, int base);
int		ft_printformat(char c, va_list args);

#endif