/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:53:58 by cfamilar          #+#    #+#             */
/*   Updated: 2023/02/23 15:52:31 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_max_min_height(t_coord coord, t_map *map)
{
	if (coord.z < map->min_z)
		map->min_z = coord.z;
	if (coord.z > map->max_z)
		map->max_z = coord.z;
	return ;
}

t_coord	set_point(int x, int y, char *z)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	if (z)
		coord.z = ft_atoi(z);
	else
		coord.z = 0;
	coord.colour = read_colour(ft_strchr(z, ','));
	return (coord);
}

static t_coord	*make_row(t_map *map, char **split)
{
	t_coord	*row;
	int		i;

	if (!split)
		return (NULL);
	if (map->width == 0)
		while (split[map->width])
			map->width++;
	row = ft_calloc(sizeof(t_coord), map->width);
	if (row)
	{
		i = 0;
		while (i < map->width)
		{
			row[i] = set_point(i, map->depth, split[i]);
			set_max_min_height(row[i], map);
			i++;
		}
	}
	free_array(split);
	return (row);
}

static int	add_row(t_map *map, t_coord *row)
{
	t_coord	**temp;
	int		i;

	if (!row || row == NULL)
		return (0);
	temp = ft_calloc(sizeof(t_coord *), map->depth + 2);
	if (!temp)
		return (0);
	i = map->depth;
	temp[i] = row;
	while (i > 0)
	{
		i--;
		temp[i] = map->coord[i];
	}
	free(map->coord);
	map->coord = temp;
	map->depth++;
	return (1);
}

int	read_map(t_map *map, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (add_row(map, make_row(map, ft_split(line, ' '))) != 1)
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
	}
	close(fd);
	if (map->depth == 0 && map->width == 0)
		return (0);
	ft_putstr_fd(MAP_LOADED, 1);
	return (1);
}
