/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghop <seonghop@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:20:30 by seonghop          #+#    #+#             */
/*   Updated: 2023/12/03 15:36:02 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_row(char side, char middle, int x)
{
	int	n;

	n = 0;
	while (n++ < x)
	{
		if (n == 1 || n == x)
			ft_putchar(side);
		else
			ft_putchar(middle);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	row;

	row = 0;
	while (row++ < y)
	{
		if (row == 1 || row == y)
			print_row('o', '-', x);
		else
			print_row('|', ' ', x);
	}
}
