/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:38:42 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/08 15:45:21 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		s_start;
	char		*sub;

	i = 0;
	s_start = start;
	sub = malloc(len + 1);
	if (sub == NULL || s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub[i] = '\0';
		return (sub);
	}
	while (len-- && s[start])
		sub[i++] = s[s_start++];
	sub[i] = '\0';
	return (sub);
}
