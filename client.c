/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:11:15 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/30 16:11:17 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, char c)
{
	int	i;
	int	b;

	i = 7;
	b = 0;
	while (i >= 0)
	{
		b = (c >> i) & 1;
		if (b == 0)
			kill(pid, SIGUSR1);
		else if (b == 1)
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	send_len(int pid, int slen)
{
	int	i;
	int	b;

	i = 31;
	b = 0;
	while (i >= 0)
	{
		b = (slen >> i) & 1;
		if (b == 0)
			kill(pid, SIGUSR1);
		else if (b == 1)
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;
	int	slen;

	i = 0;
	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	if (pid < 8)
		return (0);
	slen = ft_strlen(av[2]);
	send_len(pid, slen);
	while (av[2][i] != 0)
	{
		send_bit(pid, av[2][i]);
		i++;
		if (i == slen)
			send_bit(pid, 0);
	}
}
