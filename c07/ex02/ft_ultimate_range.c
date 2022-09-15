/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:49:50 by inlee             #+#    #+#             */
/*   Updated: 2022/09/15 16:34:25 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long	size;
	long	i;
	int		*arr;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = max - min;
	arr = (int *)malloc(size * sizeof(int));
	if (arr == 0)
	{
		*range = 0;
		return (-1);
	}
	*range = arr;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	return (size);
}
