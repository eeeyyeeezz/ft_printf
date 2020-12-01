/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:48:20 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/04 14:43:05 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		a;
	char	*new_string;

	a = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	new_string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_string == NULL)
		return (NULL);
	while (s1[a])
		new_string[i++] = s1[a++];
	a = 0;
	while (s2[a])
		new_string[i++] = s2[a++];
	new_string[i] = '\0';
	return (new_string);
}
