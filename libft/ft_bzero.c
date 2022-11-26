/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:35:36 by cnascime          #+#    #+#             */
/*   Updated: 2022/05/21 21:39:58 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Erases data (by writing zeros) in n bytes of memory starting at s.
// Deprecated in favour of memset.
void	ft_bzero(void *s, size_t n)
{
	ft_memset((void *)s, 0, (size_t)n);
}
