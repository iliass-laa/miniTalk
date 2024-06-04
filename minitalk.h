/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 02:30:56 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/29 02:30:58 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "my_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *s);
int		ft_atoi(const char *str);
void	alloc_str(char **str, long *nbr_s, int *slen);
void	alo1(char **str, long *nbr_s, int *nbr_c);

#endif