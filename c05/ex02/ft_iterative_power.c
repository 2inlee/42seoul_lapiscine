/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:36:29 by inlee             #+#    #+#             */
/*   Updated: 2022/09/10 17:48:45 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	cnt;

	if (power < 0)
		return (0);
	cnt = 0;
	result = 1;
	while (cnt < power)
	{
		result = result * nb;
		cnt++;
	}
	return (result);
}
