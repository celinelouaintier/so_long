/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-19 14:04:10 by clouaint          #+#    #+#             */
/*   Updated: 2024-07-19 14:04:10 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	destroy_images(t_data *data)
{
	int	i;

	i = 0;
	if (!data || !data->images)
		return ;
	if (data->images->floor)
		mlx_destroy_image(data->mlx, data->images->floor);
	if (data->images->wall)
		mlx_destroy_image(data->mlx, data->images->wall);
	while (i < 4)
	{
		if (data->images->player[i])
			mlx_destroy_image(data->mlx, data->images->player[i]);
		if (data->images->playerg[i])
			mlx_destroy_image(data->mlx, data->images->playerg[i]);
		i++;
	}
	if (data->images->collect)
		mlx_destroy_image(data->mlx, data->images->collect);
	if (data->images->exit)
		mlx_destroy_image(data->mlx, data->images->exit);
}

int	exit_game(t_data *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	free_map(game->map, game->height);
	exit(EXIT_FAILURE);
}

int	finish_game(t_data *game)
{
	mlx_destroy_window(game->mlx, game->window);
	destroy_images(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map, game->height);
	free(game->images);
	exit(0);
}
