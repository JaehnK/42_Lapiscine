/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghop <seonghop@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:26:52 by seonghop          #+#    #+#             */
/*   Updated: 2023/12/03 19:21:41 by seonghop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	rush(int x, int y);

int	isnum_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (str[0] == '-')
	{
		write(2, "Minus Number ", 13);
		return (-1);
	}
	while (str[i++] != '\0')
	{
		if (str[i - 1] < '0' || str[i - 1] > '9')
		{
			write(2, "Not Number ", 11);
			return (-1);
		}
		result = result * 10 + str[i - 1] - 48;
		if (result > 211)
		{
			write(2, "Big Number ", 11);
			return (-1);
		}
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc != 3)
	{
		write(2, "Put 2 Number", 13);
		return (-1);
	}	
	x = isnum_atoi(argv[1]);
	y = isnum_atoi(argv[2]);
	if (x == 0 && y == 0)
	{	
		write(2, "Zero Number", 11);
		return (-1);
	}
	else if (x == -1 || y == -1)
		return (-1);
	rush(x, y);
	return (0);
}
