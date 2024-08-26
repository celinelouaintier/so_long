/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:00:22 by clouaint          #+#    #+#             */
/*   Updated: 2024/08/26 18:37:52 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_map_closed(t_data *data)
{
	int	i;
	int	is_valid;

	i = 0;
	is_valid = 0;
	while (i < data->width)
	{
		if (data->map[0][i] != '1' || data->map[data->height - 1][i] != '1')
			is_valid = 1;
		i++;
	}
	i = 0;
	while (i < data->height)
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
			is_valid = 1;
		i++;
	}
	if (is_valid != 0)
	{
		ft_printf("Error\nMap is not properly closed\n");
		exit_game(data);
	}
}

void	check_map_double(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j++])
		{
			if (data->map[i][j] == 'P')
				data->p++;
			else if (data->map[i][j] == 'E')
				data->e++;
			else if (data->map[i][j] == 'C')
				data->c++;
		}
	}
	if (data->p != 1 || data->e != 1 || data->c < 1)
	{
		ft_printf("Error\nBad content in your map.\n");
		ft_printf("P=%d, E=%d, C=%d\n", data->p, data->e, data->c);
		exit_game(data);
	}
}

void	check_map_charac(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height - 1)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] != '0' &&
				data->map[i][j] != '1' &&
				data->map[i][j] != 'P' &&
				data->map[i][j] != 'E' &&
				data->map[i][j] != 'C' &&
				data->map[i][j] != '\n')
			{
				ft_printf("Error\nWrong characters in your map\n");
				exit_game(data);
			}
			j++;
		}
		i++;
	}
}

void	check_errors(t_data *data)
{
	is_map_closed(data);
	check_map_charac(data);
	check_map_double(data);
	if (get_screen_height() < data->height * 40)
	{
		ft_printf("Error\nThe map is too big\n");
		exit_game(data);
	}
	if (!test_map(data))
	{
		ft_printf("Error\nThe map is invalid.");
		ft_printf(" Some objects are not accessible.\n");
		exit_game(data);
	}
}
