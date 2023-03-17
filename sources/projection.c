/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:29:02 by cfamilar          #+#    #+#             */
/*   Updated: 2023/02/23 15:59:15 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rotate_x(int *y, int *z, double x_rot)
{
	int	previous_y;
	int	previous_z;

	previous_y = *y;
	previous_z = *z;
	*y = previous_y * cos(x_rot) + previous_z * sin(x_rot);
	*z = -previous_y * sin(x_rot) + previous_z * cos(x_rot);
}

static void	rotate_y(int *x, int *z, double y_rot)
{
	int	previous_x;
	int	previous_z;

	previous_x = *x;
	previous_z = *z;
	*x = previous_x * cos(y_rot) + previous_z * sin(y_rot);
	*z = -previous_x * sin(y_rot) + previous_z * cos(y_rot);
}

static void	rotate_z(int *x, int *y, double z_rot)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(z_rot) - previous_y * sin(z_rot);
	*y = previous_x * sin(z_rot) + previous_y * cos(z_rot);
}

static void	isometric(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_coord	project(t_coord coord, t_map *map, t_cam *cam)
{
	coord.x *= cam->zoom;
	coord.y *= cam->zoom;
	coord.z *= cam->zoom / cam->z_divisor;
	coord.x -= (map->width * cam->zoom) / 2;
	coord.y -= (map->depth * cam->zoom) / 2;
	rotate_x(&coord.y, &coord.z, cam->x_rot);
	rotate_y(&coord.x, &coord.z, cam->y_rot);
	rotate_z(&coord.x, &coord.y, cam->z_rot);
	if (cam->projection == ISO)
		isometric(&coord.x, &coord.y, coord.z);
	coord.x += WIN_WIDTH / 2 + cam->x_trans;
	coord.y += WIN_HEIGHT / 2 + cam->y_trans;
	return (coord);
}
