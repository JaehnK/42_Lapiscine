/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:19:00 by jaehukim          #+#    #+#             */
/*   Updated: 2023/12/07 21:56:10 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_printable(char a)
{
	if (a < 32 || a > 126)
		return (0);
	return (1);
}

void	ft_put_hex(char a)
{
	char			i2;
	char			i1;
	unsigned char	uc;

	uc = (unsigned char) a;
	i2 = (uc / 16) + '0';
	i1 = (uc % 16) + '0';
	if (i1 > '9')
		i1 += 39;
	if (i2 > '9')
		i2 += 39;
	write(1, "\\", 1);
	write(1, &i2, 1);
	write(1, &i1, 1);
}

void	ft_putstr_non_printable(char *str)
{	
	while (*str)
	{
		if (ft_check_printable(*str))
			write(1, str, 1);
		else
			ft_put_hex(*str);
		str++;
	}
}
