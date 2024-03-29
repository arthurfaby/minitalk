/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:43:47 by afaby             #+#    #+#             */
/*   Updated: 2022/05/22 15:10:06 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	ret;

	ret = 0;
	if (!ptr)
		ret += ft_putstr("(nil)");
	else
	{
		ret += ft_putstr("0x");
		ret += ft_putnbr_base_ull(
				(unsigned long long int)ptr, "0123456789abcdef"
				);
	}
	return (ret);
}
