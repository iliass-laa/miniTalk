/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:24:51 by ilaasri           #+#    #+#             */
/*   Updated: 2023/12/30 20:24:53 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	x;

	x = write(1, &c, 1);
	return (x);
}

int	ft_putnbr(int c)
{
	long	i;
	int		tot;

	i = c;
	tot = 1;
	if (i < 0)
	{
		tot += ft_putchar('-');
		i *= -1;
	}
	if (i < 10)
	{
		ft_putchar(i + 48);
	}
	else if (i >= 10)
	{
		tot += ft_putnbr(i / 10);
		ft_putchar((i % 10) + 48);
	}
	return (tot);
}

int	ft_putnbru(unsigned int c)
{
	int	tot;

	tot = 1;
	if (c < 10)
	{
		ft_putchar(c + 48);
	}
	else if (c >= 10)
	{
		tot += ft_putnbr(c / 10);
		ft_putchar((c % 10) + 48);
	}
	return (tot);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
