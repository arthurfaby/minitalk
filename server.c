/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:00:41 by afaby             #+#    #+#             */
/*   Updated: 2022/05/04 16:37:12 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "server.h"

void	encode(int n)
{
	static unsigned char	c = 0;
	static int				i = 0;

	c = c | n;
	if (++i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	else
		c = c << 1;
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		encode(1);
	if (sig == SIGUSR2)
		encode(0);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("\033[0;35mThe pid of the server is : %d\n\033[0m", pid);
	if (signal(SIGUSR1, sig_handler) == SIG_ERR)
		ft_printf("Error\n");
	if (signal(SIGUSR2, sig_handler) == SIG_ERR)
		ft_printf("Error receiving SIGUSR2\n");
	while (1)
		usleep(1);
}
