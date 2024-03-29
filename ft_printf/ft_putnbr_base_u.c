/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:55:44 by afaby             #+#    #+#             */
/*   Updated: 2022/05/22 15:08:48 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base_validity(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == '-' || *(str + i) == '+')
			return (0);
		j = 1;
		while (*(str + i + j))
		{
			if (*(str + i) == *(str + i + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base_u(unsigned int nbr, char *base)
{
	unsigned int		base_len;
	int					ret;

	ret = 0;
	if (check_base_validity(base))
	{
		base_len = ft_strlen(base);
		if (nbr < base_len)
			ret += ft_putchar(base[nbr]);
		else
		{
			ret += ft_putnbr_base_u(nbr / base_len, base);
			ret += ft_putnbr_base_u(nbr % base_len, base);
		}
	}
	return (ret);
}
