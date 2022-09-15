/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:30:13 by inlee             #+#    #+#             */
/*   Updated: 2022/09/15 16:33:36 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long	size;
	long	i;
	int		*arr;

	i = 0;
	if (min >= max)
		return (0);
	size = max - min;
	arr = malloc(size * sizeof(int));
	if (arr == 0)
		return (0);
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
