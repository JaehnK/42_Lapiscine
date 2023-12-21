/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonikoo <bonikoo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 05:45:54 by bonikoo           #+#    #+#             */
/*   Updated: 2023/12/10 07:44:41 by bonikoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

char	**init_arr(int size)
{
	char	**arr;
	int		rows_index;
	int		cols_index;

	rows_index = 0;
	arr = (char **)malloc (size * sizeof (char *));
	while (rows_index < size)
	{
		cols_index = 0;
		arr[rows_index] = (char *)malloc (size * sizeof (char));
		while (cols_index < size)
		{
			arr[rows_index][cols_index] = '0';
			cols_index ++;
		}
		rows_index ++;
	}
	return (arr);
}
