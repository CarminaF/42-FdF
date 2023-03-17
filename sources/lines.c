/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:14:27 by cfamilar          #+#    #+#             */
/*   Updated: 2023/02/23 15:45:13 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	absolute(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

static int	set_error(t_coord delta)
{
	int	error;

	if (delta.x > delta.y)
		error = delta.x;
	else
		error = -delta.y;
	error /= 2;
	return (error);
}

static t_coord	set_direction(t_coord start, t_coord end)
{
	t_coord	direction;

	if (start.x < end.x)
		direction.x = 1;
	else
		direction.x = -1;
	if (start.y < end.y)
		direction.y = 1;
	else
		direction.y = -1;
	return (direction);
}

static void	pixel_put(t_image *image, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		i = (x * image->bits_per_pixel / 8) + (y * image->line_size);
		image->address[i] = color;
		image->address[++i] = color >> 8;
		image->address[++i] = color >> 16;
	}
}

void	draw_lines(t_coord start, t_coord end, t_image *image)
{
	t_coord	delta;
	t_coord	direction;
	t_coord	curr;
	int		error[2];

	delta.x = absolute(start.x - end.x);
	delta.y = absolute(start.y - end.y);
	direction = set_direction(start, end);
	error[0] = set_error(delta);
	curr = start;
	while (curr.x != end.x || curr.y != end.y)
	{
		pixel_put(image, curr.x, curr.y, get_color(curr, start, end, delta));
		error[1] = error[0];
		if (error[1] > -delta.x)
		{
			error[0] -= delta.y;
			curr.x += direction.x;
		}
		if (error[1] < delta.y)
		{
			error[0] += delta.x;
			curr.y += direction.y;
		}
	}
}
