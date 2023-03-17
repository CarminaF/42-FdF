/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:25:42 by cfamilar          #+#    #+#             */
/*   Updated: 2023/02/23 15:18:17 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate(int key, t_fdf *fdf)
{
	if (key == KEY_Q)
		fdf->camera->x_rot -= 0.05;
	if (key == KEY_W)
		fdf->camera->x_rot += 0.05;
	if (key == KEY_A)
		fdf->camera->y_rot -= 0.05;
	if (key == KEY_S)
		fdf->camera->y_rot += 0.05;
	if (key == KEY_Z)
		fdf->camera->z_rot -= 0.05;
	if (key == KEY_X)
		fdf->camera->z_rot += 0.05;
	draw(fdf->map, fdf->camera, fdf->image, fdf);
}

void	translate(int key, t_fdf *fdf)
{
	if (key == KEY_UP)
		fdf->camera->y_trans -= 10;
	if (key == KEY_DOWN)
		fdf->camera->y_trans += 10;
	if (key == KEY_LEFT)
		fdf->camera->x_trans -= 10;
	if (key == KEY_RIGHT)
		fdf->camera->x_trans += 10;
	draw(fdf->map, fdf->camera, fdf->image, fdf);
}

void	zoom(int key, t_fdf *fdf)
{
	if (key == KEY_MINUS)
		fdf->camera->zoom--;
	if (key == KEY_PLUS)
		fdf->camera->zoom++;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw(fdf->map, fdf->camera, fdf->image, fdf);
}

void	change_projection(int key, t_fdf *fdf)
{
	fdf->camera->x_rot = 0;
	fdf->camera->y_rot = 0;
	fdf->camera->z_rot = 0;
	if (key == KEY_I)
		fdf->camera->projection = ISO;
	else if (key == KEY_P)
		fdf->camera->projection = PARALLEL;
	draw(fdf->map, fdf->camera, fdf->image, fdf);
}
