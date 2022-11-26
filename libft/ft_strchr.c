/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:23:17 by cnascime          #+#    #+#             */
/*   Updated: 2022/10/24 11:33:44 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locates the first occurrence of a char in a given string. The terminating
// NUL-character is considered to be part of the string; therefore if c == \0,
// the function returns the pointer to the terminating \0.
char	*ft_strchr(const char *lookingfor, int character)
{
	size_t	i;

	i = 0;
	if (!lookingfor)
		return (0);
	if (character == '\0')
		return ((char *)&lookingfor[ft_strlen(lookingfor)]);
	while (lookingfor[i] != '\0')
	{
		if (lookingfor[i] == (char)character)
			return ((char *)lookingfor + i);
		i++;
	}
	return (0);
}
