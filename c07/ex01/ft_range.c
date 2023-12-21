/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:25:07 by jaehukim          #+#    #+#             */
/*   Updated: 2023/12/21 17:13:29 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	len;
	int	*arr;

	len = max - min;
	if (len <= 0)
		return (0);
	arr = (int *)malloc(sizeof(int) * len);
	if (!*arr)
		return (NULL);
	i = 0;
	while (i < len)
		arr[i++] = min++;
	return (arr);
}
