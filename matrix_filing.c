/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_filing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:10:47 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/28 12:46:23 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

t_and_color	*ft_atoi_plus_ultra(char **str, t_fdf *data)
{
	t_and_color	*zap;
	int			i;

	zap = (t_and_color *)malloc(sizeof(t_and_color) * data->x);
	if (!zap)
		ft_error("Error: ");
	i = 0;
	while (i < data->x)
	{
		if (str[i] == NULL)
		{
			free (zap);
			return (0);
		}
		zap[i] = ft_atoi1(str[i]);
		zap[i].last = 1;
		i++;
	}
	zap[i].last = 0;
	return (zap);
}

void	filling(t_fdf *data, char *str, int fd)
{
	int		i;
	char	**str2;

	i = 0;
	while (i < data->y)
	{
		str = get_next_line(fd);
		str2 = ft_split(str, ' ');
		data->matrix[i] = ft_atoi_plus_ultra(str2, data);
		if (!data->matrix[i])
		{
			ft_free (str2);
			free (str);
			ft_putstr_fd ("Error: this is not an isometric projection", 1);
			close (fd);
			exit (EXIT_SUCCESS);
		}
		free(str);
		ft_free (str2);
		i++;
	}
}

void	matrix_filling(char *file_name, t_fdf *data)
{
	int		fd;
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		ft_error("Error: ");
	data->matrix = (t_and_color **)malloc(sizeof(t_and_color **) * data->y);
	fd = open(file_name, O_RDONLY);
	if (!fd)
	{
		perror ("Error :");
		free (data->matrix);
		close (fd);
		exit (EXIT_SUCCESS);
	}
	filling(data, str, fd);
	free(str);
	close (fd);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}
