/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunrlee <eunrlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:20:53 by eunrlee           #+#    #+#             */
/*   Updated: 2022/09/04 20:12:55 by eunrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_up(int **square, int *input)
{
	int	x;
	int	y;
	int	count;
	int	before;

	y = 0;
	while (y < 4)
	{
		x = 0;
		count = 0;
		before = 0;
		while (x < 4)
		{
			if (square[x][y] > before)
			{
				before = square[x][y];
				count++;
			}
			x++;
		}
		if (count != input[y])
			return (0);
		y++;
	}
	return (1);
}

int	check_down(int **square, int *input)
{
	int	x;
	int	y;
	int	count;
	int	before;

	y = 0;
	while (y < 4)
	{
		x = 3;
		count = 0;
		before = 0;
		while (x >= 0)
		{
			if (square[x][y] > before)
			{
				before = square[x][y];
				count++;
			}
			x--;
		}
		if (count != input[y + 4])
			return (0);
		y++;
	}
	return (1);
}

int	check_left(int **square, int *input)
{
	int	x;
	int	y;
	int	count;
	int	before;

	x = 0;
	while (x < 4)
	{
		y = 0;
		count = 0;
		before = 0;
		while (y < 4)
		{
			if (square[x][y] > before)
			{
				before = square[x][y];
				count++;
			}
			y++;
		}
		if (count != input[x + 8])
			return (0);
		x++;
	}
	return (1);
}

int	check_right(int **square, int *input)
{
	int	x;
	int	y;
	int	count;
	int	before;

	x = 0;
	while (x < 4)
	{
		y = 3;
		count = 0;
		before = 0;
		while (y >= 0)
		{
			if (square[x][y] > before)
			{
				before = square[x][y];
				count++;
			}
			y--;
		}
		if (count != input[x + 12])
			return (0);
		x++;
	}
	return (1);
}

int	check_answer(int **square, int *input)
{
	int	up;
	int	down;
	int	left;
	int	right;

	up = check_up(square, input);
	down = check_down(square, input);
	left = check_left(square, input);
	right = check_right(square, input);
	if (up && down && left && right)
		return (1);
	return (0);
}
