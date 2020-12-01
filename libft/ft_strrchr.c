/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:32:57 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/04 14:13:21 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*tmp;
	size_t		i;

	i = 0;
	tmp = NULL;
	while (i < ft_strlen(str) + 1)
	{
		if (str[i] == c)
			tmp = &str[i];
		i++;
	}
	return ((char *)tmp);
}
