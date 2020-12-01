/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:04:58 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/07 15:18:25 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *))
{
	t_list	*list_new;
	t_list	*elem;

	if (lst == NULL)
		return (NULL);
	if (!(list_new = ft_lstnew(f(lst->content))))
		ft_lstclear(&lst, del);
	elem = list_new;
	lst = lst->next;
	while (lst)
	{
		if (!(list_new->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst, del);
			break ;
		}
		lst = lst->next;
		list_new = list_new->next;
	}
	return (elem);
}
