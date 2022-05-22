/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:00:41 by afaby             #+#    #+#             */
/*   Updated: 2022/05/22 15:42:20 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*append(char *str, char c)
{
	char	*res;
	int		i;

	i = 0;
	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (0);
		str[0] = '\0';
	}
	res = malloc(ft_strlen(str) + 2);
	if (!res)
		return (0);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i++] = c;
	res[i] = '\0';
	free(str);
	return (res);
}

int	encode(int n)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static char				*str = NULL;

	c = c | n;
	if (++i == 8)
	{
		if (c == '\0')
		{
			ft_printf("%s", str);
			free(str);
			str = NULL;
			i = 0;
			return (0);
		}
		str = append(str, c);
		i = 0;
		c = 0;
	}
	else
		c = c << 1;
	return (1);
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
		usleep(10);
}
