/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:21:40 by ilaasri           #+#    #+#             */
/*   Updated: 2024/05/30 23:21:41 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "my_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *s);
int		ft_atoi(const char *str);
void	alo(char **str, long *nbr_s, int *slen, int *nbr_c);
void	alloc_str(char **str, long *nbr_s, int *slen);

#endif