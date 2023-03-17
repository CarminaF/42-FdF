/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:42:45 by cfamilar          #+#    #+#             */
/*   Updated: 2023/02/23 15:24:39 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int	close_window(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->image->image);
	mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf->camera);
	free_array((char **)fdf->map->coord);
	free(fdf->map);
	free(fdf->image);
	free(fdf);
	exit(0);
}
