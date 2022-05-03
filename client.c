/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:29:52 by afaby             #+#    #+#             */
/*   Updated: 2022/05/03 10:33:48 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;
	char	c;
	int		i;
	char	bit;

	if (argc != 3)
		return (ft_printf("Usage: ./bin <PID> <MESSAGE>\n"));
	pid = atoi(argv[1]);
	str = argv[2];
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
			usleep(100);
		}
		str++;
	}
}
