/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:25:57 by jaehukim          #+#    #+#             */
/*   Updated: 2023/12/13 11:37:45 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	str_idx;
	int	find_idx;
	int	btn;

	str_idx = 0;
	btn = 0;
	if (*to_find == '\0')
		return (str);
	while (str_idx <= ft_strlen(str) - ft_strlen(to_find))
	{
		find_idx = 0;
		btn = 0;
		while (find_idx < ft_strlen(to_find))
		{
			if (str[str_idx + find_idx] == to_find[find_idx])
				btn += 1;
			else
				btn = 0;
			find_idx++;
		}
		if (btn == ft_strlen(to_find))
			return (str + str_idx);
		str_idx++;
	}
	return (0);
}
