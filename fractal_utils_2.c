/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:42:05 by mthodi            #+#    #+#             */
/*   Updated: 2024/05/18 13:29:10 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

double	get_x0(t_data *img, int w)
{
	double	result;

	result = (w - img->width / 2)
		/ (0.25 * img->zoom * img->width) + img->x_move;
	return (result);
}

double	get_y0(t_data *img, int h)
{
	double	result;

	result = (h - img->height / 2)
		/ (0.25 * img->zoom * img->height) + img->y_move;
	return (result);
}
