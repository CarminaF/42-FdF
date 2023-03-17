/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:35:45 by cfamilar          #+#    #+#             */
/*   Updated: 2023/02/23 16:06:33 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_cam	*init_cam(t_map *map)
{
	t_cam	*cam;

	cam = (t_cam *)ft_memalloc(sizeof(t_cam));
	if (!cam)
		error(INITIALIZATION_ERR);
	cam->zoom = get_min((WIN_WIDTH / map->width) / 2,
			(WIN_HEIGHT / map->depth) / 2);
	if (cam->zoom < 1)
		cam->zoom = 1;
	cam->x_trans = 120;
	cam->y_trans = 50;
	cam->x_rot = 0;
	cam->y_rot = 0;
	cam->z_rot = 0;
	cam->z_divisor = 2;
	cam->projection = ISO;
	return (cam);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!map)
		error(INITIALIZATION_ERR);
	map->width = 0;
	map->depth = 0;
	map->min_z = INT_MAX;
	map->max_z = INT_MIN;
	map->coord = NULL;
	return (map);
}

t_image	*init_image(t_fdf *fdf)
{
	t_image	*image;

	image = (t_image *)ft_memalloc(sizeof(t_image));
	if (!image)
		error(INITIALIZATION_ERR);
	image->width = WIN_WIDTH;
	image->height = WIN_HEIGHT;
	image->image = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	image->address = mlx_get_data_addr(image->image,
			&(image->bits_per_pixel), &(image->line_size), &(image->endian));
	return (image);
}

t_fdf	*init_fdf(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	if (!fdf)
		error(INITIALIZATION_ERR);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!(fdf->mlx && fdf->win))
		error(INITIALIZATION_ERR);
	fdf->image = init_image(fdf);
	fdf->map = map;
	return (fdf);
}
