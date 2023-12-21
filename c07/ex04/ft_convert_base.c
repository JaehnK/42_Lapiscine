/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:08:38 by jaehukim          #+#    #+#             */
/*   Updated: 2023/12/19 20:58:46 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_ascii_to_base(char c, int base_len, char *base);
int	check_base(char *base);

char	*ft_putnbr_base(int nbr, int len_base, char *base)
{
	int		num;
	int		counter;
	int		is_minus;
	char	*result;

	counter = 0;
	is_minus = 0;
	len_base = check_base(base);
	result = (char *)malloc(33 * sizeof(char));
	if (nbr < 0)
		is_minus = 1;
	while (nbr != 0)
	{
		num = nbr % len_base;
		if (num < 0)
			num = -num;
		result[counter++] = base[num];
		nbr = nbr / len_base;
	}
	if (is_minus == 1)
		result[counter++] = '-';
	result[counter] = '\0';
	return (result);
}

void	ft_rev(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		int_nbr;
	char	*result;

	if (check_base(base_from) == -1 || check_base(base_to) == -1)
		return (NULL);
	int_nbr = ft_atoi_base(nbr, base_from);
	if (int_nbr == 0)
		return ("0");
	result = ft_putnbr_base(int_nbr, check_base(base_to), base_to);
	ft_rev(result);
	return (result);
}
