/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:30:17 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/28 13:08:29 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "libft2/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct s_key
{
	int			zoom;
	int			offset_x;
	int			offset_y;
	double		cos;
	double		sin;
	double		z;
	float		z_divisor;
	int			d;
}				t_key;

typedef struct z_data
{
	int				z;
	unsigned int	color;
	int				last;
}					t_and_color;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fdf
{
	int			y;
	int			x;
	t_and_color	**matrix;
	int			color;
	t_key		*keyboard;
	t_data		*img;

	void		*mlx_ptr;
	void		*win_ptr;
}			t_fdf;

typedef struct s_point
{
	int	y;
	int	x;
	int	z;
	int	color;
}		t_point;

t_and_color	ft_atoi1(const char *str);
t_fdf		*read_file(char *file_name, t_fdf *data);
int			ft_atoi_color(char *str, int f);
void		ft_free(char **str);
void		matrix_filling(char *file_name, t_fdf *data);
void		connection(t_point f, t_point s, t_data *img);
void		draw(t_fdf *data, t_data *img);
void		rr(float *x, float *y, t_fdf *data);
void		deal_key1(int key, t_fdf *data);
char		*search_end(const char *s);
char		*ft_strjoin1(char *s1, char *s2);
size_t		ft_strlen(const char *p);
char		*ft_strdup(const char *str);
char		*get_next_line(int fd);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_point		jaja(t_point vector, t_fdf *data);
t_point		new_point(int x, int y, t_fdf *data);
t_key		*init_keyboard(t_fdf *data);
void		*ft_memalloc(size_t size);
int			ft_abs(int a);
void		ft_free_matrix(t_and_color **matrix);
int			ft_min(int a, int b);
void		provirochka(char *str);
void		change(t_key *keyboard);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	40
# endif

#endif