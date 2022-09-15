/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunrlee <eunrlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:20:18 by eunrlee           #+#    #+#             */
/*   Updated: 2022/09/04 20:13:04 by eunrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		**make_square(void);
void	set_input(char *argv, int *int_arr);
int		check_argv(char *argv);
int		solve(int **square, int *input, int solved);
void	print_square(int **square);
void	free_square(int **square);
void	print_error(void);

int	main(int argc, char **argv)
{
	int	**square;
	int	input[16];
	int	check_solve;

	if (argc != 2 || !check_argv(argv[1]))
	{
		print_error();
		return (0);
	}
	square = make_square();
	if (!square)
	{
		print_error();
		return (0);
	}
	set_input(argv[1], input);
	check_solve = solve(square, input, 0);
	if (check_solve)
		print_square(square);
	free_square(square);
	return (0);
}
