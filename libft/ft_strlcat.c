/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:37:56 by cnascime          #+#    #+#             */
/*   Updated: 2022/06/10 16:37:31 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adds source string to the end of destination, guaranteeing space for 
// NUL-termination within dstsize. Returns the initial length of dst + src.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclength;
	size_t	dstlength;
	size_t	i;

	srclength = ft_strlen(src);
	if (dstsize == 0)
		return (srclength);
	dstlength = ft_strlen(dst);
	if (dstsize <= dstlength)
		srclength += dstsize;
	else
		srclength += dstlength;
	i = 0;
	while (src[i] != '\0' && dstlength < dstsize - 1)
	{
		dst[dstlength] = src[i];
		dstlength++;
		i++;
	}
	if (dstlength < dstsize)
		dst[dstlength] = '\0';
	return (srclength);
}
