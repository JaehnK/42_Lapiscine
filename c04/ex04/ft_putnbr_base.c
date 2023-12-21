/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:47:48 by jaehukim          #+#    #+#             */
/*   Updated: 2023/12/21 20:14:33 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	idx;
	int	check_idx;

	idx = 0;
	while (base[idx] != '\0')
	{
		check_idx = idx + 1;
		while (base[check_idx] != '\0')
		{
			if (base[idx] == base[check_idx])
				return (0);
			check_idx++;
		}
		if (base[idx] == '+' || base[idx] == '-')
			return (0);
		idx++;
	}
	if (idx <= 1)
		return (0);
	return (idx);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		num;
	int		len_base;
	int		counter;
	char	result[33];

	counter = 0;
	len_base = check_base(base);
	if (len_base == 0)
		return ;
	if (nbr == 0)
		write(1, &base[0], 1);
	if (nbr < 0)
		write(1, "-", 1);
	while (nbr != 0)
	{
		num = nbr % len_base;
		if (num < 0)
			num = -num;
		result[counter++] = base[num];
		nbr = nbr / len_base;
	}
	while (counter > 0)
		write(1, &result[--counter], 1);
}
