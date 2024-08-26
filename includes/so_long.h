/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:00:32 by clouaint          #+#    #+#             */
/*   Updated: 2024/08/26 20:07:49 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <X11/Xlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

# define MLX_FTI 	mlx_xpm_file_to_image
# define FLOOR		"./assets/floor.xpm"
# define WALL		"./assets/wall.xpm"
# define PLAYER1	"./assets/player1.xpm"
# define PLAYER2	"./assets/player2.xpm"
# define PLAYER3	"./assets/player3.xpm"
# define PLAYER4	"./assets/player4.xpm"
# define PLAYERG1	"./assets/playerg1.xpm"
# define PLAYERG2	"./assets/playerg2.xpm"
# define PLAYERG3	"./assets/playerg3.xpm"
# define PLAYERG4	"./assets/playerg4.xpm"
# define COLLECT	"./assets/collect.xpm"
# define EXIT		"./assets/exit.xpm"

typedef struct s_images
{
	void	*player[4];
	void	*playerg[4];
	void	*wall;
	void	*floor;
	void	*collect;
	void	*exit;
}	t_images;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	char		**map;
	int			height;
	int			width;
	char		*file;
	int			x;
	int			y;
	int			count;
	int			collect;
	int			num_c;
	int			current_sprite;
	int			frame_count;
	int			direct;
	int			p;
	int			e;
	int			c;
	t_images	*images;
}	t_data;

void	loading_textures(t_data *data);
void	draw_map(t_data *data);
void	read_map(t_data *data, char *file);
void	find_initial_position(t_data *data);
int		player_move(int keycode, t_data *data);
int		exit_game(t_data *game);
void	display_steps(t_data *data);
void	check_errors(t_data *data);
int		test_map(t_data *data);
char	**map_copy(char **map, int height, int width);
void	free_map(char **map, int height);
void	destroy_images(t_data *data);
int		exit_game(t_data *game);
int		finish_game(t_data *game);
void	is_ber(const char *str);
void	loading_textures(t_data *data);
void	draw_tile(t_data *data, int i, int j);
int 	get_screen_height(void);
void	is_not_loaded(t_data *data);

#endif
