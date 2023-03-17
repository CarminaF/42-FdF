/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:30:29 by cfamilar          #+#    #+#             */
/*   Updated: 2023/02/23 15:54:19 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 180, y += 465, TEXT_COLOUR, "FDF");
	mlx_string_put(mlx, win, 30, y += 50, TEXT_COLOUR,
		"Move:                Arrow Keys");
	mlx_string_put(mlx, win, 30, y += 20, TEXT_COLOUR,
		"Zoom:                + / -");
	mlx_string_put(mlx, win, 30, y += 20, TEXT_COLOUR,
		"Rotate X:            Q / W");
	mlx_string_put(mlx, win, 30, y += 20, TEXT_COLOUR,
		"Rotate Y:            A / S");
	mlx_string_put(mlx, win, 30, y += 20, TEXT_COLOUR,
		"Rotate Z:            Z / X");
	mlx_string_put(mlx, win, 30, y += 20, TEXT_COLOUR,
		"Change Height:       K / L");
	mlx_string_put(mlx, win, 30, y += 20, TEXT_COLOUR,
		"Change Projection:   I - Isometric");
	mlx_string_put(mlx, win, 240, y += 20, TEXT_COLOUR,
		"P - Parallel");
}
