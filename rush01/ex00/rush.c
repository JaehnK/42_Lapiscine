/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonikoo <bonikoo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 05:57:13 by bonikoo           #+#    #+#             */
/*   Updated: 2023/12/10 23:18:33 by bonikoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		print_error(char *str);

int		ft_strlen(char *str);

char	**init_arr(int size);

void	print_arr(char **arr, int width, int height);

void	free_arr(char **arr, int size);

int		skyskraper(char **input_arr, char **arr, int r, int size);

char	**rush(char **input, int size)
{
	char	**output;

	output = init_arr(size);
	skyskraper(input, output, 0, size);
	return (output);
}
