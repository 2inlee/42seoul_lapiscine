/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:27:05 by inlee             #+#    #+#             */
/*   Updated: 2022/09/15 16:38:04 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_valid(char *base);
int	ft_str_base(char c, char *base);
int	ft_atoi_base(char *str, char *base);
int	len_nbr(int nbr, char *base, int len);

char	*ft_putnbr_base(int nbr, char *base, char *final_nbr)
{
	long	lnbr;
	int		base_len;
	int		i;
	int		len_nbr_size;

	lnbr = nbr;
	base_len = ft_strlen(base);
	i = 0;
	len_nbr_size = len_nbr(lnbr, base, 0);
	if (lnbr < 0)
	{
		final_nbr[0] = '-';
		lnbr *= -1;
		i = 1;
	}
	len_nbr_size--;
	while (lnbr >= base_len)
	{
		final_nbr[len_nbr_size] = base[lnbr % base_len];
		lnbr /= base_len;
		len_nbr_size--;
	}
	if (lnbr < base_len)
		final_nbr[i] = base[lnbr];
	return (final_nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		from_nbr;
	int		len_nbr_size;
	char	*final_nbr;

	if (nbr == 0)
		return (0);
	if (ft_valid(base_to) == 0 || ft_valid(base_from) == 0)
		return (0);
	from_nbr = ft_atoi_base(nbr, base_from);
	len_nbr_size = len_nbr(from_nbr, base_to, 0);
	final_nbr = (char *)malloc((len_nbr_size + 1) * sizeof(char));
	if (final_nbr == 0)
		return (0);
	final_nbr[len_nbr_size] = '\0';
	ft_putnbr_base(from_nbr, base_to, final_nbr);
	return (final_nbr);
}
