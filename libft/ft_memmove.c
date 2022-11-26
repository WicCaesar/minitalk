/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:14:26 by cnascime          #+#    #+#             */
/*   Updated: 2022/05/27 18:41:36 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies len bytes from src to dst. They may overlap, but the copy is always
// done in a non-destructive manner. I had to typecast src to iterate its bytes,
// and to convert from void to char (same as dst). dst and pdst points the same.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;

	pdst = (char *)dst;
	psrc = (char *)src;
	if (dst == src)
		return (dst);
	if (psrc < pdst)
	{
		while (len--)
			*(pdst + len) = *(psrc + len);
		return (dst);
	}
	while (len--)
		*pdst++ = *psrc++;
	return (dst);
}
