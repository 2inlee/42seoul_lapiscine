/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:35:52 by inlee             #+#    #+#             */
/*   Updated: 2022/08/31 20:52:36 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		cnt;

	cnt = 0;
	while (*str != '\0')
	{
		cnt++;
		str++;
	}
	return (cnt);
}
