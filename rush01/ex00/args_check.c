/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guejung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:12:09 by guejung           #+#    #+#             */
/*   Updated: 2023/12/10 23:30:53 by guejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_error(char *str);

int	ft_strlen(char *str);

int	args_check(char *str)
{
	int		index;
	int		result;

	index = 0;
	result = 0;
	if (ft_strlen(str) != 16)
		return (-1);
	while (str[index] != '\0')
	{
		if (index % 2 == 1 && str[index] != ' ')
			return (-1);
		if (index % 2 == 0)
		{
			if (str[index] < '1' && str[index] > '4')
				return (-1);
		}
		index++;
	}
	if (result == 0 && index < 31)
		result = -1;
	return (result);
}
