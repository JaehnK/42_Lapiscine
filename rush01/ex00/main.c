/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guejung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:01:57 by guejung           #+#    #+#             */
/*   Updated: 2023/12/10 23:18:53 by bonikoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		print_error(char *str);

int		args_check(char *str);

int		ft_strlen(char *str);

int		ft_check_zero(char **arr, int size);

char	**alloc_arr(char *str);

void	free_arr(char **arr, int num);

void	print_str(char *str);

void	print_arr(char **arr, int width, int height);

char	**rush(char **arr, int size);

int	main(int argc, char **argv)
{
	char	**input;
	char	**output;
	char	*str;

	if (argc != 2)
		return (print_error("Error"));
	else
	{
		str = argv[1];
		if (args_check(str) > -1)
		{
			input = alloc_arr(str);
			output = rush(input, (ft_strlen(str) / 4));
			if (ft_check_zero(output, (ft_strlen(str) / 4)) < 0)
				return (print_error("Error"));
			else
				print_arr(output, (ft_strlen(str) / 4), (ft_strlen(str) / 4));
			free_arr(input, ft_strlen(str) / 4);
		}
		else
			return (print_error("Error"));
	}
	free_arr(output, 4);
	return (0);
}
