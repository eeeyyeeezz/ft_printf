/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:35:05 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/02 14:50:31 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	dest = dst;
	source = (char *)src;
	if (dst == 0 && src == 0)
		return (dst);
	if (dest < source)
	{
		while (len--)
			*dest++ = *source++;
	}
	else
	{
		source += len - 1;
		dest += len - 1;
		while (len--)
			*dest-- = *source--;
	}
	return (dst);
}
