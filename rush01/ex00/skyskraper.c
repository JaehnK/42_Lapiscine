/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyskraper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonikoo <bonikoo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:37:30 by bonikoo           #+#    #+#             */
/*   Updated: 2023/12/10 23:40:48 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_arr(char **arr, int width, int height);

int		validation(char **input_arr, char **output_arr, int col, int row);

int	check_rows(char **arr, int row_index, int col_index, char word)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i == col_index)
		{
			i++;
			continue ;
		}
		if (arr[row_index][i] == word)
			return (0);
		i++;
	}
	return (1);
}

int	check_cols(char **arr, int row_index, int col_index, char word)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i == row_index)
		{
			i++;
			continue ;
		}
		if (arr[i][col_index] == word)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(char **arr, int row_index, int col_index, char word)
{
	if (check_rows(arr, row_index, col_index, word) == 1 \
			&& check_cols(arr, row_index, col_index, word) == 1)
		return (1);
	return (0);
}

int	ft_validation(char **input_arr, char **arr)
{
	if (validation(input_arr, arr, 0, 0) \
			&& validation(input_arr, arr, 1, 1) \
			&& validation(input_arr, arr, 2, 2) \
			&& validation(input_arr, arr, 3, 3))
		return (1);
	else
		return (-1);
}

int	skyskraper(char **input_arr, char **arr, int r, int size)
{
	char	word;
	int		row_index;
	int		col_index;

	row_index = r / 4;
	col_index = r % 4;
	if (r > 15)
		return (ft_validation(input_arr, arr));
	if (arr[row_index][col_index] != '0')
		return (skyskraper(input_arr, arr, r + 1, size));
	else
	{
		word = '0';
		while (++word < '5')
		{
			arr[row_index][col_index] = word;
			if (check_duplicate(arr, row_index, col_index, word))
				{
				if (skyskraper(input_arr, arr, r + 1, size) == -1);
				{
					arr[row_index][col_index] = word +1;
				}
				}
			else
				arr[row_index][col_index] = '0';
		}
	}
	return (0);
}
