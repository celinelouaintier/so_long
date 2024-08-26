/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:03:56 by clouaint          #+#    #+#             */
/*   Updated: 2024/08/26 19:16:05 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	animate_player(t_data *data)
{
	data->frame_count++;
	if (data->frame_count >= 100)
	{
		data->current_sprite = (data->current_sprite + 1) % 4;
		data->frame_count = 0;
	}
}

int	game_loop(t_data *data)
{
	animate_player(data);
	draw_map(data);
	display_steps(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		is_ber(argv[1]);
		ft_memset(&data, 0, sizeof(t_data));
		read_map(&data, argv[1]);
		find_initial_position(&data);
		check_errors(&data);
		data.mlx = mlx_init();
		if (!data.mlx)
			return (1);
		loading_textures(&data);
		data.window = mlx_new_window(data.mlx, data.width * 40,
				data.height * 40, "so_long");
		mlx_hook(data.window, 17, 0, finish_game, &data);
		mlx_hook(data.window, 2, 1L << 0, player_move, &data);
		mlx_loop_hook(data.mlx, game_loop, &data);
		mlx_loop(data.mlx);
	}
}
