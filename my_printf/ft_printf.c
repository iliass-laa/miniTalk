/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:36:41 by ilaasri           #+#    #+#             */
/*   Updated: 2024/03/08 05:11:54 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printall(const char *s, va_list lst)
{
	int	tot;
	int	i;

	tot = 0;
	i = 0;
	if (s[i] == '%' && s[i + 1] == 'c')
		tot += ft_putchar(va_arg(lst, int));
	if (s[i] == '%' && (s[i + 1] == 'd' || s[i + 1] == 'i'))
		tot += ft_putnbr(va_arg(lst, int));
	if (s[i] == '%' && s[i + 1] == 's')
		tot += ft_putstr(va_arg(lst, char *));
	if (s[i] == '%' && s[i + 1] == 'p')
		tot += ft_printaddress(va_arg(lst, unsigned long));
	if (s[i] == '%' && s[i + 1] == 'x')
		tot += ft_printhexa(va_arg(lst, unsigned int));
	if (s[i] == '%' && s[i + 1] == 'X')
		tot += ft_printhexaupper(va_arg(lst, int));
	if (s[i] == '%' && s[i + 1] == 'u')
		tot += ft_putnbru(va_arg(lst, unsigned int));
	if (s[i] == '%' && s[i + 1] == '%')
		tot += ft_putchar(s[i]);
	return (tot);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	lst;
	int		tot;

	i = 0;
	tot = 0;
	va_start(lst, s);
	while (s[i])
	{
		if (s[i] != '%')
			tot += ft_putchar(s[i]);
		else
		{
			tot += printall((s + i), lst);
			i++;
		}
		if (s[i])
			i++;
	}
	va_end(lst);
	return (tot);
}
