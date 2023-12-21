/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:05:46 by jaehukim          #+#    #+#             */
/*   Updated: 2023/12/21 18:20:53 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	if (size <= 0)
		return (0);
	while (i < size)
		total_len += ft_strlen(strs[i++]);
	total_len += (size - 1) * ft_strlen(sep);
	return (total_len);
}

void	ft_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_len;
	char	*ans;

	i = 0;
	total_len = ft_total_len(size, strs, sep) + 1;
	ans = (char *)malloc(total_len * sizeof(char));
	if (!ans)
		return (NULL);
	while (i < size)
	{
		ft_strcat(ans, strs[i]);
		if (i < size - 1)
			ft_strcat(ans, sep);
		i++;
	}
	ans[total_len] = '\0';
	return (ans);
}
