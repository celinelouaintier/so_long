/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:28:23 by clouaint          #+#    #+#             */
/*   Updated: 2024/08/26 20:04:12 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// separer cette fonction en deux et verifier si on a les droits sur les textures (segfault quand on les chmod)
void	loading_textures(t_data *data)
{
	int	width;
	int	height;

	data->images = malloc(sizeof(t_images));
	if (!data->images)
		return ;
	data->images->floor = MLX_FTI(data->mlx, FLOOR, &width, &height);
	data->images->wall = MLX_FTI(data->mlx, WALL, &width, &height);
	data->images->player[0] = MLX_FTI(data->mlx, PLAYER1, &width, &height);
	data->images->player[1] = MLX_FTI(data->mlx, PLAYER2, &width, &height);
	data->images->player[2] = MLX_FTI(data->mlx, PLAYER3, &width, &height);
	data->images->player[3] = MLX_FTI(data->mlx, PLAYER4, &width, &height);
	data->images->playerg[0] = MLX_FTI(data->mlx, PLAYERG1, &width, &height);
	data->images->playerg[1] = MLX_FTI(data->mlx, PLAYERG2, &width, &height);
	data->images->playerg[2] = MLX_FTI(data->mlx, PLAYERG3, &width, &height);
	data->images->playerg[3] = MLX_FTI(data->mlx, PLAYERG4, &width, &height);
	data->images->collect = MLX_FTI(data->mlx, COLLECT, &width, &height);
	data->images->exit = MLX_FTI(data->mlx, EXIT, &width, &height);
	is_not_loaded(data);
}

void	draw_tile(t_data *data, int i, int j)
{
	if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->window,
			data->images->floor, j * 40, i * 40);
	else if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->window,
			data->images->wall, j * 40, i * 40);
	else if (data->map[i][j] == 'P')
	{
		if (data->direct == 0)
			mlx_put_image_to_window(data->mlx, data->window,
				data->images->player[data->current_sprite],
				j * 40, i * 40);
		else
			mlx_put_image_to_window(data->mlx, data->window,
				data->images->playerg[data->current_sprite],
				j * 40, i * 40);
	}
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->window,
			data->images->collect, j * 40, i * 40);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->window,
			data->images->exit, j * 40, i * 40);
}