/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:43:31 by jaehukim          #+#    #+#             */
/*   Updated: 2023/12/16 11:13:58 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	test(int *arr, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (arr[i] - i == arr[row] - row)
			return (0);
		if (arr[i] + i == arr[row] + row)
			return (0);
		if (arr[i] == arr[row])
			return (0);
		i++;
	}
	return (1);
}

void	print_arr(int *arr)
{
	char	temp;
	int		i;

	i = 0;
	while (i < 10)
	{
		temp = arr[i] + '0';
		write(1, &temp, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	recur(int *arr, int r)
{
	int	num;
	int	cnt;

	if (r == 10)
	{
		print_arr(arr);
		return (1);
	}
	cnt = 0;
	num = 0;
	while (num < 10)
	{	
		arr[r] = num;
		if (test(arr, r))
			cnt += recur(arr, r + 1);
		num += 1;
	}
	return (cnt);
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[12];

	return (recur(arr, 0));
}
