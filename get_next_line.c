/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:17 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 16:48:09 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

char	*st_string_go(char *st_string)
{
	int		i;
	int		b;
	char	*new_st_string;

	i = 0;
	while (st_string[i] && st_string[i] != '\n')
		i++;
	if (st_string[i] == '\0')
	{
		free (st_string);
		return (0);
	}
	new_st_string = malloc(sizeof(char) * (ft_strlen(st_string) - i + 1));
	if (!new_st_string)
		ft_error("Error: ");
	b = 0;
	i++;
	while (st_string[i])
		new_st_string[b++] = st_string[i++];
	new_st_string[b] = '\0';
	free(st_string);
	return (new_st_string);
}

char	*vivod(char *st_string)
{
	int		i;
	char	*string2;

	i = 0;
	if (st_string[i] == '\0')
		return (0);
	while (st_string[i] && st_string[i] != '\n')
		i++;
	string2 = malloc(sizeof(char) * (i + 2));
	if (!string2)
		ft_error("Error: ");
	i = 0;
	while (st_string[i] && st_string[i] != '\n')
	{
		string2[i] = st_string[i];
		i++;
	}
	if (st_string[i] == '\n')
	{
		string2[i] = st_string[i];
		i++;
	}
	string2[i] = '\0';
	return (string2);
}

static char	*sos(int fd, char *string)
{
	char	*buf;
	int		c;

	c = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		ft_error("Error: ");
	while (!search_end(string) && c != 0)
	{
		c = read(fd, buf, BUFFER_SIZE);
		if (c == -1)
		{
			free(buf);
			perror("Error");
			exit (EXIT_SUCCESS);
		}
		buf[c] = '\0';
		string = ft_strjoin1(string, buf);
	}
	free(buf);
	return (string);
}

char	*get_next_line(int fd)
{
	static char		*st_string;
	char			*string2;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	st_string = sos(fd, st_string);
	if (!st_string)
		return (0);
	string2 = vivod(st_string);
	st_string = st_string_go (st_string);
	return (string2);
}
