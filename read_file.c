/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:36:10 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/28 12:35:03 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	ft_free(char **str)
{
	int	y;

	y = 0;
	while (str[y])
		free(str[y++]);
	free(str);
}

int	wdcounter(int fd, int width)
{
	char	**str2;
	char	*str;
	int		f;

	f = 0;
	str = get_next_line(fd);
	str2 = ft_split(str, ' ');
	while (str2[width])
		width++;
	while (str != 0)
	{
		free(str);
		str = get_next_line(fd);
	}
	ft_free(str2);
	free(str);
	return (width);
}

int	height_file(char *file_name)
{
	int		fd;
	char	*str;
	int		height;

	height = 0;
	fd = open(file_name, O_RDONLY);
	if (!fd)
		ft_error("Error2: ");
	str = malloc(sizeof(char));
	if (!str)
		ft_error("Error3: ");
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		height++;
	}
	close(fd);
	free(str);
	return (height - 1);
}

int	width_file(char *file_name)
{
	int		fd;
	int		width;

	width = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("Error4: ");
	width = wdcounter(fd, width);
	close(fd);
	return (width);
}

t_fdf	*read_file(char *file_name, t_fdf *data)
{
	data->y = height_file(file_name);
	data->x = width_file(file_name);
	matrix_filling(file_name, data);
	provirochka(file_name);
	return (data);
}
