/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarraji <rarraji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:51:13 by rarraji           #+#    #+#             */
/*   Updated: 2023/01/11 17:03:29 by rarraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_strlen(char *s);
int		ft_atoi(const char *str);
void	all_bit(int j, char *s);
void	ft_putnbr(int n);
void	ft_printf(const char *str, ...);
void	binart_to_deci(char *s);
void	ft_pass(int signal, siginfo_t *info, void *content);
int		ft_strlen2(char *s);
void	ft_send(char *s, int j);
void	convert_to_binary(int nb, int j);

#endif