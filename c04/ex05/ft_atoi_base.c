/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:27:00 by jaehukim          #+#    #+#             */
/*   Updated: 2023/12/19 11:15:55 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_ascii_to_base(char c, int base_len, char *base)
{
	int	i;

	i = 0;
	while (i < base_len)
	{
		if (c == base[i])
			break ;
		else
			i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	idx;
	int	nbr;
	int	sign;
	int	base_len;

	if (check_base(base) == 0)
		return (0);
	idx = 0;
	nbr = 0;
	sign = 1;
	base_len = check_base(base);
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	while (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	while (str[idx] != '\0')
		nbr = nbr * base_len + ft_ascii_to_base(str[idx++], base_len, base);
	return (nbr * sign);
}
