/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:34:32 by inlee             #+#    #+#             */
/*   Updated: 2022/09/10 17:48:25 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fac;
	int	i;

	if (nb < 0)
		return (0);
	i = nb;
	fac = 1;
	while (i > 0)
	{
		fac = fac * i;
		i--;
	}
	return (fac);
}
