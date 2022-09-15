/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:35:33 by inlee             #+#    #+#             */
/*   Updated: 2022/09/10 18:11:54 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		j;
	char	a;

	j = 0;
	argc -= 1;
	while (argc > 0)
	{
		j = 0;
		while (argv[argc][j] != '\0')
		{
			a = argv[argc][j];
			write(1, &a, 1);
			j++;
		}
		write(1, "\n", 1);
		argc--;
	}
}
