/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:45:38 by cnascime          #+#    #+#             */
/*   Updated: 2022/05/26 20:43:17 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Finds a string inside another string, looking only for the first occurence 
// within the amount of characters in len, and, obviously, before \0.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needllen;
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	needllen = ft_strlen((char *)needle);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (i + j < len && j < needllen && haystack[i + j] == needle[j])
				j++;
			if (j == needllen)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
