/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:06:12 by inlee             #+#    #+#             */
/*   Updated: 2022/09/11 00:02:12 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_sort_string(char *str[], int size)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (ft_strcmp(str[j], str[j + 1]) < 0)
			{
				tmp = str[j + 1];
				str[j + 1] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	ft_sort_string(argv + 1, argc - 1);
	while (argc - 1 > 0)
	{
		putstr(argv[argc - 1]);
		write(1, "\n", 1);
		argc--;
	}
}
