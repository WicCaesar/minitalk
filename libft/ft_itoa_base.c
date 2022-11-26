/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:43:42 by cnascime          #+#    #+#             */
/*   Updated: 2022/08/24 18:58:44 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int base);
char	*result(int places, int index, int *convert);

// Simply counts the amount of decimal places there'll be in the final integer.
// Also checks if it's a negative and saves a space for the minus operator.
char	*ft_itoa_base(int n, int base)
{
	long	number;
	int		operator;
	int		convert[65];
	int		i;

	number = n;
	if (number == 0)
		return ("0");
	operator = 0;
	if (number < 0)
	{
		number *= -1;
		if (base == 10)
			operator = 1;
	}
	i = 0;
	while (number != 0)
	{
		convert[i++] = number % base + '0';
		number /= base;
	}
	return (result(i, operator, convert));
}

char	*result(int places, int index, int *convert)
{
	char	*base;
	char	*converted;

	base = "0123456789abcdef";
	converted = (char *)malloc(places * sizeof(converted));
	if (!converted)
		return (NULL);
	places --;
	if (index == 1)
		converted[0] = '-';
	while (places >= 0)
	{
		converted[index] = base[convert[places]];
		index++;
		places--;
	}
	converted[index] = '\0';
	return (converted);
}
