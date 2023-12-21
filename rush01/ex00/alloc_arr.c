/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guejung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:25:53 by guejung           #+#    #+#             */
/*   Updated: 2023/12/10 05:31:51 by bonikoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

char	**alloc_arr(char *str)
{
	char	**arr;
	int		rows_index;
	int		cols_index;

	rows_index = 0;
	cols_index = 0;
	arr = (char **)malloc (4 * sizeof (char *));
	while (rows_index < 4)
	{
		arr[rows_index] = (char *)malloc ((ft_strlen(str) / 4) * sizeof (char));
		cols_index = 0;
		while (cols_index < (ft_strlen(str) / 4))
		{
			arr[rows_index][cols_index] = \
				str[2 * (rows_index * 4 + cols_index)];
			cols_index++;
		}
		rows_index++;
	}
	return (arr);
}
