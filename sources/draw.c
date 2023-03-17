/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:28:40 by cfamilar          #+#    #+#             */
/*   Updated: 2023/02/23 16:07:35 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	background_colour(t_image *image)
{
	int	*new_image;
	int	i;

	ft_bzero(image->address,
		WIN_WIDTH * WIN_HEIGHT *(image->bits_per_pixel / 8));
	new_image = (int *)(image->address);
	i = 0;
	while (i < (WIN_WIDTH * WIN_HEIGHT))
	{
		new_image[i] = BG_COLOUR;
		i++;
	}
}

void	draw(t_map *map, t_cam *cam, t_image *image, t_fdf *fdf)
{
	int	i;
	int	j;

	background_colour(image);
	height_colours(map);
	i = 0;
	while (i < map->depth)
	{
		j = 0;
		while (j < map->width)
		{
			if (j + 1 < map->width)
				draw_lines(project(map->coord[i][j], map, cam),
					project(map->coord[i][j + 1], map, cam), image);
			if (i + 1 < map->depth)
				draw_lines(project(map->coord[i][j], map, cam),
					project(map->coord[i + 1][j], map, cam), image);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, image->image, 0, 0);
	print_menu(fdf);
}
