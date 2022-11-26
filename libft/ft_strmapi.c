/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:12:17 by cnascime          #+#    #+#             */
/*   Updated: 2022/06/09 18:29:27 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Passes the address of every character of a string to a function.
// Doesn't alter the source string, allocates memory for a new string.
// Returns the string created from the successive applications of ’f’.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*postfunction;

	if (!s || !f)
		return (NULL);
	postfunction = ft_calloc(ft_strlen(s) + 1, 1);
	if (postfunction == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		postfunction[i] = f(i, s[i]);
		i++;
	}
	return (postfunction);
}
