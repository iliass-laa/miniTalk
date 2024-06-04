/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:11:02 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/30 16:11:04 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_x = 7;

int	check_pid(siginfo_t *info, int *nbr_c, char *c, int *slen)
{
	static int	tmp;

	if (tmp != info->si_pid)
	{
		tmp = info->si_pid;
		*nbr_c = -100;
		*c = 0;
		*slen = 0;
		g_x = 7;
		return (1);
	}
	return (0);
}

void	the_if(long *nbr_s, int *nbr_c, char *c, int *slen)
{
	static char	*str;

	if (*nbr_c < 0)
		alo1(&str, nbr_s, nbr_c);
	alloc_str(&str, nbr_s, slen);
	if (g_x == -1)
	{
		if (*c == 0)
		{
			str[*nbr_c] = 0;
			if (ft_strlen(str) == *slen)
				ft_printf("%s", str);
			alo1(&str, nbr_s, nbr_c);
			*slen = 0;
		}
		else
		{
			str[*nbr_c] = *c;
			(*nbr_c)++;
		}
		g_x = 7;
		*c = 0;
	}
	(*nbr_s)++;
}

void	assign_slen(int num, long *nbr_s, int *slen)
{
	if ((*nbr_s) < 32)
	{
		if (num == SIGUSR2)
			(*slen) = (1 << (31 - (*nbr_s))) | (*slen);
		(*nbr_s) += 1;
	}
}

void	handle(int num, siginfo_t *info, void *context)
{
	static long	nbr_s;
	static int	slen;
	static char	c;
	static int	nbr_c;

	(void)context;
	if (1 == check_pid(info, &nbr_c, &c, &slen))
		nbr_s = 0;
	if (nbr_s < 32)
		assign_slen(num, &nbr_s, &slen);
	else if (nbr_s >= 32)
	{
		if (num == SIGUSR2)
			c = (1 << g_x) | c;
		g_x--;
		the_if(&nbr_s, &nbr_c, &c, &slen);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle;
	ft_printf("PID>>%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
