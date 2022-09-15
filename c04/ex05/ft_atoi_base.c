/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:58:34 by inlee             #+#    #+#             */
/*   Updated: 2022/09/08 20:12:09 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen3(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_valid_check(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen3(str) == 0 || ft_strlen3(str) == 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= ' ' || str[i] == '\n' || str[i] == '\t' || \
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
			return (0);
		else if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (j < ft_strlen3(str))
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	make_digit(char c, char *base)
{
	int	len_base;
	int	i;

	i = 0;
	len_base = ft_strlen3(base);
	while (i < len_base)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int	is_base(char c, char *base)
{
	int	i;
	int	len_base;

	i = 0;
	len_base = ft_strlen3(base);
	while (i < len_base)
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	sum;

	i = 0;
	sign = 1;
	sum = 0;
	if (!ft_valid_check(base))
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
			str[i] == '\v' || str[i] == '\r' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (is_base(str[i], base))
	{
		sum = sum * ft_strlen3(base) + make_digit(str[i], base);
		i++;
	}
	return (sign * sum);
}
