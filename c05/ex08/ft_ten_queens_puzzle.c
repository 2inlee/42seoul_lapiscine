/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:12:20 by inlee             #+#    #+#             */
/*   Updated: 2022/09/11 20:26:55 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_ten_queens_puzzle(void);
void	ft_rec(int *check, int *cnt, int col);
void	print_check(int *check);
int		valid_check(int col, int *check);

int	ft_ten_queens_puzzle(void)
{
	int		check[10];
	int		i;
	int		cnt;

	cnt = 0;
	i = 0;
	ft_rec(check, &cnt, 0);
	return (cnt);
}

void	ft_rec(int *check, int *cnt, int col)
{
	int	row;

	row = 0;
	if (col == 10)
	{
		*cnt += 1;
		print_check(check);
		return ;
	}
	while (row < 10)
	{
		check[col] = row;
		if (valid_check(col, check))
			ft_rec(check, cnt, col + 1);
		row++;
	}
}

void	print_check(int *check)
{
	int		i;
	char	temp;

	i = 0;
	while (i < 10)
	{
		temp = check[i] + '0';
		write(1, &temp, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	valid_check(int col, int *check)
{
	int	temp;
	int	put;

	put = 0;
	while (put < col)
	{
		temp = check[col] - check[put];
		if (temp < 0)
			temp *= -1;
		if (temp == 0 || col - put == temp)
			return (0);
		put++;
	}
	return (1);
}
