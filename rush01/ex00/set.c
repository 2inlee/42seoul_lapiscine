/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunrlee <eunrlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:20:40 by eunrlee           #+#    #+#             */
/*   Updated: 2022/09/04 20:12:44 by eunrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**make_square(void)
{
	int	**square;
	int	i;
	int	j;

	square = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
	{
		square[i] = (int *)malloc(sizeof(int) * 4);
		i++;
	}
	if (!square)
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			square[i][j] = 0;
			j++;
		}
		i++;
	}
	return (square);
}

void	set_input(char *argv, int *int_arr)
{
	int	i;

	i = 0;
	while (*argv)
	{
		if (*argv >= '1' && *argv <= '4')
		{
			int_arr[i] = *argv - '0';
			i++;
		}
		argv++;
	}
}

int	check_argv(char *argv)
{
	int	i;
	int	count;
	int	check;

	i = 0;
	count = 0;
	check = 1;
	while (argv[i])
	{
		if (argv[i] == ' ' && check == 0)
			check++;
		else if ((argv[i] >= '1' && argv[i] <= '4') && check == 1)
		{
			count++;
			check--;
		}
		i++;
	}
	if (count != 16 || i != 31)
		return (0);
	return (1);
}

void	free_square(int **square)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(square[i]);
		i++;
	}
	free(square);
	return ;
}
