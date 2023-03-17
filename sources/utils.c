/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:04:59 by cfamilar          #+#    #+#             */
/*   Updated: 2023/02/23 16:02:32 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	change_height(int key, t_fdf *fdf)
{
	if (key == KEY_K)
		fdf->camera->z_divisor -= 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	if (key == KEY_L)
		fdf->camera->z_divisor += 0.1;
	if (fdf->camera->z_divisor > 10)
		fdf->camera->z_divisor = 10;
	draw(fdf->map, fdf->camera, fdf->image, fdf);
}

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size);
	if (ptr)
		ft_bzero(ptr, size);
	return (ptr);
}
