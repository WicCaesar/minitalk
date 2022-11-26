/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:08:09 by cnascime          #+#    #+#             */
/*   Updated: 2022/08/26 18:39:21 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(int fd, char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd(1, STR_ERROR);
		return (ft_strlen(STR_ERROR));
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], sizeof(char));
		i++;
	}
	return (ft_strlen(s));
}
