/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:55:52 by jaehukim          #+#    #+#             */
/*   Updated: 2023/12/07 21:55:17 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_lower(char a)
{
	if (a > 'a' && a < 'z')
		return (1);
	return (0);
}

int	ft_check_num_str(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	else if (a >= 'a' && a <= 'z')
		return (1);
	else if (a >= 'A' && a <= 'Z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (ft_check_lower(str[0]))
		str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		if (ft_check_lower(str[i]) == 1 && ft_check_num_str(str[i - 1]) == 0)
			str[i] = str[i] - 32;
		else if (ft_check_num_str(str[i - 1]) == 1)
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
