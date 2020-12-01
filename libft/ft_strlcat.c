/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:01:21 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/07 20:55:26 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	origa_origa_dstlen;
	size_t	origa_dstlen;
	size_t	origa_srclen;
	char	*d_dst;

	d_dst = dst;
	origa_dstlen = ft_strlen(dst);
	origa_srclen = ft_strlen(src);
	origa_origa_dstlen = ft_strlen(dst);
	i = ft_strlen(dst);
	if (dst == NULL && src == NULL)
		return (0);
	if (ft_strlen(dst) > dstsize || dstsize == 0)
		return (ft_strlen(src) + dstsize);
	while (*src && (dstsize - 1) > origa_dstlen++)
		d_dst[i++] = *src++;
	d_dst[i] = '\0';
	return (origa_srclen + origa_origa_dstlen);
}
