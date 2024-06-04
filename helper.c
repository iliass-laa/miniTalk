/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:00:27 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/30 22:00:29 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		i;
	int		sign;
	long	tmp;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		tmp = res;
		res = res * 10 + (str[i++] - 48);
		if (tmp != res / 10 && sign == 1)
			return (-1);
		if (tmp != res / 10 && sign == -1)
			return (0);
	}
	return (res * sign);
}

void	alo(char **str, long *nbr_s, int *slen, int *nbr_c)
{
	if (*nbr_c >= 0)
	{
		*nbr_s = 0;
		*slen = -1;
	}
	*nbr_c = 0;
	free(*str);
	*str = NULL;
}

void	alloc_str(char **str, long *nbr_s, int *slen)
{
	if (*nbr_s == 32)
	{
		*str = (char *)malloc(*slen + 1);
		if (!*str)
			exit(2);
	}
}

void	alo1(char **str, long *nbr_s, int *nbr_c)
{
	if (*nbr_c >= 0)
		*nbr_s = 0;
	*nbr_c = 0;
	free(*str);
	*str = NULL;
}
