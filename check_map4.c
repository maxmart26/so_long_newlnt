/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:16:41 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/22 16:21:25 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstadd_back2(t_pos **lst, t_pos *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast2(*lst)->next = new;
}

t_pos	*ft_lstlast2(t_pos *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
