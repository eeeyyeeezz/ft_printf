/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:24:11 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/02 14:17:40 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (n--)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			*((unsigned char *)dst) = ((unsigned char *)src)[i];
			dst++;
			return (dst);
		}
		else
		{
			*((unsigned char *)dst) = ((unsigned char *)src)[i++];
			dst++;
		}
	}
	return (NULL);
}
