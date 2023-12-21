/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:50:24 by jaehukim          #+#    #+#             */
/*   Updated: 2023/12/10 20:23:28 by guejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid_rev_row(int s, char **arr, int idx)
{
	int		i;
	int		cnt;
	char	max;

	i = 3;
	max = 0;
	cnt = 0;
	while (i >= 0)
	{
		if (arr[i][idx] > max)
		{
			max = arr[i][idx];
			cnt += 1;
		}
		i--;
	}
	return (cnt == s);
}

int	valid_row(int s, char **arr, int idx)
{
	int		i;
	int		cnt;
	char	max;

	i = 0;
	max = 0;
	cnt = 0;
	while (i < 4)
	{
		if (arr[i][idx] > max)
		{
			max = arr[i][idx];
			cnt += 1;
		}
		i++;
	}
	return (cnt == s);
}

int	valid_rev_col(int s, char **arr, int idx)
{
	int		i;
	int		cnt;
	char	max;

	i = 3;
	max = 0;
	cnt = 0;
	while (i >= 0)
	{
		if (arr[idx][i] > max)
		{
			max = arr[idx][i];
			cnt += 1;
		}
		i--;
	}
	return (cnt == s);
}

int	valid_col(int s, char **arr, int idx)
{
	int		i;
	int		cnt;
	char	max;

	i = 0;
	max = 0;
	cnt = 0;
	while (i < 4)
	{
		if (arr[idx][i] > max)
		{
			max = arr[idx][i];
			cnt += 1;
		}
		i++;
	}
	return (cnt == s);
}

int	validation(char **input_arr, char **output_arr, int col, int row)
{
	if (valid_rev_row(input_arr[3][row], output_arr, row) == 1 \
			&& valid_row(input_arr[2][row], output_arr, row) == 1)
	{
		if (valid_rev_col(input_arr[1][col], output_arr, col) == 1 \
				&& valid_col(input_arr[0][col], output_arr, col) == 1)
			return (1);
	}
	return (0);
}
