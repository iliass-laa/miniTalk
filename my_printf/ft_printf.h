/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:31:18 by ilaasri           #+#    #+#             */
/*   Updated: 2024/01/01 14:37:54 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putnbr(int c);
int	ft_putstr(char *s);
int	ft_printhexa(unsigned int c);
int	ft_printhexaupper(int c);
int	ft_printaddress(unsigned long c);
int	ft_putnbru(unsigned int c);
int	ft_printf(const char *s, ...);

#endif
