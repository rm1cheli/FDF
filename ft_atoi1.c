/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:10:36 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/27 17:42:45 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

t_point	new_point(int x, int y, t_fdf *data)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = data->matrix[y][x].z;
	point.color = data->matrix[y][x].color;
	return (point);
}

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_error("Error: ");
		exit (1);
	}
	ft_bzero(ptr, size);
	return (ptr);
}

t_and_color	ft_atoi1(const char *str)
{
	long long		c;
	long long		f;
	unsigned int	m;
	t_and_color		el_matrix;

	f = 0;
	c = 1;
	m = 0;
	while (str[f] == '\t' || str[f] == '\n' || str[f] == '\v'
		|| str[f] == '\f' || str[f] == '\r' || str[f] == ' ')
		f++;
	if (str[f] == '+' || str[f] == '-')
		if (str[f++] == '-')
			c *= -1;
	while ((str[f] >= '0') && (str[f] <= '9'))
		m = (m * 10) + (str[f++] - '0');
	el_matrix.color = ft_atoi_color((char *)str, f);
	c *= m;
	el_matrix.z = c;
	if (c >= 2147483648)
		el_matrix.z = -1;
	if (c <= -2147483649)
		el_matrix.z = 0;
	return (el_matrix);
}

int	ft_atoi_color(char *str, int f)
{
	int				i;
	unsigned int	m;

	m = 0;
	i = 0;
	if (str[f++] != ',')
		return (0xffffff);
	if (str[f++] != '0')
		return (0xffffff);
	if (str[f++] != 'x')
		return (0xffffff);
	while (((str[f] >= 'A' && str[f] <= 'F')
			|| (str[f] >= '0' && str[f] <= '9')))
		m = (m * 10) + (str[f++] - '0');
	return (m);
}

t_key	*init_keyboard(t_fdf *fdf)
{
	t_key	*keyboard;

	keyboard = (t_key *)ft_memalloc(sizeof(t_key));
	if (!keyboard)
		exit (1);
	keyboard->zoom = ft_min((1920 / fdf->x / 2), (1080 / fdf->y / 2));
	keyboard->cos = 0;
	keyboard->sin = 0;
	keyboard->z = 0;
	keyboard->z_divisor = 6;
	keyboard->offset_x = 0;
	keyboard->offset_y = 0;
	keyboard->d = 1;
	return (keyboard);
}
