/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:27:08 by rmicheli          #+#    #+#             */
/*   Updated: 2021/10/29 18:59:21 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*y;
	int		u;

	u = ft_strlen((char *)str);
	y = malloc(sizeof(*y) * (u + 1));
	if (!y)
		return (0);
	while (u >= 0)
	{
		y[u] = str[u];
		u--;
	}
	return (y);
}
