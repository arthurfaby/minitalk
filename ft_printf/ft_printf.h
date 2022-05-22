/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:21:52 by afaby             #+#    #+#             */
/*   Updated: 2022/05/22 15:11:07 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_process(const char *s, va_list args);
int		ft_putnbr(long long int n);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr_base_u(unsigned int n, char *base);
int		ft_putptr(void	*ptr);
int		ft_strlen(char *str);
int		ft_putnbr_base_ull(unsigned long long int n, char *base);
#endif
