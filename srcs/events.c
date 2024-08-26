/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:05:24 by clouaint          #+#    #+#             */
/*   Updated: 2024/08/26 19:34:39 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	update_player_position(t_data *data, int x, int y)
{
	if (data->map[y][x] != '1')
	{
		if (data->map[y][x] == 'E')
		{
			if (data->collect == data->num_c)
				finish_game(data);
			return (0);
		}
		else if (data->map[y][x] == 'C')
			data->collect++;
		data->map[data->y][data->x] = '0';
		data->map[y][x] = 'P';
		data->x = x;
		data->y = y;
		return (1);
	}
	return (0);
}

int	move_x(int keycode, t_data *data, int new_place_x)
{
	if (keycode == 'a')
	{
		new_place_x--;
		data->direct = 1;
	}
	if (keycode == 'd')
	{
		new_place_x++;
		data->direct = 0;
	}
	return (new_place_x);
}

int	move_y(int keycode, int new_place_y)
{
	if (keycode == 'w')
		new_place_y--;
	if (keycode == 's')
		new_place_y++;
	return (new_place_y);
}

void	display_steps(t_data *data)
{
	char	*steps;

	steps = ft_itoa(data->count);
	if (steps)
	{
		mlx_string_put(data->mlx, data->window, 10, 20, 0x000000, steps);
		free(steps);
	}
}

int	player_move(int keycode, t_data *data)
{
	int	new_place_x;
	int	new_place_y;
	int	moved;

	new_place_x = data->x;
	new_place_y = data->y;
	if (keycode == 65307)
		finish_game(data);
	new_place_x = move_x(keycode, data, new_place_x);
	new_place_y = move_y(keycode, new_place_y);
	moved = update_player_position(data, new_place_x, new_place_y);
	if (moved && (keycode == 'a' || keycode == 'd'
		|| keycode == 'w' || keycode == 's'))
	{
		data->count++;
		draw_map(data);
		display_steps(data);
	}
	return (0);
}
