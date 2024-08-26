/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:31:09 by clouaint          #+#    #+#             */
/*   Updated: 2024/08/26 18:39:13 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*copy_line(char *line, int width)
{
	char	*copy;
	int		j;

	copy = malloc(sizeof(char) * (width + 1));
	if (!copy)
		return (NULL);
	j = 0;
	while (j < width)
	{
		copy[j] = line[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

char	**map_copy(char **map, int height, int width)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * height);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = copy_line(map[i], width);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

void	find_initial_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'P')
			{
				data->x = j;
				data->y = i;
			}
			else if (data->map[i][j] == 'C')
				data->num_c++;
			j++;
		}
		i++;
	}
}

void	is_ber(const char *str)
{
	int	size;

	size = ft_strlen((char *)str);
	if (str[size - 1] == 'r' && str[size - 2] == 'e')
	{
		if (str[size - 3] == 'b' || str[size - 4] == '.')
			return ;
	}
	ft_printf("Error\nMap not ber\n");
	exit(-1);
}

int get_screen_height(void)
{
    Display *display;
    int screen_num;
    int screen_height;

    display = XOpenDisplay(NULL);
    if (!display)
        return 600;  // Valeur par défaut si l'affichage échoue

    screen_num = DefaultScreen(display);
    screen_height = XDisplayHeight(display, screen_num);

    XCloseDisplay(display);
    return (screen_height);
}

