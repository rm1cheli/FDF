/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   сonnection_points.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:36:17 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/25 14:59:51 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"
#include <math.h>

t_point	step(t_point *f, t_point*s)
{
	t_point	sign;

	if (f->x < s->x)
		sign.x = 1;
	else
		sign.x = -1;
	if (f->y < s->y)
		sign.y = 1;
	else
		sign.y = -1;
	return (sign);
}

static void	draw_background(t_data *fdf)
{
	int	*image;

	ft_bzero(fdf->addr, 1920 * 1080 * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->addr);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	connection(t_point f, t_point s, t_data *img)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = ft_abs(s.x - f.x);
	delta.y = ft_abs(s.y - f.y);
	sign = step(&f, &s);
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		else if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

void	draw(t_fdf *data, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	draw_background(img);
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			if (x != data->x - 1)
			{
				connection(jaja(new_point(x, y, data), data),
					jaja(new_point(x + 1, y, data), data), img);
			}
			if (y != data->y - 1)
				connection(jaja(new_point(x, y, data), data),
					jaja(new_point(x, y + 1, data), data), img);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img, 0, 0);
}
