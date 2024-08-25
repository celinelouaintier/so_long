/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-10 11:40:25 by clouaint          #+#    #+#             */
/*   Updated: 2024/07/11 11:11:46 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

int	test(char c)
{
	if (c == 'E' || c == 'C' || c == '0')
		return (1);
	return (0);
}

int	test_objet(char *map[], int haut, int longueur)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < haut)
	{
		j = 0;
		while (j < longueur)
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	place(char *map[], int *dimensions, int i, int j)
{
	int	count;

	count = 0;
	if (i > 0 && test(map[i - 1][j]))
	{
		map[i - 1][j] = 'P';
		count++;
	}
	if (i < dimensions[0] && test(map[i + 1][j]))
	{
		count++;
		map[i + 1][j] = 'P';
	}
	if (j < dimensions[1] && test(map[i][j + 1]))
	{
		count++;
		map[i][j + 1] = 'P';
	}
	if (j > 0 && test(map[i][j - 1]))
	{
		count++;
		map[i][j - 1] = 'P';
	}
	return (count);
}

int	process_map(char **map, int dimensions[2])
{
	int	i;
	int	j;

	i = 0;
	while (i < dimensions[0])
	{
		j = 0;
		while (j < dimensions[1])
		{
			if (map[i][j] == 'P')
				if (place(map, dimensions,
						i, j) > 0)
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	test_map(t_data *data)
{
	int		dimensions[2];
	int		test;
	int		result;
	char	**map;

	map = map_copy(data->map, data->height, data->width);
	if (!map)
		return (-1);
	dimensions[0] = data->height;
	dimensions[1] = data->width;
	test = 1;
	while (test != 0)
	{
		test = 0;
		test = process_map(map, dimensions);
	}
	result = test_objet(map, data->height, data->width);
	free_map(map, data->height);
	return (result);
}
