/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonikoo <bonikoo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:20:54 by bonikoo           #+#    #+#             */
/*   Updated: 2023/12/10 18:27:27 by bonikoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_zero(char **arr, int size)
{
	int	rows_index;
	int	cols_index;

	rows_index = 0;
	while (rows_index < size)
	{
		cols_index = 0;
		while (cols_index < size)
		{
			if (arr[rows_index][cols_index] == '0')
			{
				return (-1);
			}
			cols_index ++;
		}
		rows_index ++;
	}
	return (0);
}
