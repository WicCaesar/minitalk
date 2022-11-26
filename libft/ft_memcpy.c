/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:43:35 by cnascime          #+#    #+#             */
/*   Updated: 2022/06/02 21:33:49 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies n bytes from src to dst. If they overlap, behaviour is undefined.
// Prefer to use memmove instead of memcpy.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*pdst;
	char	*psrc;

	pdst = (char *)dst;
	psrc = (char *)src;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (n > 0)
	{
		while (n > 0)
		{
			pdst[i] = psrc[i];
			i++;
			n--;
		}
	}
	return (pdst);
}
