/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:10:59 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/22 15:49:05 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"
#include <math.h>

static void	rotate_x(int *y, int *z, t_fdf *data)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(data->keyboard->cos) + *z * sin(data->keyboard->cos);
	*z = -previous_y * sin(data->keyboard->cos) + *z * cos(data->keyboard->cos);
}

static void	rotate_y(int *x, int *z, t_fdf *data)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(data->keyboard->sin) + *z * sin(data->keyboard->sin);
	*z = -previous_x * sin(data->keyboard->sin) + *z * cos(data->keyboard->sin);
}

static void	rotate_z(int *x, int *y, t_fdf *data)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(data->keyboard->z) - previous_y
		* sin(data->keyboard->z);
	*y = previous_x * sin(data->keyboard->z) + previous_y
		* cos(data->keyboard->z);
}

static void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_point	jaja(t_point vector, t_fdf *data)
{
	vector.x *= data->keyboard->zoom;
	vector.y *= data->keyboard->zoom;
	vector.z *= data->keyboard->zoom / data->keyboard->z_divisor;
	vector.x -= (data->x * data->keyboard->zoom) / 2;
	vector.y -= (data->y * data->keyboard->zoom) / 2;
	rotate_x(&vector.y, &vector.z, data);
	rotate_y(&vector.x, &vector.z, data);
	rotate_z(&vector.x, &vector.y, data);
	if (data->keyboard->d == 1)
		iso(&vector.x, &vector.y, vector.z);
	vector.x += 1920 / 2 + data->keyboard->offset_x;
	vector.y += (1080 + data->y * data->keyboard->zoom) / 2
		+ data->keyboard->offset_y;
	return (vector);
}
