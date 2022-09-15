/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:04:47 by inlee             #+#    #+#             */
/*   Updated: 2022/09/15 16:36:11 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i])
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (dest);
}

int	ft_total_strlen(int size, char **strs, int sep_len)
{
	int	strs_len;
	int	i;

	strs_len = 0;
	i = 0;
	while (i < size - 1)
	{
		strs_len += ft_strlen(strs[i]);
		strs_len += sep_len;
		i++;
	}
	strs_len += ft_strlen(strs[i]);
	return (strs_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		strs_len;
	char	*full_str;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	strs_len = ft_total_strlen(size, strs, ft_strlen(sep));
	full_str = (char *)malloc((strs_len + 1) * sizeof(char));
	if (full_str == 0)
		return (0);
	i = 0;
	*full_str = 0;
	while (i < size)
	{
		ft_strcat(full_str, strs[i]);
		if (i < size - 1)
			ft_strcat(full_str, sep);
		i++;
	}
	return (full_str);
}
