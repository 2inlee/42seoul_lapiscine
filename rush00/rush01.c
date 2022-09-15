/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 10:43:14 by inlee             #+#    #+#             */
/*   Updated: 2022/08/27 10:54:47 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int col, int row);
void	first_type(int y, int col);
void	normal_type(int y, int col);
void	last_type(int y, int col);

void	rush(int col, int row)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (x < row)
	{
		while(y < col)
		{
		if ( x == 0 )
			first_type(y, col);
		else if ( x == row - 1)
			last_type(y, col);
		else
			normal_type(y, col);
		y++;
		}
	x++;
	y = 0;
	ft_putchar('\n');
	}
}

void	first_type(int y, int col)
{
	if (y == 0)
		ft_putchar('/');
	else if (y == col - 1)
		ft_putchar('\\');
	else
		ft_putchar('*');
}

void	normal_type(int y, int col)
{
	if (y == 0)
		ft_putchar('*');
	else if (y == col -1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	last_type(int y, int col)
{
	if (y == 0)
		ft_putchar('\\');
	else if (y == col -1)
		ft_putchar('/');
	else
		ft_putchar('*');
}
