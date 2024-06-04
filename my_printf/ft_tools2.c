/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:14:47 by ilaasri           #+#    #+#             */
/*   Updated: 2024/01/01 14:16:48 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printaddress(unsigned long c)
{
	int		tot;
	char	*base;

	base = "0123456789abcdef";
	tot = 1;
	if (c < 16)
	{
		tot += ft_putstr("0x");
		ft_putchar(base[c]);
	}
	else if (c >= 16)
	{
		tot += ft_printaddress(c / 16);
		ft_putchar(base[c % 16]);
	}
	return (tot);
}

int	ft_printhexaupper(int c)
{
	unsigned int	i;
	int				tot;
	char			*base1;

	i = c;
	tot = 1;
	base1 = "0123456789ABCDEF";
	if (i < 16)
	{
		ft_putchar(base1[i]);
	}
	else if (i >= 16)
	{
		tot += ft_printhexaupper(i / 16);
		ft_putchar(base1[i % 16]);
	}
	return (tot);
}

int	ft_printhexa(unsigned int c)
{
	int		tot;
	char	*base;

	tot = 1;
	base = "0123456789abcdef";
	if (c < 16)
	{
		ft_putchar(base[c]);
	}
	else if (c >= 16)
	{
		tot += ft_printhexa(c / 16);
		ft_putchar(base[c % 16]);
	}
	return (tot);
}
