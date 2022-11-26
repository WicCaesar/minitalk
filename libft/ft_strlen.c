/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:16:56 by cnascime          #+#    #+#             */
/*   Updated: 2022/10/24 11:31:31 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Computes the length of a string, not counting the NUL-character.
size_t	ft_strlen(const char *string)
{
	size_t	length;

	length = 0;
	if (!string)
		return (0);
	while (string[length] != '\0')
		length++;
	return (length);
}

// Calculates how many decimal places the string'll need.
int	ft_places(long number)
{
	size_t	places;

	places = 0;
	if (number <= 0)
	{
		places++;
		number *= -1;
	}
	while (number > 0)
	{
		places++;
		number /= 10;
	}
	places++;
	return (places);
}

size_t	ft_hexlen(unsigned int hex)
{
	size_t	length;

	length = 0;
	while (hex > 0)
	{
		hex /= 16;
		length++;
	}
	return (length);
}

size_t	ft_pointerlen(uintptr_t pointer)
{
	size_t		length;

	length = 2;
	if (!pointer)
	{
		ft_putstr_fd(1, PTR_ERROR);
		return (ft_strlen(PTR_ERROR));
	}
	while (pointer != 0)
	{
		pointer /= 16;
		length++;
	}
	return (length);
}
