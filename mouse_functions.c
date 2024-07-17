/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:41:16 by mthodi            #+#    #+#             */
/*   Updated: 2024/05/18 13:19:58 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_hook(void)
{
	exit (0);
	return (0);
}

void	arrow_move(t_data *img, int keycode)
{
	if (keycode == 2 || keycode == 124)
		img->x_move += 0.1 / img->zoom;
	if (keycode == 0 || keycode == 123)
		img->x_move += -0.1 / img->zoom;
	if (keycode == 13 || keycode == 126)
		img->y_move += -0.1 / img->zoom;
	if (keycode == 1 || keycode == 125)
		img->y_move += 0.1 / img->zoom;
}

int	key_control_function(int keycode, t_data *img)
{
	mlx_clear_window(img->mlx, img->mlx_window);
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_window);
		exit (0);
	}
	else if (keycode == 83)
		img->base_color = 0x461178;
	else if (keycode == 84)
		img->base_color = 0x961158;
	else if (keycode == 85)
		img->base_color = 0x001642;
	else if (keycode == 69)
		img->zoom = img->zoom * 1.1;
	else if (keycode == 78)
		img->zoom = img->zoom / 1.1;
	else if (keycode == 49)
		img->stop = 0;
	else if (keycode == 36)
		img->stop = 1;
	arrow_move(img, keycode);
	show_fractol(img);
	return (0);
}

int	mouse_control_function(int mouse_key_code, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	mlx_clear_window(img->mlx, img->mlx_window);
	if (mouse_key_code == 5)
		img->zoom *= 1.1;
	else if (mouse_key_code == 4)
		img->zoom /= 1.1;
	show_fractol(img);
	return (0);
}

int	mouse_move_julia(int x, int y, t_data *img)
{
	mlx_clear_window(img->mlx, img->mlx_window);
	if (img->stop == 0)
		img->cy = (x - img->width / 2)
			/ (0.25 * img->zoom * img->width);
	if (img->stop == 0)
		img->cx = (y - img->height / 2)
			/ (0.25 * img->zoom * img->height);
	show_fractol(img);
	return (0);
}
