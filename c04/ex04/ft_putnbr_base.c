/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:29:13 by inlee             #+#    #+#             */
/*   Updated: 2022/09/08 19:57:12 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar2(char c)
{
	write(1, &c, 1);
}

int	ft_strlen2(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_checkbase(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen2(str) == 0 || ft_strlen2(str) == 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == 127)
			return (0);
		else if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (j < ft_strlen2(str))
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	n;

	len = ft_strlen2(base);
	n = nbr;
	if (ft_checkbase(base) == 1)
	{
		if (n < 0)
		{
			ft_putchar2('-');
			n *= -1;
		}
		if (n >= len)
		{
			ft_putnbr_base(n / len, base);
		}
		ft_putchar2(base[n % len]);
	}
}
