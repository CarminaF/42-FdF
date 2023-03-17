/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:15:58 by cfamilar          #+#    #+#             */
/*   Updated: 2023/02/23 16:07:13 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	*fdf;
	t_map	*map;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			error(OPEN_ERR);
		map = init_map();
		if (read_map(map, fd) != 1)
			error(MAP_READING_ERR);
		fdf = init_fdf(map);
		fdf->camera = init_cam(fdf->map);
		draw(fdf->map, fdf->camera, fdf->image, fdf);
		set_mlx_hooks(fdf);
		mlx_loop(fdf->mlx);
	}
	else
		error(USAGE_ERR);
	return (0);
}
