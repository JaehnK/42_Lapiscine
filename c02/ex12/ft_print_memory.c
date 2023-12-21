/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:41:55 by jaehukim          #+#    #+#             */
/*   Updated: 2023/12/12 22:59:12 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	addr_dec2hex(char hex[16], unsigned long long int dec)
{
	char	digits[17];
	int		digit;
	int		i;

	i = 16;
	digit = -1;
	while (digit++ < 15)
	{
		if (digit >= 10)
			digits[digit] = digit + 87;
		else
			digits[digit] = digit + 48;
	}
	digits[16] = '\0';
	while (--i >= 0)
	{
		hex[i] = digits [dec % 16];
		dec = dec >> 4;
	}
	hex[16] = '\0';
	write(1, hex, 16);
}

void	char2hex(unsigned char c, unsigned int i, unsigned int size)
{
	char	i2;
	char	i1;

	if (i < size)
	{
		i2 = (c / 16) + '0';
		i1 = (c % 16) + '0';
		if (i1 > '9')
			i1 += 39;
		if (i2 > '9')
			i2 += 39;
		else
		{
			write(1, &i2, 1);
			write(1, &i1, 1);
		}
	}
	else
		write(1, "  ", 2);
}

void	print_str(char *str, int line, unsigned int size)
{
	int				i;
	unsigned char	uc;

	i = 0;
	while (i < 16 && str[i + line * 16] != '\0')
	{
		uc = (unsigned char) str[i + line * 16];
		if (uc >= 32 && uc <= 126)
			write(1, &uc, 1);
		else
			write(1, ".", 1);
		i++;
	}
	if ((i + line * 16) == (int)size - 1)
		write(1, ".", 1);
	write(1, "\n", 1);
}

unsigned int	resize(unsigned int size)
{
	if (size % 16 == 0)
		return (size);
	else
		return ((size / 16 + 1) * 16);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char				hex[16];
	int					line;
	unsigned int		i;
	void				*ptr;

	ptr = addr;
	i = 0;
	line = 0;
	while (i < resize(size))
	{
		if (i % 16 == 0)
		{
			addr_dec2hex(hex, (unsigned long long int)addr + i);
			write(1, ": ", 2);
		}
		char2hex(*((unsigned char *)addr + i), i, size);
		if (i % 2 == 1)
			write(1, " ", 1);
		if (i % 16 == 15)
			print_str((char *)addr, line++, size);
		i++;
	}
	return (ptr);
}
