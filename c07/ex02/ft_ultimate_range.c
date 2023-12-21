/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:03:45 by jaehukim          #+#    #+#             */
/*   Updated: 2023/12/21 18:05:04 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;

	if ((max - min) <= 0)
	{
		*range = NULL;
		return (0);
	}
	arr = (int *)malloc((max - min) * sizeof(int));
	if (!arr)
		return (0);
	else
	{
		i = 0;
		while (i < (max - min))
		{
			arr[i] = min + i;
			i++;
		}
	}
	*range = arr;
	return ((max - min));
}
