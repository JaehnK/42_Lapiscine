/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:50:18 by jaehukim          #+#    #+#             */
/*   Updated: 2023/12/21 18:20:33 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	count;
	int	i;	

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!is_charset(str[i], charset))
			count++;
		while (!is_charset(str[i], charset))
			i++;
		while (is_charset(str[i], charset))
			i++;
	}
	return (count);
}

char	*ft_pick_word(char *str, char *charset)
{
	int		i;
	int		cnt;
	char	*word;

	i = 0;
	cnt = 0;
	while (!is_charset(str[cnt], charset))
		cnt++;
	word = (char *)malloc(sizeof(char) * cnt);
	if (!word)
		return (0);
	while (i < cnt)
	{
		word[i] = *str++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		idx;
	char	**words;

	idx = 0;
	words = (char **)malloc(sizeof(char *) * (count_word(str, charset) + 1));
	if (!words)
		return (0);
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			words[idx] = ft_pick_word(str, charset);
			i = 0;
			while (words[idx][i++])
				str++;
			idx++;
		}
		str++;
	}
	words[idx] = 0;
	return (words);
}
