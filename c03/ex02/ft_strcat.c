/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:03:22 by jaehukim          #+#    #+#             */
/*   Updated: 2023/12/13 11:42:45 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		destlen;

	destlen = 0;
	while (dest[destlen] != '\0')
		destlen++;
	while (*src)
	{
		dest[destlen++] = *src;
		src++;
	}
	dest[destlen] = '\0';
	return (dest);
}
