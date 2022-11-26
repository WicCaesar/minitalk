/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:57:43 by cnascime          #+#    #+#             */
/*   Updated: 2022/05/27 18:48:24 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a pointer to a duplicate of a given string.
char	*ft_strdup(const char *s1)
{
	char	*ditto;
	int		length;

	length = ft_strlen(s1) + 1;
	ditto = malloc(sizeof(*ditto) * length);
	if (ditto == NULL)
		return (NULL);
	ditto = ft_memmove(ditto, s1, length);
	return (ditto);
}
