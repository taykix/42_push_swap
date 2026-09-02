/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsbur      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:37:09 by takaraka          #+#    #+#             */
/*   Updated: 2026/07/10 16:37:10 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;

	if (!lst)
		return ;
	if (!*lst)
		return ;
	while (*lst)
	{
		nxt = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nxt;
	}
}
