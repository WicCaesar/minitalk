/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:45:22 by cnascime          #+#    #+#             */
/*   Updated: 2022/08/20 02:40:44 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prints a number in a recursive way.
void	ft_putnbr_fd(int fd, int number)
{
	unsigned char	c;

	if (number < 0)
	{
		if (number == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		else
		{
			write(fd, "-", 1);
			number *= -1;
		}
	}
	if (number < 10)
	{
		c = number + '0';
		write(fd, &c, sizeof(c));
	}
	else
	{
		ft_putnbr_fd(fd, number / 10);
		ft_putnbr_fd(fd, number % 10);
	}
}

void	ft_putnbr_base_fd(int fd, int number, char *base)
{
	int	places;
	int	finalnumber[33];
	int	i;

	i = 0;
	places = 0;
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	while (base[places] != '\0')
		places++;
	while (number)
	{
		finalnumber[i] = number % places;
		number /= places;
		i++;
	}
	while (--i >= 0)
		ft_putchar_fd(fd, base[finalnumber[i]]);
}
