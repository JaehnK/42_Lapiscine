/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guejung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:28:46 by guejung           #+#    #+#             */
/*   Updated: 2023/12/10 04:27:34 by bonikoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_arr(char **arr, int num)
{
	int		index;

	index = 0;
	while (index < num)
	{
		free (arr[index]);
		index++;
	}
	free (arr);
}
