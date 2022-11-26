/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:55:14 by cnascime          #+#    #+#             */
/*   Updated: 2022/06/17 17:53:30 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocate memory for count objects that are size bytes of memory each.
// Returns a pointer to the allocated memory, which is filled with bytes of 0.
// Checks if count or size equals 0, replaces with 1 to aid in multiplication.
void	*ft_calloc(size_t count, size_t size)
{
	void	*mallocation;

	if (count == 0)
		count = 1;
	if (size == 0)
		size = 1;
	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	mallocation = malloc(count * size);
	if (!mallocation)
		return (NULL);
	ft_bzero(mallocation, count * size);
	return (mallocation);
}
