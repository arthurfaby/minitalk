/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:29:52 by afaby             #+#    #+#             */
/*   Updated: 2022/05/22 15:40:25 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

static void	send_datas(int pid, char *str)
{
	char	c;
	int		i;
	char	bit;

	while (*str)
	{
		c = *str;
		i = 8;
		while (i--)
		{
			bit = c >> i & 1;
			if (bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(10);
		}
		str++;
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}

static int	ft_atoi(const char *nptr)
{
	long long int	res;
	int				neg;

	res = 0;
	neg = 1;
	while (((*nptr >= 9 && *nptr <= 13) || *nptr == ' ') && *nptr)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)neg * res);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
		return (ft_printf("Usage: ./%s <PID> <MESSAGE>\n", argv[0]));
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_datas(pid, str);
	return (0);
}
