/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:53:15 by cfamilar          #+#    #+#             */
/*   Updated: 2023/02/23 16:12:22 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* Headers */
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h> 
# include "../libraries/minilibx/mlx.h"
# include "../libraries/libft/libft.h"
# include "../libraries/libft/get_next_line.h"

/* Macros */

// Window
# define WIN_HEIGHT 700
# define WIN_WIDTH 1200
# define WIN_TITLE "FdF"

// Colours
# define TEXT_COLOUR 0xFFFFFF
# define BG_COLOUR 0x000000
# define LINE_25 0xDE0279
# define LINE_50 0xEC649E
# define LINE_75 0xF79AC1
# define LINE_100 0xFFCCE2

// Keys
# define KEY_ESC 53
// Translate
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
// Zoom
# define KEY_MINUS 27 
# define KEY_PLUS 24
// Projection
# define KEY_I 34 
# define KEY_P 35 
//rotate x
# define KEY_Q 12 
# define KEY_W 13 
//rotate y
# define KEY_A 0 
# define KEY_S 1 
//rotate z
# define KEY_Z 6
# define KEY_X 7
//height
# define KEY_K 40 
# define KEY_L 37 

// Error Messages
# define INITIALIZATION_ERR "Initialization error.\n"
# define MAP_READING_ERR "Map reading error.\n"
# define MAP_LOADED "Map loaded.\n"
# define OPEN_ERR "Error with opening file.\n"
# define USAGE_ERR "Usage: ./fdf <MAP>\n"

/* Structs */
typedef enum e_projection
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
	int	colour;
}	t_coord;

typedef struct s_map
{
	int		width;
	int		depth;
	int		min_z;
	int		max_z;
	t_coord	**coord;
}	t_map;

typedef struct s_image
{
	void	*image;
	char	*address;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_image;

typedef struct s_cam
{
	int				x_trans;
	int				y_trans;
	double			x_rot;
	double			y_rot;
	double			z_rot;
	float			z_divisor;
	int				zoom;
	t_projection	projection;
}	t_cam;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_image	*image;
	t_cam	*camera;
	t_map	*map;
}	t_fdf;

/* Functions */
void		error(char *str);
void		*ft_memalloc(size_t size);
int			read_colour(char *str);
int			get_min(int a, int b);
void		height_colours(t_map *map);
void		print_menu(t_fdf *fdf);
int			close_window(t_fdf *fdf);
void		rotate(int key, t_fdf *fdf);
void		translate(int key, t_fdf *fdf);
void		zoom(int key, t_fdf *fdf);
void		change_projection(int key, t_fdf *fdf);
int			read_map(t_map *map, int fd);
void		free_array(char **array);
void		set_mlx_hooks(t_fdf *fdf);
void		change_height(int key, t_fdf *fdf);
void		draw_lines(t_coord start, t_coord end, t_image *image);
void		draw(t_map *map, t_cam *cam, t_image *image, t_fdf *fdf);
int			get_color(t_coord curr, t_coord start, t_coord end, t_coord delta);
t_fdf		*init_fdf(t_map *map);
t_map		*init_map(void);
t_cam		*init_cam(t_map *map);
t_image		*init_image(t_fdf *fdf);
t_coord		project(t_coord coord, t_map *map, t_cam *cam);

#endif
