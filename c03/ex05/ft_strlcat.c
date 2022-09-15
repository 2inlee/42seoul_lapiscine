/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inlee <inlee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:13:10 by inlee             #+#    #+#             */
/*   Updated: 2022/09/15 20:52:05 by inlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *dest)
{
	unsigned int	cnt;

	cnt = 0;
	while (dest[cnt] != '\0')
		cnt++;
	return (cnt);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = str_len(dest);
	src_len = str_len(src);
	i = 0;
	while (*(src + i) && dest_len + i + 1 < size)
	{
		*(dest + dest_len + i) = *(src + i);
		i++;
	}
	*(dest + dest_len + i) = '\0';
	if (size < dest_len)
		return (src_len + size);
	return (src_len + dest_len);
}
