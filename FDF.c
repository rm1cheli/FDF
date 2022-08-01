/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:10:30 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/28 12:53:23 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	provirochka(char *str)
{
	int	c;
	int	i;

	i = 0;
	c = ft_strlen(str);
	if (str[--c] == 'f')
		i++;
	if (str[--c] == 'd')
		i++;
	if (str[--c] == 'f')
		i++;
	if (i != 3)
	{
		ft_putstr_fd ("the file must end in .fdf", 1);
		exit (1);
	}
}

void	deal_key1(int key, t_fdf *data)
{
	if (key == 69)
		data->keyboard->zoom += 1;
	if (key == 78)
		data->keyboard->zoom -= 1;
	if (key == 6)
		data->keyboard->z += 0.1;
	if (key == 7)
		data->keyboard->z -= 0.1;
	if (key == 47)
		data->keyboard->z_divisor += 0.1;
	if (key == 43)
		data->keyboard->z_divisor -= 0.1;
	if (data->keyboard->z_divisor < 0.1)
		data->keyboard->z_divisor = 0.1;
	else if (data->keyboard->z_divisor > 10)
		data->keyboard->z_divisor = 10;
	if (key == 49)
	{
		change (data->keyboard);
		data->keyboard->d *= -1;
	}
}

int	deal_key(int key, t_fdf *data)
{
	printf("%d\n", key);
	if (key == 126)
		data->keyboard->offset_y -= 10;
	if (key == 125)
		data->keyboard->offset_y += 10;
	if (key == 124)
		data->keyboard->offset_x += 10;
	if (key == 123)
		data->keyboard->offset_x -= 10;
	if (key == 13)
		data->keyboard->sin += 0.1;
	if (key == 0)
		data->keyboard->cos -= 0.1;
	if (key == 1)
		data->keyboard->sin -= 0.1;
	if (key == 2)
		data->keyboard->cos += 0.1;
	deal_key1(key, data);
	if (key == 53)
		exit (EXIT_SUCCESS);
	draw(data, data->img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
	{
		ft_putstr_fd("Eroor: wrong number of arguments\n", 1);
		exit(1);
	}
	data = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	data->img = (t_data *)ft_memalloc(sizeof(t_data));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");
	data->img->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->img->addr = mlx_get_data_addr(data->img->img,
			&data->img->bits_per_pixel, &data->img->line_length,
			&data->img->endian);
	data->keyboard = init_keyboard(data);
	draw(data, data->img);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	ft_free_matrix(data->matrix);
	return (0);
}
