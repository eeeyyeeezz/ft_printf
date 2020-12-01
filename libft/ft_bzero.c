/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:09:30 by gmorra            #+#    #+#             */
/*   Updated: 2020/10/31 13:35:27 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bzero(void *b, size_t len)
{
	unsigned char *tmp;

	tmp = b;
	if (len == 0)
		return ;
	while (len--)
		*tmp++ = '\0';
}
