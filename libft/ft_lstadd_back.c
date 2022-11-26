/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:47:26 by cnascime          #+#    #+#             */
/*   Updated: 2022/08/20 04:51:48 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newnode)
{
	t_list	*penultimate;

	if (!newnode)
		return ;
	if (!*lst)
	{
		*lst = newnode;
		return ;
	}
	penultimate = ft_lstlast(*lst);
	penultimate->next = newnode;
}
