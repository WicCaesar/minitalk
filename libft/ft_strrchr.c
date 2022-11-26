/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:00:00 by cnascime          #+#    #+#             */
/*   Updated: 2022/08/24 09:33:15 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locates the last occurrence of a char in a given string. Reads the string
// backwards. The terminating NUL-character is considered part of the string;
// therefore if c == \0, the function returns the pointer to the terminating \0.
// This is not the optimal implementation, since it counts the length of the
// entire string and only then starts looking for a correspondence. It would be
// better to search for the correspondences as it scans through the string.
char	*ft_strrchr(const char *lookingfor, int character)
{
	int		length;
	char	*rewind;

	length = ft_strlen(lookingfor);
	rewind = (char *)lookingfor + length;
	while (length-- >= 0)
	{
		if (*rewind == (unsigned char)character)
			return (rewind);
		rewind--;
	}
	return (NULL);
}
