/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 07:53:03 by cnascime          #+#    #+#             */
/*   Updated: 2022/06/09 19:05:06 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_isforbidden(char character, char *forbidden);

// Allocates and returns a copy of s1 with the characters specified in set
// removed from the beginning and the end of the string.
char	*ft_strtrim(char const *s1, char const *set)
{
	int		length;
	int		trimfw;
	int		trimbw;
	char	*trimmed;

	if (!s1)
		return (NULL);
	length = ft_strlen(s1);
	trimbw = 0;
	while ((length - trimbw - 1) >= 0
		&& ft_isforbidden(s1[length - trimbw - 1], (char *)set))
		trimbw++;
	trimfw = 0;
	while (s1[trimfw] != '\0' && ft_isforbidden(s1[trimfw], (char *)set))
		trimfw++;
	trimmed = ft_substr(s1, trimfw, length - trimfw - trimbw);
	return (trimmed);
}

// Checks whether the character in question is in the forbidden list.
// 1-true if it's forbidden, 2-false if it's allowed.
static int	ft_isforbidden(char character, char *forbidden)
{
	int	i;

	i = 0;
	while (forbidden[i] != '\0')
	{
		if (character == forbidden[i])
			return (1);
		i++;
	}
	if (character == '\0')
		return (1);
	return (0);
}
