/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:07 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 16:48:05 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

size_t	ft_strlen(const char *p)
{
	int	b;

	b = 0;
	if (!p)
		return (0);
	while (p[b])
		b++;
	return (b);
}

char	*search_end(const char *s)
{
	size_t	g;

	g = 0;
	if (!s)
		return (0);
	while (s[g] != '\n')
	{
		if (!s[g])
			return (0);
		++g;
	}
	return ((char *)&s[g]);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	int		y;
	int		m;
	char	*t;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			ft_error("Error: ");
		s1[0] = '\0';
	}
	t = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!t)
		ft_error("Error: ");
	m = 0;
	y = 0;
	while (s1[m])
		t[y++] = s1[m++];
	m = 0;
	while (s2[m])
		t[y++] = s2[m++];
	t[y] = '\0';
	free(s1);
	return (t);
}
