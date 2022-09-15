/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:03:20 by inlee             #+#    #+#             */
/*   Updated: 2022/08/29 21:18:59 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *a, int nfix)
{
	write(1, a, nfix);
	if (!(a[0] == (10 - nfix) + '0'))
		write(1, ", ", 2);
}

void	ft_rec(char *a, int i, int ndwn, int nfix)
{
	if (ndwn == 0)
		ft_putchar(a, nfix);
	while (i < 10)
	{
		a[nfix - ndwn] = i + '0';
		if (ndwn < 0)
			return ;
		ft_rec(a, i + 1, ndwn - 1, nfix);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	a[10];
	int		i;

	i = 0;
	a[0] = '0';
	ft_rec(a, i, n, n);
}
