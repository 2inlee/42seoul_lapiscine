/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:30:41 by inlee             #+#    #+#             */
/*   Updated: 2022/09/15 16:38:39 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] <= 32 || base[i] == 127 || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_str_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		count;
	long	result;

	i = 0;
	count = 1;
	result = 0;
	if (ft_valid(base) == 0)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count *= -1;
		i++;
	}
	while (ft_str_base(str[i], base) != -1)
	{
		result = result * ft_strlen(base) + ft_str_base(str[i], base);
		i++;
	}
	return (result * count);
}

int	len_nbr(int nbr, char *base, int len)
{
	int		i;
	int		base_len;
	long	lnbr;

	i = 0;
	base_len = ft_strlen(base);
	lnbr = nbr;
	if (lnbr < 0)
	{
		lnbr *= -1;
		len++;
	}
	while (lnbr >= base_len)
	{
		lnbr /= base_len;
		len++;
	}
	len++;
	return (len);
}
