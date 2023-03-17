/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:07:56 by cfamilar          #+#    #+#             */
/*   Updated: 2023/02/23 15:16:57 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	get_percent(int start, int end, int current)
{
	double	position;
	double	distance;

	position = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (position / distance);
}

int	get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + (percent * end)));
}

int	get_color(t_coord curr, t_coord start, t_coord end, t_coord delta)
{
	int		r;
	int		g;
	int		b;
	double	perc;

	if (curr.colour == end.colour)
		return (curr.colour);
	if (delta.x > delta.y)
		perc = get_percent(start.x, end.x, curr.x);
	else
		perc = get_percent(start.y, end.y, curr.y);
	r = get_light((start.colour >> 16) & 0xFF, (end.colour >> 16) & 0xFF, perc);
	g = get_light((start.colour >> 8) & 0xFF, (end.colour >> 8) & 0xFF, perc);
	b = get_light(start.colour & 0xFF, end.colour & 0xFF, perc);
	return ((r << 16) | (g << 8) | b);
}

int	read_colour(char *str)
{
	static char	*hex_upper = "0123456789ABCDEF";
	static char	*hex_lower = "0123456789abcdef";
	int			res;
	int			i;

	if (!str)
		return (-1);
	str += 3;
	res = 0;
	while (*str)
	{
		i = 0;
		while (i < 16)
		{
			if (*str == hex_upper[i] || *str == hex_lower[i])
			{
				res = res * 16 + i;
				break ;
			}
			i++;
		}
		str++;
	}
	return (res);
}

void	height_colours(t_map *map)
{
	double	perc;
	int		row;
	int		col;

	row = -1;
	while (++row < map->depth)
	{
		col = -1;
		while (++col < map->width)
		{
			if (map->coord[row][col].colour == -1)
			{
				perc = get_percent(map->min_z,
						map->max_z, map->coord[row][col].z);
				if (perc < 0.25)
					map->coord[row][col].colour = LINE_25;
				else if (perc < 0.5)
					map->coord[row][col].colour = LINE_50;
				else if (perc < 0.75)
					map->coord[row][col].colour = LINE_75;
				else
					map->coord[row][col].colour = LINE_100;
			}
		}
	}
}
