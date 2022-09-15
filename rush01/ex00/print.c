/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunrlee <eunrlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:21:05 by eunrlee           #+#    #+#             */
/*   Updated: 2022/09/04 20:13:17 by eunrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_square(int **square)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			c = square[x][y] + '0';
			write (1, &c, 1);
			y++;
		}
		write (1, "\n", 1);
		x++;
	}
	return ;
}

void	print_error(void)
{
	write(1, "Error!\n", 7);
}
