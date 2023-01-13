/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarraji <rarraji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:44:45 by rarraji           #+#    #+#             */
/*   Updated: 2023/01/13 12:41:59 by rarraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
// ----------------------------------------//

int	ft_strlen2(char *s)
{
	int			i;

	i = 8;
	if (!s)
		return (0);
	while (i != 0)
		i--;
	return (i);
}

// -----------------------------------------//

void	ft_send(char *s, int j)
{
	int		i;

	i = 0;
	while (s[i])
	{
		usleep(50);
		if (s[i] == '0')
			kill(j, SIGUSR1);
		else
			kill(j, SIGUSR2);
		i++;
		usleep(100);
	}
}
// ------------------------------------------ //

void	convert_to_binary(int nb, int j)
{
	char	*s;
	int		i;
	int		l;

	s = malloc(9);
	l = 0;
	i = 8;
	s[i] = '\0';
	i -= 1;
	while (nb > 0)
	{
		s[i] = (nb % 2) + 48;
		nb = nb / 2;
		l++;
		i--;
	}
	while (l < 8)
	{
		s[i] = '0';
		i--;
		l++;
	}
	i = 0;
	ft_send(s, j);
	free (s);
}
// ------------------------------------------- //

int	main(int ac, char **av)
{
	int		j;

	(void) ac;
	j = 0;
	while (av[2][j])
	{
		convert_to_binary(av[2][j], ft_atoi(av[1]));
		j++;
	}
	return (0);
}
