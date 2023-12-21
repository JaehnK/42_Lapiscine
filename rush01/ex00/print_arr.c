/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guejung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:40:03 by guejung           #+#    #+#             */
/*   Updated: 2023/12/10 06:19:22 by bonikoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *str);

void	print_arr(char **arr, int width, int height)
{
	int		rows_index;
	int		cols_index;
	char	character;

	rows_index = 0;
	while (rows_index < width)
	{
		cols_index = 0;
		while (cols_index < height)
		{
			write(1, &arr[rows_index][cols_index], 1);
			if (cols_index < height - 1)
			{
				character = ' ';
				write(1, &character, 1);
			}
			else
			{
				character = '\n';
				write(1, &character, 1);
			}
			cols_index++;
		}
		rows_index++;
	}
}
