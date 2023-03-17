/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:51:43 by cfamilar          #+#    #+#             */
/*   Updated: 2023/02/23 16:06:07 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_input(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == KEY_ESC)
		close_window(fdf);
	else if (key == KEY_Q || key == KEY_W || key == KEY_A || key == KEY_S
		|| key == KEY_Z || key == KEY_X)
		rotate(key, fdf);
	else if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT
		|| key == KEY_RIGHT)
		translate(key, fdf);
	else if (key == KEY_MINUS || key == KEY_PLUS)
		zoom(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		change_projection(key, fdf);
	else if (key == KEY_K || key == KEY_L)
		change_height(key, fdf);
	return (0);
}

void	set_mlx_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_input, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
}
