/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunrlee <eunrlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:21:19 by eunrlee           #+#    #+#             */
/*   Updated: 2022/09/04 20:13:24 by eunrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_answer(int **square, int *input);

int	check_square_row(int **square, int x, int y)
{
	int	check[4];

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
			check[y++] = 0;
		y = 0;
		while (y < 4)
		{
			if (square[x][y] > 0)
				check[square[x][y] - 1]++;
			y++;
		}
		y = 0;
		while (y < 4)
		{
			if (check[y++] > 1)
				return (0);
		}
		x++;
	}
	return (1);
}

int	check_square_col(int **square, int x, int y)
{
	int	check[4];

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
			check[x++] = 0;
		x = 0;
		while (x < 4)
		{
			if (square[x][y] > 0)
				check[square[x][y] - 1]++;
			x++;
		}
		x = 0;
		while (x < 4)
		{
			if (check[x++] > 1)
				return (0);
		}
		y++;
	}
	return (1);
}

int	solve(int **square, int *input, int solved)
{
	int	i;
	int	quit;

	i = 1;
	quit = 0;
	if (solved == 16)
	{
		quit = check_answer(square, input);
		return (quit);
	}
	while (i <= 4)
	{
		square[solved / 4][solved % 4] = i;
		if (check_square_row(square, 0, 0) && check_square_col(square, 0, 0))
		{
			quit = solve(square, input, solved + 1);
			if (quit == 1)
				break ;
		}
		square[solved / 4][solved % 4] = 0;
		i++;
	}
	return (quit);
}
