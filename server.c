/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarraji <rarraji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:36:18 by rarraji           #+#    #+#             */
/*   Updated: 2023/01/13 11:17:58 by rarraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	int		i ;

	i = 0;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		i = n + 48;
		write(1, &i, 1);
	}	
}

void	ft_printf(const char *str, ...)
{
	va_list	list;

	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd' || *str == 'i')
				ft_putnbr(va_arg(list, int));
		}
		str++;
	}
	va_end (list);
}

void	binart_to_deci(char *s)
{
	int		i;
	int		sum;
	int		j;

	sum = 0;
	i = 0;
	j = 128;
	while (s[i])
	{
		sum += (s[i] - 48) * j;
		j = j / 2;
		i++;
	}
	write(1, &sum, 1);
}
// -------------------------------------//

void	ft_pass(int signal, siginfo_t *info, void *content)
{
	static int		j;
	static char		s[8];
	static int		r;

	(void)content;
	if (info -> si_pid != r)
	{
		r = info->si_pid;
		j = 0;
	}
	if (signal == SIGUSR1)
	{
		s[j] = '0';
		j++;
	}
	else
	{
		s[j] = '1';
		j++;
	}
	if (j == 8)
	{
		binart_to_deci(s);
		j = 0;
	}
}
// --------------------------------------//

int	main(void)
{
	struct sigaction	sg;

	sg.sa_sigaction = &ft_pass;
	sg.sa_flags = SA_RESTART;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sg, NULL);
	sigaction(SIGUSR2, &sg, NULL);
	while (1)
		;
}
