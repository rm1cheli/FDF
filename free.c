/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:10:33 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/06 12:23:15 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	ft_free_matrix(t_and_color **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free (matrix[i++]);
	free (matrix);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	change(t_key *keyboard)
{
	keyboard->cos = 0;
	keyboard->sin = 0;
	keyboard->z = 0;
}
