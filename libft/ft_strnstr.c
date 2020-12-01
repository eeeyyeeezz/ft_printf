/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:39:21 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/03 19:39:13 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ft_strncmp(const char *s1, const char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] && s2[i + 1] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[ft_strlen(little) + i - 1] && i + ft_strlen(little) <= len)
	{
		if (ft_ft_strncmp(&big[i], little) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
