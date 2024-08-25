/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-02 16:08:05 by clouaint          #+#    #+#             */
/*   Updated: 2024/07/09 17:00:44 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

int	map_size(t_data *data, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error\nMap not read\n");
		close(fd);
		exit_game(data);
	}
	data->width = ft_strlen(line) - 1;
	data->height = 0;
	while (line)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (data->height);
}

void	read_map(t_data *data, char *file)
{
	char	*line;
	int		i;
	int		fd;

	map_size(data, file);
	fd = open(file, O_RDONLY);
	i = 0;
	data->map = malloc(sizeof(char *) * (data->height + 2));
	if (!data->map)
	{
		perror("Error allocating memory");
		close(fd);
		exit_game(data);
	}
	line = get_next_line(fd);
	while (line)
	{
		data->map[i] = line;
		data->map[i][data->width] = '\0';
		i++;
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	close(fd);
}


void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (data->map[i][j])
		{
			draw_tile(data, i, j);
			j++;
		}
		i++;
	}
}
